
#include "Playground.h"
#include <cmath>  // for sqrt() and cos(), sin()


#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

ViewMode viewMode = THIRD_PERSON;

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
