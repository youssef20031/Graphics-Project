
#include "../CommonH/Controls.h"
#include "../CommonH/Camera.h"
#include "../../Level1/Level1H/Level1.h"
#include <glut.h>

#define GLUT_KEY_ESCAPE 27

bool keyStates[256] = { false };       // Tracks the state of normal keys
bool specialKeyStates[256] = { false }; // Tracks the state of special keys
bool mouseStates[256] = { false };

int lastMouseX = 0;
int lastMouseY = 0;
bool firstMouse = true;

int MOVE_THRESHOLD = 5;


void Keyboard(unsigned char key, int x, int y) {

	if(key== GLUT_KEY_ESCAPE)
		exit(EXIT_SUCCESS);

	if (gameStatus == PLAYING) {
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

		}

		glutPostRedisplay();
	}
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

void MouseMovement(int x, int y) {
	static const float sensitivity = 3.0f;
	int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	int centerX = windowWidth / 2;
	int centerY = windowHeight / 2;

	if (firstMouse) {
		lastMouseX = centerX;
		lastMouseY = centerY;
		firstMouse = false;
		glutWarpPointer(centerX, centerY);
		return;
	}

	int deltaX = x - centerX;
	int deltaY = y - centerY;

	if (deltaX == 0 && deltaY == 0)
		return;

	deltaX = static_cast<int>(deltaX * sensitivity);
	deltaY = static_cast<int>(deltaY * sensitivity);

	mouseStates[GLUT_KEY_RIGHT] = false;
	mouseStates[GLUT_KEY_LEFT] = false;
	mouseStates[GLUT_KEY_UP] = false;
	mouseStates[GLUT_KEY_DOWN] = false;

	if (deltaX > MOVE_THRESHOLD) {
		mouseStates[GLUT_KEY_RIGHT] = true;
	}
	else if (deltaX < -MOVE_THRESHOLD) {
		mouseStates[GLUT_KEY_LEFT] = true;
	}

	if (deltaY > MOVE_THRESHOLD) {
		mouseStates[GLUT_KEY_DOWN] = true;
	}
	else if (deltaY < -MOVE_THRESHOLD) {
		mouseStates[GLUT_KEY_UP] = true;
	}

	glutWarpPointer(centerX, centerY);

	glutPostRedisplay();
}
