#include "Playground.h"
#include <cmath> 
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

