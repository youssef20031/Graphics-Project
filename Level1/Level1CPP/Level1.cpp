#include "../../OpenGLMeshLoader.h"
#include "../Level1H/Level1.h"


#include <cmath> 

float M_PI = 3.14;

GameStatus gameStatus = PLAYING;


float platformVisibilityTimer = 0.0f;

GLfloat originalYStart[L1numberOfObstacles];
GLfloat originalYEnd[L1numberOfObstacles];

int timerL1=200;
int scoreL1=0;

bool roarSound = false;
bool checkPointSound = false;
bool winL1Sound = false;




void updateTimer(int value){
    if (timerL1 > 0) {
        timerL1--;
        glutTimerFunc(1000, updateTimer, 0);
    }
    else {
        gameStatus = LOSE;
    }

   
}


void dragonRoar() {
    if (!roarSound) {
        if (playerX <= -14.36 && playerX >= -14.42 && playerZ >= 46.10 && playerZ <= 49.9) {
            PlaySound(TEXT("music/roar.wav"), NULL, SND_FILENAME | SND_ASYNC);
            roarSound = true;
        }
    }
}

void DisplayL1() {

    if (gameStatus == LOSE) {
        drawGameOverScreen();
        stopBackgroundMusic();
        if (!loseL1Sound) {
            PlaySound(TEXT("music/loseL1.wav"), NULL, SND_FILENAME | SND_ASYNC);
            loseL1Sound = true;
        }
        return;
    }
    if (gameStatus == WIN) {
        timerL1 = 207;
        drawGameWinScreen();
        stopBackgroundMusic();
        if (!winL1Sound) {
            PlaySound(TEXT("music/winL1.wav"), NULL, SND_FILENAME | SND_ASYNC);
            winL1Sound = true;
        }
        // timer function to get us to level 2
        glutTimerFunc(7000, level2Transition, 0);
        return;
    }
 
    //drawSkybox();
	setupCamera();
	//setupLights(currentTime);
	glutFullScreen();
    glClearColor(1.0f, 0.65f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawGradientSky();
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
            float movementSpeed = 0.5f; 
            float horizontalOffset = sin(elapsedTime * movementSpeed) * movementRange;

            L1currentObstacle[0] = -215.0f + horizontalOffset; 
            L1currentObstacle[1] = -216.0f + horizontalOffset; 
        }

        if (i == 50) {
            drawLavaCuboid(L1currentObstacle[0], L1currentObstacle[1], L1currentObstacle[2],
                L1currentObstacle[3], L1currentObstacle[4], L1currentObstacle[5]);
       }

        // Draw the obstacle
        if (!(i>=45&&i<=48)&&i!=50)   // invisible collisions for the checkpoints and other models
        drawTexturedCuboid(L1currentObstacle[0], L1currentObstacle[1], L1currentObstacle[2],
            L1currentObstacle[3], L1currentObstacle[4], L1currentObstacle[5]);
        
       

    }
    
	

	drawPlayer();

  
	
	axe.Draw();
	axe2.Draw();
	axe3.Draw();
	axe4.Draw();
	axe5.Draw();

        

    flag1.Draw();
    flag2.Draw();
    flag3.Draw();
    
    
    
    coin1.Draw(); 
    coin2.Draw();
    coin3.Draw();
    coin4.Draw();
    coin5.Draw();


    

    torch.Draw();
    torch2.Draw();
    torch3.Draw();
    torch4.Draw();



    // this is because sometimes the model for some reason messes with the skybox
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    goal.Draw();
    glPopAttrib();

    barrel.Draw();

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    dragon.Draw();
    glPopAttrib();

    if (showCheckpointMessage) {
        float currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
        if (currentTime - checkpointMessageStartTime < 3.0f) {
            renderCheckpointMessage("Checkpoint Reached!");

            if (!checkPointSound) {
                PlaySound(TEXT("music/checkpoint.wav"), NULL, SND_FILENAME | SND_ASYNC);
                checkPointSound = true;
            }
        }
        else {
            showCheckpointMessage = false;
        }
    }

    drawHUD();
	

	glFlush();
	glutSwapBuffers();
}

