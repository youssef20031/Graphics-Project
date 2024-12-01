#include "../CommonH/Player.h"
#include "../CommonH/Camera.h"
#include "../CommonH/Collisions.h"
#include <algorithm>



Vector3f spawnPoint(3.07, 0.2, 3.5);
//Vector3f spawnPoint(-138.84, 4.2, 45.34);
//Vector3f spawnPoint(-192.00, 5.3, 56.19);
//Vector3f spawnPoint(-138.84, 4.2, 45.34);

int whichCp = 0;
bool showCheckpointMessage = false;
float checkpointMessageStartTime = 0.0f;

GLfloat playerX = spawnPoint.x;
GLfloat playerY = spawnPoint.y;
GLfloat playerZ = spawnPoint.z;
GLfloat playerHeight = 0.6f;
GLfloat playerWidth = 0.2f;
GLfloat playerMovementSpeed = 5.0f;
 

Model_3DS wolfplayermodel;

// Player spawn point for level 1: (3.07,0.2,3.5)
// Stage 1: (-21.5,0.1,48.25)
// Stage 2: (-71.59,0.2,48.18)
// Stage 3: (-138.84,4.2,45.34)
// Win Platform: (-231.6,12.56,58.2)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// player rotating animation
GLfloat playerDirectionRotationFacing = 270.0f; // direction player facing  (270 for starting the game, 180 for stage 2 and 3)
GLfloat playerDirectionRotationFacingVertical = 0.0f; // direction player is facing up and down
GLfloat playerDirectionRotationFacingVerticalMin = -30.0f;
GLfloat playerDirectionRotationFacingVerticalMax = 30.0f; 
GLfloat playerDirectionRotationBody = 0.0f; // direction player facing
GLfloat playerRotationAnimationSpeed = 1.0f;
GLfloat playerRotationSpeed = 0.25f;
bool rotatingLeft = false;
bool rotatingRight = false;
bool rotatingForward = false;
bool rotatingBack = false;

// player jump stuff
bool isPlayerJumping = false;
GLfloat playerVerticalSpeed = 0.0f;
GLfloat playerVerticalJumpInitialSpeed = 0.03f;
GLfloat fallAcceleration = -0.05f; // e3tebro gravity

void updateCheckpoint() {
	if ((playerX>=-27.24&&playerX<=-26.54&&playerZ>=45.15&&playerZ<=51.03)&&whichCp==0) {
		spawnPoint.x = -21.5;
		spawnPoint.y = 0.1+0.2;
		spawnPoint.z = 48.25;
		whichCp = 1;
		showCheckpointMessage = true;
		checkpointMessageStartTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
		
		
	}

	if ((playerX >= -74.37 && playerX <= -74.1 && playerZ >= 42.53 && playerZ <= 52.81) && whichCp == 1) {
		spawnPoint.x = -71.59;
		spawnPoint.y = 0.2+0.2;
		spawnPoint.z = 48.18;
		whichCp = 2;
		showCheckpointMessage = true;
		checkpointMessageStartTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;

		
		

	}

	if ((playerX >= -139.43 && playerX <= -139.32 && playerZ >= 43.0 && playerZ <= 47.0) && whichCp == 2) {
		spawnPoint.x = -138.84;
		spawnPoint.y = 4.2 + 0.2;
		spawnPoint.z = 45.34;
		whichCp = 3;
		showCheckpointMessage = true;
		checkpointMessageStartTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;



	}

	


}

void updateWinLevel1() {
	if (playerX>=-235.38&&playerX<=-235.15&&playerZ>=55.28&&playerZ<=59.28) {

		gameStatus = WIN;
	}
}

void updatePlayerRotation() {
	// 8 cases
	if (rotatingForward && rotatingRight) {
		// check if difference between current rotation and the desired is more than 180, if so then add or remove a 360)
		if (playerDirectionRotationBody - playerDirectionRotationFacing - -45.0f >= 180.0f) {
			playerDirectionRotationBody -= 360.0f;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing - -45.0f <= -180.0f) {
			playerDirectionRotationBody += 360.0f;
		}

		// forward right
		if (playerDirectionRotationBody - playerDirectionRotationFacing > -46.0f) {
			playerDirectionRotationBody -= playerRotationAnimationSpeed;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing < -44.0f) {
			playerDirectionRotationBody += playerRotationAnimationSpeed;
		}
	}
	else if (rotatingForward && rotatingLeft) {
		// check if difference between current rotation and the desired is more than 180, if so then add or remove a 360)
		if (playerDirectionRotationBody - playerDirectionRotationFacing - 45.0f >= 180.0f) {
			playerDirectionRotationBody -= 360.0f;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing - 45.0f <= -180.0f) {
			playerDirectionRotationBody += 360.0f;
		}

		// forward left
		if (playerDirectionRotationBody - playerDirectionRotationFacing > 46.0f) {
			playerDirectionRotationBody -= playerRotationAnimationSpeed;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing < 44.0f) {
			playerDirectionRotationBody += playerRotationAnimationSpeed;
		}
	}
	else if (rotatingBack && rotatingRight) {
		// check if difference between current rotation and the desired is more than 180, if so then add or remove a 360)
		if (playerDirectionRotationBody - playerDirectionRotationFacing - -135.0f >= 180.0f) {
			playerDirectionRotationBody -= 360.0f;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing - -135.0f <= -180.0f) {
			playerDirectionRotationBody += 360.0f;
		}

		// back right
		if (playerDirectionRotationBody - playerDirectionRotationFacing > -136.0f) {
			playerDirectionRotationBody -= playerRotationAnimationSpeed;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing < -134.0f) {
			playerDirectionRotationBody += playerRotationAnimationSpeed;
		}
	}
	else if (rotatingBack && rotatingLeft) {
		// check if difference between current rotation and the desired is more than 180, if so then add or remove a 360)
		if (playerDirectionRotationBody - playerDirectionRotationFacing - 135.0f >= 180.0f) {
			playerDirectionRotationBody -= 360.0f;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing - 135.0f <= -180.0f) {
			playerDirectionRotationBody += 360.0f;
		}

		// back left
		if (playerDirectionRotationBody - playerDirectionRotationFacing > 136.0f) {
			playerDirectionRotationBody -= playerRotationAnimationSpeed;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing < 134.0f) {
			playerDirectionRotationBody += playerRotationAnimationSpeed;
		}
	}
	else if (rotatingForward) {
		// check if difference between current rotation and the desired is more than 180, if so then add or remove a 360)
		if (playerDirectionRotationBody - playerDirectionRotationFacing - 0.0f >= 180.0f) {
			playerDirectionRotationBody -= 360.0f;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing - 0.0f <= -180.0f) {
			playerDirectionRotationBody += 360.0f;
		}

		// forward
		if (playerDirectionRotationBody - playerDirectionRotationFacing > 1.0f) {
			playerDirectionRotationBody -= playerRotationAnimationSpeed;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing < -1.0f) {
			playerDirectionRotationBody += playerRotationAnimationSpeed;
		}
	}
	else if (rotatingBack) {
		// check if difference between current rotation and the desired is more than 180, if so then add or remove a 360)
		if (playerDirectionRotationBody - playerDirectionRotationFacing - 180.0f >= 180.0f) {
			playerDirectionRotationBody -= 360.0f;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing - 180.0f <= -180.0f) {
			playerDirectionRotationBody += 360.0f;
		}

		// back
		if (playerDirectionRotationBody - playerDirectionRotationFacing > 181.0f) {
			playerDirectionRotationBody -= playerRotationAnimationSpeed;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing < 179.0f) {
			playerDirectionRotationBody += playerRotationAnimationSpeed;
		}
	}
	else
		if (rotatingRight) {
			//check if difference between current rotation and the desired is more than 180, if so then add or remove a 360)
			if (playerDirectionRotationBody - playerDirectionRotationFacing - -90.0f >= 180.0f) {
				playerDirectionRotationBody -= 360.0f;
			}
			else if (playerDirectionRotationBody - playerDirectionRotationFacing - -90.0f <= -180.0f) {
				playerDirectionRotationBody += 360.0f;
			}

			//right
			if (playerDirectionRotationBody - playerDirectionRotationFacing > -89.0f) {
				playerDirectionRotationBody -= playerRotationAnimationSpeed;
			}
			else if (playerDirectionRotationBody - playerDirectionRotationFacing < -91.0f) {
				playerDirectionRotationBody += playerRotationAnimationSpeed;
			}
		}
		else if (rotatingLeft) {
			//check if difference between current rotation and the desired is more than 180, if so then add or remove a 360)
			if (playerDirectionRotationBody - playerDirectionRotationFacing - 90.0f >= 180.0f) {
				playerDirectionRotationBody -= 360.0f;
			}
			else if (playerDirectionRotationBody - playerDirectionRotationFacing - 90.0f <= -180.0f) {
				playerDirectionRotationBody += 360.0f;
			}

			//left
			if (playerDirectionRotationBody - playerDirectionRotationFacing > 91.0f) {
				playerDirectionRotationBody -= playerRotationAnimationSpeed;
			}
			else if (playerDirectionRotationBody - playerDirectionRotationFacing < 89.0f) {
				playerDirectionRotationBody += playerRotationAnimationSpeed;
			}
		}

	// start rotating back to the direction the face is facing if he stopped moving in a certain direction
	if (!rotatingBack && !rotatingLeft && !rotatingRight) {
		if (playerDirectionRotationBody - playerDirectionRotationFacing >= 180.0f) {
			playerDirectionRotationBody -= 360.0f;
		}
		else if (playerDirectionRotationBody - playerDirectionRotationFacing <= -180.0f) {
			playerDirectionRotationBody += 360.0f;
		}

		if (playerDirectionRotationBody > playerDirectionRotationFacing + 1.0f) {
			playerDirectionRotationBody -= playerRotationAnimationSpeed;
		}
		else if (playerDirectionRotationBody < playerDirectionRotationFacing - 1.0f) {
			playerDirectionRotationBody += playerRotationAnimationSpeed;
		}

	}
}

void movePlayer(GLfloat speedSign = 1.0f, GLfloat angleSign = 1.0f, GLfloat sinCosAngleShift = 0.0f) {
	// calculate the new x and z positions
	GLfloat speedX = playerMovementSpeed * speedSign * deltaTime * cos(angleSign * playerDirectionRotationFacing * M_PI / 180.0f - sinCosAngleShift);
	GLfloat speedZ = playerMovementSpeed * speedSign * deltaTime * sin(angleSign * playerDirectionRotationFacing * M_PI / 180.0f + sinCosAngleShift);

	
	// normalizing the vector 3ashan to prevent speed boost while moving diagonally
	GLfloat magnitude = sqrt(speedX * speedX + speedZ * speedZ);

	if (magnitude > 0.0f && magnitude > playerMovementSpeed) {
		speedX = speedX / magnitude * playerMovementSpeed;
		speedZ = speedZ / magnitude * playerMovementSpeed;
	}

	if (!isColliding(speedX, 0, 0)) {
		playerX += speedX;
	}
	if (!isColliding(0, 0, speedZ)) {
		playerZ += speedZ;
	}
}


void updatePlayerMovement() {

	bool moving = keyStates['w'] || keyStates['s'] || keyStates['d'] || keyStates['a'] || specialKeyStates[GLUT_KEY_LEFT] || specialKeyStates[GLUT_KEY_RIGHT] || specialKeyStates[GLUT_KEY_UP] || specialKeyStates[GLUT_KEY_DOWN];
	if (keyStates['w']) {
		movePlayer(1.0f, -1.0); // calculate the new x and z positions
	}
	if (keyStates['s']) {
		movePlayer(-1.0f, -1.0); // calculate the new x and z positions
	}
	if (keyStates['d']) {
		movePlayer(1.0f, 1.0f, M_PI / 2); // calculate the new x and z positions
	}
	if (keyStates['a']) {
		movePlayer(-1.0f, 1.0f, M_PI / 2); // calculate the new x and z positions
	}

	if (specialKeyStates[GLUT_KEY_LEFT]) {
		playerDirectionRotationFacing += playerRotationSpeed;
	}
	if (specialKeyStates[GLUT_KEY_RIGHT]) {
		playerDirectionRotationFacing -= playerRotationSpeed;
	}
	if (specialKeyStates[GLUT_KEY_UP] && playerDirectionRotationFacingVertical <= playerDirectionRotationFacingVerticalMax) {
		playerDirectionRotationFacingVertical += playerRotationSpeed;
	}
	if (specialKeyStates[GLUT_KEY_DOWN] && playerDirectionRotationFacingVertical >= playerDirectionRotationFacingVerticalMin) {
		playerDirectionRotationFacingVertical -= playerRotationSpeed;
	}

	// player direction rotation
	rotatingForward = keyStates['w'];
	rotatingBack = keyStates['s'];
	rotatingLeft = keyStates['a'];
	rotatingRight = keyStates['d'];

	if (moving) {
		// update camera as well
		if (viewMode == FIRST_PERSON) {
			setFirstPersonCamera();
		}
		if (viewMode == THIRD_PERSON) {
			setThirdPersonCamera();
		}
	}
}

void updatePlayerVerticalMovement() {
	bool moving = updateFalling();
	// jump if not already falling
	if (!isPlayerJumping && keyStates[' ']) {
		isPlayerJumping = true;
		playerVerticalSpeed = playerVerticalJumpInitialSpeed;
	}
	if (moving) {
		// update camera as well
		if (viewMode == FIRST_PERSON) {
			setFirstPersonCamera();
		}
		if (viewMode == THIRD_PERSON) {
			setThirdPersonCamera();
		}
	}
}
// returns true if player is falling
bool updateFalling() {
	// calculate new falling speed
	playerVerticalSpeed += fallAcceleration * deltaTime;
	
	// check if player is falling in void


	if (playerY <= -20.0f) {
		// return to spawnpoint maslan
		playerX = spawnPoint.x;
		playerY = spawnPoint.y;
		playerZ = spawnPoint.z;
		playerVerticalSpeed = 0;
	}
	
	// check if there's something under (collision)
	if (isColliding(0, playerVerticalSpeed, 0)) {
		playerVerticalSpeed = 0.0f; // set vertical speed to rest
		return false;
	}
	else {
		// move player downwards
		playerY += playerVerticalSpeed;
		return true;
	}
}

void drawCuboid(double xStart, double xEnd, double yStart, double yEnd, double zStart, double zEnd) {
	glPushMatrix();

	double centerX = (xStart + xEnd) / 2.0;
	double centerY = (yStart + yEnd) / 2.0;
	double centerZ = (zStart + zEnd) / 2.0;

	double scaleX = fabs(xEnd - xStart);
	double scaleY = fabs(yEnd - yStart);
	double scaleZ = fabs(zEnd - zStart);

	glTranslated(centerX, centerY, centerZ);

	glScaled(scaleX, scaleY, scaleZ);

	glutSolidCube(1);

	glPopMatrix();
}


void drawPlayer() {
	glPushMatrix();

	glTranslatef(playerX, playerY, playerZ);

	glRotatef(playerDirectionRotationBody, 0.0f, 1.0f, 0.0f);

	glScalef(wolfplayermodel.scale, wolfplayermodel.scale, wolfplayermodel.scale);
	

	
	 glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

	wolfplayermodel.Draw();

	glPopMatrix();
}


