#include "../CommonH/Player.h"
#include "../CommonH/Camera.h"

GLfloat playerX = 0.0f;
GLfloat playerY = 0.2f;
GLfloat playerZ = 0.0f;
GLfloat playerHeight = 0.6f;
GLfloat playerWidth = 0.2f;
GLfloat playerMovementSpeed = 0.005f;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// player rotating animation
GLfloat playerDirectionRotationFacing = 0.0f; // direction player facing
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
GLfloat playerVerticalJumpInitialSpeed = 0.012f;
GLfloat fallAcceleration = -0.00008f; // e3tebro gravity


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
	GLfloat speedX = playerMovementSpeed * speedSign * cos(angleSign * playerDirectionRotationFacing * M_PI / 180.0f - sinCosAngleShift);
	GLfloat speedZ = playerMovementSpeed * speedSign * sin(angleSign * playerDirectionRotationFacing * M_PI / 180.0f + sinCosAngleShift);
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
	playerVerticalSpeed += fallAcceleration;
	
	// check if player is falling in void
	if (playerY <= -20.0f) {
		// return to spawnpoint maslan
		playerX = 0.0f;
		playerY = 0.11f;
		playerZ = 0.0f;
		playerVerticalSpeed = 0;
	}
	
	// check if there's something under (collision)
	if (isColliding(0, playerVerticalSpeed, 0)) {
		playerVerticalSpeed = 0.0f; // set vertical speed to rest
		isPlayerJumping = false;
		return false;
	}
	else {
		// move player downwards
		playerY += playerVerticalSpeed;
		return true;
	}
}
// checks if player's new center coords overlaps some obstacle's start and end coords
bool checkCollision(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2Start, GLfloat x2End, GLfloat y2Start, GLfloat y2End, GLfloat z2Start, GLfloat z2End) {
	GLfloat playerXStart = x1 - playerWidth / 2;
	GLfloat playerXEnd = x1 + playerWidth / 2;
	GLfloat playerYStart = y1;
	GLfloat playerYEnd = y1 + playerHeight;
	GLfloat playerZStart = z1 - playerWidth / 2;
	GLfloat playerZEnd = z1 + playerWidth / 2;
	bool xOverlapping = ((x2Start <= playerXStart && playerXStart <= x2End) ||
		(x2Start <= playerXEnd && playerXEnd <= x2End) ||
		(playerXStart <= x2Start && x2Start <= playerXEnd) ||
		(playerXStart <= x2End && x2End <= playerXEnd));
	bool yOverlapping = ((y2Start <= playerYStart && playerYStart <= y2End) ||
		(y2Start <= playerYEnd && playerYEnd <= y2End) ||
		(playerYStart <= y2Start && y2Start <= playerYEnd) ||
		(playerYStart <= y2End && y2End <= playerYEnd));
	bool zOverlapping = ((z2Start <= playerZStart && playerZStart <= z2End) ||
		(z2Start <= playerZEnd && playerZEnd <= z2End) ||
		(playerZStart <= z2Start && z2Start <= playerZEnd) ||
		(playerZStart <= z2End && z2End <= playerZEnd));
	return xOverlapping && yOverlapping && zOverlapping;
}
// checks if player's new change in position would collide (overlap) any of the obstacles
bool isColliding(GLfloat deltaX, GLfloat deltaY, GLfloat deltaZ) {
	// calculate new coords
	GLfloat centerX = playerX + deltaX;
	GLfloat centerY = playerY + deltaY;
	GLfloat centerZ = playerZ + deltaZ;
	for (int i = 0; i < L1numberOfObstacles; i++)
	{
		GLfloat* currentObstacle = L1obstacles[i];
		if (checkCollision(centerX, centerY, centerZ, currentObstacle[0], currentObstacle[1], currentObstacle[2], currentObstacle[3], currentObstacle[4], currentObstacle[5])) {
			return true;
		}
	}
	return false;
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


//// drawWolf {
//
//glTranslate  <- parameters of player
//wolf.Draw()
//
//
//}



void drawPlayer() {
	glPushMatrix();

	// Translate to the player's position in the world
	glTranslatef(playerX, playerY, playerZ);

	// rotate player's head independently of his body
	glPushMatrix();
	glTranslatef(0, playerHeight * 7 / 8, 0);
	glRotatef(playerDirectionRotationFacing, 0.0, 1.0, 0.0);
	glRotatef(playerDirectionRotationFacingVertical, 0.0, 0.0, 1.0);
	glColor3f(0.94f, 0.80f, 0.72f);
	drawCuboid(-playerWidth / 2, playerWidth / 2, playerHeight * -1 / 8, playerHeight * 1 / 8, -playerWidth / 2, playerWidth / 2);
	glPopMatrix();

	// rotate whole player body except for his head (camera bardo)
	glRotatef(playerDirectionRotationBody, 0.0, 1.0, 0.0);

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	drawCuboid(-playerWidth / 2, playerWidth / 2, 0.0f, playerHeight * 3 / 4, -playerWidth / 2, playerWidth / 2);
	glColor3f(1.0f, 0.843f, 0.0f);
	drawCuboid(playerWidth / 2, playerWidth / 2 + 0.001f, 0.0f, playerHeight * 3 / 4, -playerWidth / 2, playerWidth / 2);
	glPopMatrix();
	glPopMatrix();
}



