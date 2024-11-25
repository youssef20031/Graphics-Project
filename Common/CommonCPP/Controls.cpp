
#include "../CommonH/Controls.h"
#include "../CommonH/Camera.h"
#include <glut.h>

#define GLUT_KEY_ESCAPE 27

bool keyStates[256] = { false };       // Tracks the state of normal keys
bool specialKeyStates[256] = { false }; // Tracks the state of special keys


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