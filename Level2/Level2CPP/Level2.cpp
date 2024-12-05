#include "../../OpenGLMeshLoader.h"
#include "../Level2H/Level2.h"

Vector3f spawnPoint0L2 = Vector3f(0, 0.5, 0);
GLfloat spawnPoint0DirectionL2 = 0;

Vector3f spawnPoint1L2 = Vector3f(44.5, 0.5, 36.0);
GLfloat spawnPoint1DirectionL2 = 270;

Vector3f spawnPoint2L2 = Vector3f(29.0, 0.5, 80.0);
GLfloat spawnPoint2DirectionL2 = 180;


void DisplayL2() {
    //if (gameStatus == LOSE) {
    //    drawGameOverScreen();
    //    stopBackgroundMusic();
    //    if (!loseL1Sound) {
    //        PlaySound(TEXT("music/loseL1.wav"), NULL, SND_FILENAME | SND_ASYNC);
    //        loseL1Sound = true;
    //    }
    //    return;
    //}
    //if (gameStatus == WIN) {
    //    timerL1 = 999;
    //    drawGameWinScreen();
    //    stopBackgroundMusic();
    //    if (!winL1Sound) {
    //        PlaySound(TEXT("music/winL1.wav"), NULL, SND_FILENAME | SND_ASYNC);
    //        winL1Sound = true;
    //    }
    //    // timer function to get us to level 2
    //    glutTimerFunc(3000, level2Transition, 0);
    //    return;
    //}

    drawSkybox();
    setupCamera();
    //setupLights();
    glutFullScreen();
    glClearColor(1.0f, 0.65f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawGradientSky();
    displayCameraCoords();
    drawAxis();
    glColor3f(0.2f, 0.7f, 0.8f);
    float elapsedTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;

    for (int i = 0; i < L2numberOfObstacles; i++) {
        GLfloat* L2currentObstacle = L2obstacles[i];

        //// red checkpoint color
        //if (i == 13 || i == 16 || i == 31) {
        //    glColor3f(1.0f, 0.0f, 0.0f);
        //}
        //else {
        //    glColor3f(0.2f, 0.7f, 0.8f);
        //}

        //// the invisible platforms

        //if (i >= 32 && i <= 35) {
        //    if (fmod(elapsedTime, 7.0f) < 4.0f) {
        //        continue;
        //    }
        //}

        //// moving platform (vertical)
        //if (i == 37) {
        //    float movementRange = 4.0f;
        //    float movementSpeed = 2.0f;

        //    float verticalOffset = sin(elapsedTime * movementSpeed) * movementRange;

        //    L1currentObstacle[2] = originalYStart[i] + verticalOffset + 7; // Ystart
        //    L1currentObstacle[3] = originalYEnd[i] + verticalOffset + 6.5;   // Yend
        //}

        //// Moving platform (horizontal)
        //if (i == 39) {
        //    float movementRange = 12.0f;
        //    float movementSpeed = 0.5f;
        //    float horizontalOffset = sin(elapsedTime * movementSpeed) * movementRange;

        //    L1currentObstacle[0] = -215.0f + horizontalOffset;
        //    L1currentObstacle[1] = -216.0f + horizontalOffset;
        //}

        //if (i == 50) {
        //    drawLavaCuboid(L1currentObstacle[0], L1currentObstacle[1], L1currentObstacle[2],
        //        L1currentObstacle[3], L1currentObstacle[4], L1currentObstacle[5]);
        //}

        // Draw the obstacle
        drawTexturedCuboidL2(L2currentObstacle[0], L2currentObstacle[1], L2currentObstacle[2], L2currentObstacle[3], L2currentObstacle[4], L2currentObstacle[5]);



    }

    drawPlayer();

    //loadBMP(&texL1, "Textures/blu-sky-3.bmp", true);

    flag1L2.Draw();
    flag2L2.Draw();
    flag3L2.Draw();

    coin1L2.Draw();
    coin2L2.Draw();
    coin3L2.Draw();
    coin4L2.Draw();
    coin5L2.Draw();

    torchL2.Draw();
    torch2L2.Draw();
    torch3L2.Draw();
    torch4L2.Draw();


    // Chandeliers

    for (int i = 0; i < 15; i++)
    {
        chandeliers[i]->Draw();
    }


    // this is because sometimes the model for some reason messes with the skybox
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    goalL2.Draw();
    glPopAttrib();


    glPushAttrib(GL_ALL_ATTRIB_BITS);
    dragonL2.Draw();
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