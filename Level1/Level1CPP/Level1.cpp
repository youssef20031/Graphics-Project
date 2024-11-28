#include "../Level1H/Level1.h"

#include <cmath> 
void DisplayL1() {
	setupCamera();
	setupLights();
	glutFullScreen();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	displayCameraCoords();
	drawAxis();
	glColor3f(0.2f, 0.7f, 0.8f);
	for (int i = 0; i < numberOfObstacles; i++)
	{
		GLfloat* currentObstacle = obstacles[i];
		drawCuboid(currentObstacle[0], currentObstacle[1], currentObstacle[2], currentObstacle[3], currentObstacle[4], currentObstacle[5]);
	}
	drawPlayer();
	glFlush();
	glutSwapBuffers();
}

