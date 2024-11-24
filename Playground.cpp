
#include "Playground.h"
#include <cmath>  // for sqrt() and cos(), sin()


#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

ViewMode viewMode = THIRD_PERSON;

bool keyStates[256] = { false }; // to track state of keys pressed
bool specialKeyStates[256] = { false }; // to track state of special keys pressed

GLfloat playerX = 0.0f;
GLfloat playerY = 0.1f;
GLfloat playerZ = 0.0f;
GLfloat playerHeight = 0.6f;
GLfloat playerWidth = 0.2f;
GLfloat playerMovementSpeed = 0.005f;

// player rotating animation
GLfloat playerDirectionRotationFacing = 0.0f; // direction player facing
GLfloat playerDirectionRotationBody = 0.0f; // direction player facing
GLfloat playerRotationAnimationSpeed = 1.0f;
GLfloat playerRotationSpeed = 0.25f;
bool rotatingLeft = false;
bool rotatingRight = false;
bool rotatingForward = false;
bool rotatingBack = false;





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

void setupLights() {
	GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
	GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
	GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}


void drawAxis() {
	glPushMatrix();

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 10.0f);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 10.0f, 0.0f);
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, 0.0f);
	glEnd();

	glPopMatrix();
}


void setFirstPersonCamera() {
	GLfloat angleRadians = playerDirectionRotationFacing * M_PI / 180.0f;  // Convert to radians

	// Calculate the direction the player is facing using sin and cos
	GLfloat centerOffsetX = cos(angleRadians) * 2.0f;  // 2.0f is the distance from the player
	GLfloat centerOffsetZ = -(sin(angleRadians) * 2.0f);  // 2.0f is the distance from the player

	GLfloat eyeOffsetX = cos(angleRadians) * 0.2f;  // 2.0f is the distance from the player
	GLfloat eyeOffsetZ = -(sin(angleRadians) * 0.2f);  // 2.0f is the distance from the player

	// Set the camera position
	camera.setView(playerX + eyeOffsetX, playerY + playerHeight * 0.875, playerZ + eyeOffsetZ, playerX + centerOffsetX, playerY + (playerHeight / 2), playerZ + centerOffsetZ);
}

void setThirdPersonCamera() {
	GLfloat angleRadians = playerDirectionRotationFacing * M_PI / 180.0f;  // Convert to radians

	// Calculate the direction the player is facing using sin and cos
	GLfloat centerOffsetX = cos(angleRadians) * 2.0f;  // 2.0f is the distance from the player
	GLfloat centerOffsetZ = -(sin(angleRadians) * 2.0f);  // 2.0f is the distance from the player

	GLfloat eyeOffsetX = cos(angleRadians) * - 2.0f;  // 2.0f is the distance from the player
	GLfloat eyeOffsetZ = -(sin(angleRadians) * - 2.0f);  // 2.0f is the distance from the player

	// Set the camera position
	camera.setView(playerX + eyeOffsetX, playerY + (playerHeight * 2), playerZ + eyeOffsetZ, playerX + centerOffsetX, playerY + (playerHeight / 2), playerZ + centerOffsetZ);
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
	drawCuboid(-playerWidth / 2, playerWidth / 2, 0.0f, playerHeight * 3 / 4, - playerWidth / 2, playerWidth / 2);
	glColor3f(1.0f, 0.843f, 0.0f);
	drawCuboid(playerWidth / 2, playerWidth / 2 + 0.001f, 0.0f, playerHeight * 3 / 4, - playerWidth / 2, playerWidth / 2);
	glPopMatrix();
	glPopMatrix();
}

/////////////////////////////// Display ////////////////////////////////

void Display() {
	setupCamera();
	setupLights();

	glutFullScreen();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	displayCameraCoords();

	drawAxis();

	glColor3f(0.2f, 0.7f, 0.8f);
	drawCuboid(0.0f, 3.0f, 0.0f, 0.1f, 0.0f, 3.0f); // ground

	drawPlayer();

	glFlush();
	glutSwapBuffers();
}
void Keyboard(unsigned char key, int x, int y) {
	switch (key) {
		// player movement
	case 'w':
		keyStates['w'] = true;
		break;
	case 's':
		keyStates['s'] = true;
		break;
	case 'a':
		keyStates['a'] = true;
		break;
	case 'd':
		keyStates['d'] = true;
		break;
	case ' ':
		keyStates[' '] = true;
		break;

		// camera states
	case '1':
		printf("First Person View Active\n");
		viewMode = FIRST_PERSON;
		setFirstPersonCamera();
		break;
	case '2':
		printf("Third Person View Active\n");
		viewMode = THIRD_PERSON;
		setThirdPersonCamera();
		break;
	case '3':
		printf("Free View Active\n");
		viewMode = FREE;
		break;

		// camera movement
	case 'i':
		keyStates['i'] = true;
		break;
	case 'k':
		keyStates['k'] = true;
		break;
	case 'j':
		keyStates['j'] = true;
		break;
	case 'l':
		keyStates['l'] = true;
		break;
	case 'u':
		keyStates['u'] = true;
		break;
	case 'o':
		keyStates['o'] = true;
		break;

	case GLUT_KEY_ESCAPE:
		exit(EXIT_SUCCESS);
	}

	glutPostRedisplay();
}
void KeyboardUp(unsigned char key, int x, int y) {
	switch (key) {
		// player movement
	case 'w':
		keyStates['w'] = false;
		break;
	case 's':
		keyStates['s'] = false;
		break;
	case 'a':
		keyStates['a'] = false;
		break;
	case 'd':
		keyStates['d'] = false;
		break;
	case ' ':
		keyStates[' '] = false;
		break;

		// camera movement
	case 'i':
		keyStates['i'] = false;
		break;
	case 'k':
		keyStates['k'] = false;
		break;
	case 'j':
		keyStates['j'] = false;
		break;
	case 'l':
		keyStates['l'] = false;
		break;
	case 'u':
		keyStates['u'] = false;
		break;
	case 'o':
		keyStates['o'] = false;
		break;
	}

	glutPostRedisplay();
}
void Special(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		specialKeyStates[GLUT_KEY_UP] = true;
		break;
	case GLUT_KEY_DOWN:
		specialKeyStates[GLUT_KEY_DOWN] = true;
		break;
	case GLUT_KEY_LEFT:
		specialKeyStates[GLUT_KEY_LEFT] = true;
		break;
	case GLUT_KEY_RIGHT:
		specialKeyStates[GLUT_KEY_RIGHT] = true;
		break;
	}

	glutPostRedisplay();
}
void SpecialUp(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		specialKeyStates[GLUT_KEY_UP] = false;
		break;
	case GLUT_KEY_DOWN:
		specialKeyStates[GLUT_KEY_DOWN] = false;
		break;
	case GLUT_KEY_LEFT:
		specialKeyStates[GLUT_KEY_LEFT] = false;
		break;
	case GLUT_KEY_RIGHT:
		specialKeyStates[GLUT_KEY_RIGHT] = false;
		break;
	}

	glutPostRedisplay();
}

void updateStates() {
	updateCameraMovement(); // update key presses

	updatePlayerMovement(); // updates player movement duhhhhh

	updatePlayerRotation();

	glutPostRedisplay();
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

void updateCameraMovement() {
	float d = 0.002;
	float a = 0.08;

	if (viewMode != FREE) return;

	if (keyStates['i']) {
		camera.moveY(d);
	}
	if (keyStates['k']) {
		camera.moveY(-d);
	}
	if (keyStates['j']) {
		camera.moveX(d);
	}
	if (keyStates['l']) {
		camera.moveX(-d);
	}
	if (keyStates['u']) {
		camera.moveZ(d);
	}
	if (keyStates['o']) {
		camera.moveZ(-d);
	}

	if (specialKeyStates[GLUT_KEY_UP]) {
		camera.rotateX(a);
	}
	if (specialKeyStates[GLUT_KEY_DOWN]) {
		camera.rotateX(-a);
	}
	if (specialKeyStates[GLUT_KEY_LEFT]) {
		camera.rotateY(a);
	}
	if (specialKeyStates[GLUT_KEY_RIGHT]) {
		camera.rotateY(-a);
	}
}
