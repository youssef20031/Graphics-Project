#include <OpenGLMeshLoader.h>
#include "../CommonH/Engine.h"
#include "../../Level1/Level1H/Playground.h"
#include "../../Level1/Level1H/Level1Obstacles.h"
#include "../../Level1/Level1H/Level1.h"

float lastFrameTime = 0.0f;
float deltaTime = 0.016f;


// Note: Any time you need to use speed reference this file in the header and multiply with deltaTime

void updateDeltaTime() {
	float currentFrameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	deltaTime = currentFrameTime - lastFrameTime;
	lastFrameTime = currentFrameTime;
}

void updateStates() {
	updateCameraMovement(); // update key presses

	updatePlayerMovement(); // updates player movement duhhhhh

	updatePlayerVerticalMovement(); // updates player jumping and falling

	updatePlayerRotation();


	// Level 1
	updateCheckpoint();

	updateWinLevel1();

	updateDeltaTime();

	for (int i = 0; i < 5; i++) {
		if (axes[i] != nullptr) {
			handleAxeCollision(*axes[i]);
		}
	}

	for (int i = 0; i < 5; i++) {
		if (coins[i] != nullptr) { 
			handleCoinCollision(*coins[i]);
		}
	}

	dragonRoar();

	glutPostRedisplay();
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


void realDeal(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(WIDTH, HEIGHT);

	glutInitWindowPosition(100, 150);

	glutCreateWindow(title);

	glutDisplayFunc(myDisplay);

	glutKeyboardFunc(myKeyboard);

	glutMotionFunc(myMotion);

	glutMouseFunc(myMouse);

	glutReshapeFunc(myReshape);

	myInit();

	LoadAssets();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
}

void playgroundMain(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);

	glutIdleFunc(updateStates);

	glutCreateWindow("Playground");
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutKeyboardUpFunc(KeyboardUp);
	glutSpecialFunc(Special);
	glutSpecialUpFunc(SpecialUp);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
}

void playBackgroundMusic() {
	mciSendString(TEXT("open \"music/bgm1.wav\" type mpegvideo alias bgm"), NULL, 0, NULL);
	mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);
}


void stopBackgroundMusic() {
	mciSendString(TEXT("stop bgm"), NULL, 0, NULL);
	mciSendString(TEXT("close bgm"), NULL, 0, NULL);
}

void Level1Main(int argc, char** argv) {
	playBackgroundMusic();
	glutInit(&argc, argv);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);

	glutIdleFunc(updateStates);
	glutTimerFunc(1000, updateTimer, 0);
	glutCreateWindow("Level 1");
	glutDisplayFunc(DisplayL1);
	glutKeyboardFunc(Keyboard);
	glutKeyboardUpFunc(KeyboardUp);
	glutSpecialFunc(Special);
	glutSpecialUpFunc(SpecialUp);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	LoadAssetsL1();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
}




//=======================================================================
// Main Function
//=======================================================================

void main(int argc, char** argv) {
	//realDeal(argc, argv);
	//playgroundMain(argc, argv);
	Level1Main(argc, argv);
}
