#include <OpenGLMeshLoader.h>
#include "../CommonH/Engine.h"
#include "../CommonH/Controls.h"
#include "../../Level1/Level1H/Playground.h"
#include "../../Level1/Level1H/Level1Obstacles.h"
#include "../../Level1/Level1H/Level1.h"

#include "../../Level2/Level2H/Level2Obstacles.h"
#include "../../Level2/Level2H/Level2.h"

float lastFrameTime = 0.0f;
float deltaTime = 0.016f;
float currentTime = 0.0f;
int level = 1;
GLfloat fallAcceleration = -0.05f; // e3tebro gravity
bool loseL1Sound = false;

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

	glutSetCursor(GLUT_CURSOR_NONE);


	updateCheckpoint();

	updateWinLevel1();
	updateWinLevel2();

	updateDeltaTime();

	currentTime += deltaTime;
	setupLights(currentTime);

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

	// level 2

	for (int i = 0; i < 15; i++) {
		if (chandeliers[i] != nullptr) {
			handleChandelierCollision(*chandeliers[i]);
			handleSnowBallCollision(*snowBalls[i]);
		}
	}

	for (int i = 0; i < 5; i++) {
		if (coinsL2[i] != nullptr) {
			handleCoinCollision(*coinsL2[i]);
		}
	}



	glutPostRedisplay();
}

void drawGradientSky() {
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 0.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glShadeModel(GL_SMOOTH);

	glBegin(GL_QUADS);

	if (level == 1) {
		// Level 1: Gradient from Bright orange to Bright red
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex2f(0.0f, 1.0f);
		glVertex2f(1.0f, 1.0f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(1.0f, 0.0f);
		glVertex2f(0.0f, 0.0f);
	}
	else if (level == 2) {
		// Level 2: Gradient from light blue to dark blue
		glColor3f(0.53f, 0.81f, 0.98f);
		glVertex2f(0.0f, 1.0f);
		glVertex2f(1.0f, 1.0f);

		glColor3f(0.0f, 0.0f, 0.5f);
		glVertex2f(1.0f, 0.0f);
		glVertex2f(0.0f, 0.0f);
	}
	glEnd();

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
}


void renderBoldStrokeText(float x, float y, float z, const char* text, float scale, float lineWidth) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(scale, scale, scale);
	glLineWidth(lineWidth);
	for (const char* c = text; *c != '\0'; c++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}

void drawHUD() {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_LIGHTING);

	glColor3f(1.0f, 1.0f, 1.0f);

	char timerPos[100];
	snprintf(timerPos, sizeof(timerPos), "Time Left: %i", timerL1);
	renderBoldStrokeText(250.0f, 450.0f, 0.0f, timerPos, 0.15f, 4.0f);

	char scorePos[100];
	snprintf(scorePos, sizeof(scorePos), "Score: %i", scoreL1);
	renderBoldStrokeText(530.0f, 450.0f, 0.0f, scorePos, 0.15f, 4.0f);

	glEnable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void renderCheckpointMessage(const char* message) {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);

	renderBoldStrokeText(230.0f, 420.0f, 0.0f, message, 0.15f, 4.0f);

	glEnable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
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

	if (level == 1) {
		mciSendString(TEXT("open \"music/bgm1.wav\" type mpegvideo alias bgm"), NULL, 0, NULL);
		mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);
	}
	else {
		mciSendString(TEXT("open \"music/bgm2.wav\" type mpegvideo alias bgm"), NULL, 0, NULL);
		mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);
	}
}


void stopBackgroundMusic() {
	mciSendString(TEXT("stop bgm"), NULL, 0, NULL);
	mciSendString(TEXT("close bgm"), NULL, 0, NULL);
}

void drawGameOverScreen() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	if(level==1){
		glColor3f(1.0f, 0.0f, 0.0f);
	}
	else {
		glClearColor(0.0f, 0.0f, 0.8f, 0.8f);
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	

	renderBitmapString(270.0f, 300.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Game Over");

	renderBitmapString(260.0f, 250.0f, GLUT_BITMAP_HELVETICA_18, "You ran out of time!");

	glEnable(GL_LIGHTING);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glFlush();
	glutSwapBuffers();
}

void drawGameWinScreen() {
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	if (level == 2) {
		glClearColor(0.0f, 0.0f, 0.8f, 1.0f); 
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	glColor3f(0.0f, 0.0f, 1.0f);

	if (level == 1) {

		renderBitmapString(270.0f, 300.0f, GLUT_BITMAP_TIMES_ROMAN_24, "You win level 1!");

		char scorePos[100];
		snprintf(scorePos, sizeof(scorePos), "Score: %i", scoreL1);
		renderBitmapString(290.0f, 280.0f, GLUT_BITMAP_HELVETICA_18, scorePos);

		renderBitmapString(275.0f, 250.0f, GLUT_BITMAP_HELVETICA_18, "Loading Level 2...");
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);
		renderBitmapString(250.0f, 300.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Congrats! You beat the game!");

		char scorePos[100];
		snprintf(scorePos, sizeof(scorePos), "Final Score: %i", scoreL1);
		renderBitmapString(280.0f, 280.0f, GLUT_BITMAP_HELVETICA_18, scorePos);

	}

	glEnable(GL_LIGHTING);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glFlush();
	glutSwapBuffers();
	glPopAttrib();
}


void level2Transition(int value) {
	checkPointSound = false;
	

	level = 2;
	
	whichCp = 0;
	gameStatus = PLAYING;
	playBackgroundMusic();

	spawnPoint = spawnPoint0L2;
	playerDirectionRotationFacing = spawnPoint0DirectionL2;
	playerDirectionRotationBody = spawnPoint0DirectionL2;

	playerX = spawnPoint.x;
	playerY = spawnPoint.y;
	playerZ = spawnPoint.z;
	playerVerticalSpeed = 0.0f;
	isPlayerJumping = false;

	glutDisplayFunc(DisplayL2);
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
	//glutPassiveMotionFunc(MouseMovement);  


	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	LoadAssetsL1();
	LoadAssetsL2();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	level2Transition(0); // go to level 2 directly
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
