#include "../../OpenGLMeshLoader.h"
#include "../Level1H/Level1.h"


#include <cmath> 

float M_PI = 3.14;


float platformVisibilityTimer = 0.0f;

GLfloat originalYStart[L1numberOfObstacles];
GLfloat originalYEnd[L1numberOfObstacles];

//Model_3DS wolfplayermodel;



void DisplayL1() {
    drawSkybox();
	setupCamera();
	//setupLights();
	glutFullScreen();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	displayCameraCoords();
	drawAxis();
	glColor3f(0.2f, 0.7f, 0.8f);
    float elapsedTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;  

    for (int i = 0; i < L1numberOfObstacles; i++) {
        GLfloat* L1currentObstacle = L1obstacles[i];

        //red checkpoint color
        if (i == 13 || i == 16 || i == 31) {
            glColor3f(1.0f, 0.0f, 0.0f); 
        }
        else {
            glColor3f(0.2f, 0.7f, 0.8f); 
        }

        // the invisible platforms

        if (i>=32&&i<=35) {
            if (fmod(elapsedTime, 7.0f) < 4.0f) {
                continue;
            }
        }

        // moving platform (vertical)
        if (i == 37) {
            float movementRange = 4.0f;    
            float movementSpeed = 2.0f;   

            float verticalOffset = sin(elapsedTime * movementSpeed) * movementRange;

            L1currentObstacle[2] = originalYStart[i] + verticalOffset+7; // Ystart
            L1currentObstacle[3] = originalYEnd[i] + verticalOffset+6.5;   // Yend
        }

        // Moving platform (horizontal)
        if (i == 39) {
            float movementRange = 12.0f; 
            float movementSpeed = 1.5f; 
            float horizontalOffset = sin(elapsedTime * movementSpeed) * movementRange;

            L1currentObstacle[0] = -215.0f + horizontalOffset; 
            L1currentObstacle[1] = -216.0f + horizontalOffset; 
        }

        // Draw the obstacle
        drawTexturedCuboid(L1currentObstacle[0], L1currentObstacle[1], L1currentObstacle[2],
            L1currentObstacle[3], L1currentObstacle[4], L1currentObstacle[5]);
    }

	

	drawPlayer();

	
	axe.Draw();
	axe2.Draw();
	axe3.Draw();
	axe4.Draw();
	axe5.Draw();

    wolfplayermodel.Draw();

    //loadBMP(&texL1, "Textures/blu-sky-3.bmp", true);

	

	glFlush();
	glutSwapBuffers();
}

