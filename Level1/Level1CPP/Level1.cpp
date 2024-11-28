#include "../Level1H/Level1.h"

#include <cmath> 
void DisplayL1() {
	setupCamera();
	//setupLights();
	glutFullScreen();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	displayCameraCoords();
	drawAxis();
	glColor3f(0.2f, 0.7f, 0.8f);
	for (int i = 0; i < L1numberOfObstacles; i++)
	{
		GLfloat* L1currentObstacle = L1obstacles[i];
		drawCuboid(L1currentObstacle[0],L1currentObstacle[1], L1currentObstacle[2], L1currentObstacle[3], L1currentObstacle[4], L1currentObstacle[5]);
	}
	drawPlayer();
	glFlush();
	glutSwapBuffers();
}

