#include "Player.h"
#include "Camera.h"



GLfloat playerX = 0.0f;
GLfloat playerY = 0.1f;
GLfloat playerZ = 0.0f;
GLfloat playerHeight = 0.6f;
GLfloat playerWidth = 0.2f;
GLfloat playerMovementSpeed = 0.005f;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// player rotating animation
GLfloat playerDirectionRotationFacing = 0.0f; // direction player facing
GLfloat playerDirectionRotationBody = 0.0f; // direction player facing
GLfloat playerRotationAnimationSpeed = 1.0f;
GLfloat playerRotationSpeed = 0.25f;
bool rotatingLeft = false;
bool rotatingRight = false;
bool rotatingForward = false;
bool rotatingBack = false;


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

	// Translate to the player's position in the world
	glTranslatef(playerX, playerY, playerZ);

	// rotate player's head independently of his body
	glPushMatrix();
	glRotatef(playerDirectionRotationFacing, 0.0, 1.0, 0.0);
	glColor3f(0.94f, 0.80f, 0.72f);
	drawCuboid(-playerWidth / 2, playerWidth / 2, playerHeight * 3 / 4, playerHeight, -playerWidth / 2, playerWidth / 2);
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

void updatePlayerMovement() {
	bool moving = false;
	if (keyStates['w']) {
		// calculate the new x and z positions
		GLfloat speedX = playerMovementSpeed * cos(-playerDirectionRotationFacing * M_PI / 180.0f);
		GLfloat speedZ = playerMovementSpeed * sin(-playerDirectionRotationFacing * M_PI / 180.0f);
		//if (!isCollision(playerX + speedX, playerY, playerZ + speedZ)) {
		playerX += speedX;
		playerZ += speedZ;
		//}
		moving = true;
	}
	if (keyStates['s']) {
		// calculate the new x and z positions
		GLfloat speedX = -playerMovementSpeed * cos(-playerDirectionRotationFacing * M_PI / 180.0f);
		GLfloat speedZ = -playerMovementSpeed * sin(-playerDirectionRotationFacing * M_PI / 180.0f);
		//if (!isCollision(playerX + speedX, playerY, playerZ + speedZ)) {
		playerX += speedX;
		playerZ += speedZ;
		//}
		moving = true;
	}
	if (keyStates['d']) {
		// calculate the new x and z positions
		GLfloat speedX = playerMovementSpeed * sin(playerDirectionRotationFacing * M_PI / 180.0f);
		GLfloat speedZ = playerMovementSpeed * cos(playerDirectionRotationFacing * M_PI / 180.0f);
		//if (!isCollision(playerX + speedX, playerY, playerZ + speedZ)) {
		playerX += speedX;
		playerZ += speedZ;
		//}
		moving = true;
	}
	if (keyStates['a']) {
		// calculate the new x and z positions
		GLfloat speedX = -playerMovementSpeed * sin(playerDirectionRotationFacing * M_PI / 180.0f);
		GLfloat speedZ = -playerMovementSpeed * cos(playerDirectionRotationFacing * M_PI / 180.0f);
		//if (!isCollision(playerX + speedX, playerY, playerZ + speedZ)) {
		playerX += speedX;
		playerZ += speedZ;
		//}
		moving = true;
	}

	if (specialKeyStates[GLUT_KEY_LEFT]) {
		playerDirectionRotationFacing += playerRotationSpeed;
		moving = true;
	}
	if (specialKeyStates[GLUT_KEY_RIGHT]) {
		playerDirectionRotationFacing -= playerRotationSpeed;
		moving = true;
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


