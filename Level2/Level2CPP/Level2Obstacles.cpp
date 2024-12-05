#include "../Level2H/Level2Obstacles.h"
#include <iostream>

extern GLfloat L2obstacles[L2numberOfObstacles][6];

GLTexture icetex;
GLuint texL2;

Cpflag flag1L2;
Cpflag flag2L2;
Cpflag flag3L2;

Collectible coin1L2;
Collectible coin2L2;
Collectible coin3L2;
Collectible coin4L2;
Collectible coin5L2;

Collectible* coinsL2[5] = {
    &coin1L2,
    &coin2L2,
    &coin3L2,
    &coin4L2,
    &coin5L2
};

Goal goalL2;

Model_3DS dinosaur;

Model_3DS torchL2;
Model_3DS torch2L2;
Model_3DS torch3L2;
Model_3DS torch4L2;

// Chandelier

// Chandelier
Chandelier chandelier1;
Chandelier chandelier2;
Chandelier chandelier3;
Chandelier chandelier4;
Chandelier chandelier5;
Chandelier chandelier6;
Chandelier chandelier7;
Chandelier chandelier8;
Chandelier chandelier9;
Chandelier chandelier10;
Chandelier chandelier11;
Chandelier chandelier12;
Chandelier chandelier13;
Chandelier chandelier14;
Chandelier chandelier15;

Chandelier* chandeliers[15] = {
    &chandelier1, 
    &chandelier2, 
    &chandelier3, 
    &chandelier4, 
    &chandelier5,
    &chandelier6,
    &chandelier7,
    &chandelier8,
    &chandelier9,
    &chandelier10,
    &chandelier11,
    &chandelier12,
    &chandelier13,
    &chandelier14,
    &chandelier15
};

// obstacles
GLfloat L2obstacles[L2numberOfObstacles][6] = {

    // CAVE SECTION (STAGE 0)

   { -5.0f, 25.0f, 0.0f, 0.1f, -10.0f, 10.0f },  // cave ground
   { -5.0f, 25.0f, 3.0f, 3.1f, -10.0f, 10.0f },  // cave roof
   { -5.0f, -5.1f, 0.0f, 3.0f, -10.0f, 10.0f },   // cave back wall
   { -5.0f, 25.0f, 0.0f, 3.0f, -10.0f, -10.1f },   // cave left wall
   { -5.0f, 25.0f, 0.0f, 3.0f, 10.0f, 10.1f },   // cave right wall
   { 25.0f, 25.1f, -21.0f, 3.0f, -10.0f, -2.0f },   // cave front left wall
   { 25.0f, 25.1f, -21.0f, 3.0f, 10.0f, 2.0f },   // cave front right wall
   { 25.0f, 25.1f, -21.0f, 0.0f, -2.0f, 2.0f },   // cave front middle wall (under platform)
   { 3.0f, 6.0f, 0.0f, 3.0f, 15.0f, 16.0f }, // cave middle wall 1
   { 0.0f, 3.0f, 0.0f, 3.0f, 25.0f, 26.0f }, // cave middle wall 2
   { 2.0f, 9.0f, 0.0f, 3.0f, 35.0f, 36.0f }, // cave middle wall 3

    // Big Cave Walls
   //{ 0.0f, 60.0f, -20.5f, -21.0f, -30.0f, 50.0f }, // ground (spikes)
   { 25.0f, 25.1f, -21.0f, 10.0f, -10.0f, -30.0f }, // 1- left
   { 25.0f, 60.0f, -21.0f, 10.0f, -30.1f, -30.0f }, // 2- forward
   { 60.0f, 60.1f, -21.0f, 10.0f, 50.0f, -30.1f }, // 3- right

    // Section 1 - Sliding Platforms
   { 25.0f, 30.0f, 0.0f, 0.1f, -2.0f, 2.0f },  // initial platform
   { 30.0f, 40.0f, 0.0f, 0.1f, -0.5f, 0.5f },  // 1 - forwards
   { 39.0f, 40.0f, 0.0f, 0.1f, -0.5f, -10.0f },  // 2 - left
   { 39.0f, 35.0f, 0.0f, 0.1f, -9.0f, -10.0f },  // 3 - backwards
   { 34.0f, 35.0f, 0.0f, 0.1f, -9.0f, -20.0f },  // 4 - left
   { 48.0f, 35.0f, 0.0f, 0.1f, -19.0f, -20.0f },  // 5 - forwards
   { 48.0f, 49.0f, 0.0f, 0.1f, -20.0f, 20.0f },  // 6 - right
   { 48.0f, 38.0f, 0.0f, 0.1f, 20.0f, 19.0f },  // 7 - backwards
   { 37.0f, 38.0f, 0.0f, 0.1f, 20.0f, 8.0f },  // 8 - left
   { 37.0f, 30.0f, 0.0f, 0.1f, 9.0f, 8.0f },  // 9 - backwards
   { 31.0f, 30.0f, 0.0f, 0.1f, 9.0f, 28.0f },  // 10 - right
   { 44.0f, 30.0f, 0.0f, 0.1f, 29.0f, 28.0f },  // 11 - forwards
   { 44.0f, 45.0f, 0.0f, 0.1f, 35.0f, 28.0f },  // 12 - right

   
   // Section 2 - Falling Chandeliers
   { 40.0f, 50.0f, 0.0f, 0.1f, 35.0f, 60.0f },  // stage platform
   { 40.0f, 50.0f, 0.0f, 0.1f, 60.0f, 65.0f },  // stage safezone platform

   { 44.5f, 45.5f, 0.0f, 0.1f, 65.0f, 80.5f },  // path connector to stage 3 (first part)
   { 44.5f, 30.0f, 0.0f, 0.1f, 79.5f, 80.5f },  // path connector to stage 3 (second part)


   // Section 3 - Platforms with snow balls
   { 25.0f, 30.0f, 0.0f, 0.1f, 75.0f, 85.0f },  // stage 3 safe zone
   { 24.0f, 25.0f, 0.0f, 0.1f, 78.0f, 82.0f },  // floating platform 1
   { 21.0f, 22.0f, 0.0f, 0.1f, 78.0f, 82.0f },  // floating platform 2
   { 18.0f, 19.0f, 0.0f, 0.1f, 78.0f, 82.0f },  // floating platform 3
   { 14.0f, 15.0f, 0.0f, 0.1f, 78.0f, 82.0f },  // floating platform 4
   { 11.0f, 12.0f, 0.0f, 0.1f, 78.0f, 82.0f },  // floating platform 5
   { 6.0f, 7.0f, 0.0f, 0.1f, 78.0f, 82.0f },  // floating platform 6
   { 3.0f, 4.0f, 0.0f, 0.1f, 78.0f, 82.0f },  // floating platform 7
   { -1.0f, 0.0f, 0.0f, 0.1f, 78.0f, 82.0f },  // floating platform 8
   { -7.0f, -6.0f, 0.0f, 0.1f, 78.0f, 82.0f },  // floating platform 9
   { -13.0f, -12.0f, 0.0f, 0.1f, 78.0f, 82.0f },  // floating platform 10
   { -19.0f, -18.0f, 0.0f, 0.1f, 78.0f, 82.0f },  // floating platform 11
   { -25.0f, -24.0f, 0.0f, 0.1f, 78.0f, 82.0f },  // floating platform 12
   { -30.0f, -25.0f, 0.0f, 0.1f, 75.0f, 85.0f },  // safe zone

   
   // staircase to game win!
   { -28.0f, -27.0f, 0.0f, 0.3f, 75.0f, 74.8f },  // step 1
   { -28.0f, -27.0f, 0.3f, 0.5f, 74.8f, 74.6f },  // step 2
   { -28.0f, -27.0f, 0.5f, 0.7f, 74.6f, 74.4f },  // step 3
   { -28.0f, -27.0f, 0.7f, 0.9f, 74.4f, 74.2f },  // step 4
   { -28.0f, -27.0f, 0.9f, 1.1f, 74.2f, 74.0f },  // step 5
   { -28.0f, -27.0f, 1.1f, 1.3f, 74.0f, 73.8f },  // step 6
   { -28.0f, -27.0f, 1.3f, 1.5f, 73.8f, 73.6f },  // step 7
   { -28.0f, -27.0f, 1.5f, 1.7f, 73.6f, 73.4f },  // step 8
   { -28.0f, -27.0f, 1.7f, 1.9f, 73.4f, 73.2f },  // step 9
   { -28.0f, -27.0f, 1.9f, 2.1f, 73.2f, 73.0f },  // step 10
   { -28.0f, -27.0f, 2.1f, 2.3f, 73.0f, 72.8f },  // step 11
   { -28.0f, -27.0f, 2.3f, 2.5f, 72.8f, 72.6f },  // step 12
   { -28.0f, -27.0f, 2.5f, 2.7f, 72.6f, 72.4f },  // step 13
   { -28.0f, -27.0f, 2.7f, 2.9f, 72.4f, 72.2f },  // step 14
   { -28.0f, -27.0f, 2.9f, 3.1f, 72.2f, 72.0f },  // step 15
   { -28.0f, -27.0f, 3.1f, 3.3f, 72.0f, 71.8f },  // step 16
   { -28.0f, -27.0f, 3.3f, 3.5f, 71.8f, 71.6f },  // step 17
   { -28.0f, -27.0f, 3.5f, 3.7f, 71.6f, 71.4f },  // step 18
   { -28.0f, -27.0f, 3.7f, 3.9f, 71.4f, 71.2f },  // step 19
   { -28.0f, -27.0f, 3.9f, 4.1f, 71.2f, 71.0f },  // step 20
   { -28.0f, -27.0f, 4.1f, 4.3f, 71.0f, 70.8f },  // step 21
   { -28.0f, -27.0f, 4.3f, 4.5f, 70.8f, 70.6f },  // step 22
   { -28.0f, -27.0f, 4.5f, 4.7f, 70.6f, 70.4f },  // step 23
   { -28.0f, -27.0f, 4.7f, 4.9f, 70.4f, 70.2f },  // step 24
   { -28.0f, -27.0f, 4.9f, 5.1f, 70.2f, 70.0f },  // step 25
   { -30.0f, -25.0f, 5.0f, 5.1f, 68.0f, 70.0f },  // small platform to stand on

   { -30.0f, -25.0f, 0.0f, 0.1f, 55.0f, 60.0f },  // jump for the win hehe



   // more big walls- i put them here in case you made this array order-dependant

    { 24.89f, 23.9f, -21.36f, 10.0f, 9.9f, 45.1f },

};

void drawTexturedCuboidL2(double xStart, double xEnd, double yStart, double yEnd, double zStart, double zEnd) {
    glDisable(GL_LIGHTING);

    glColor3f(0.6, 0.6, 0.6);

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, icetex.texture[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glPushMatrix();

    double centerX = (xStart + xEnd) / 2.0;
    double centerY = (yStart + yEnd) / 2.0;
    double centerZ = (zStart + zEnd) / 2.0;

    double scaleX = fabs(xEnd - xStart);
    double scaleY = fabs(yEnd - yStart);
    double scaleZ = fabs(zEnd - zStart);

    glTranslated(centerX, centerY, centerZ);
    glScaled(scaleX, scaleY, scaleZ);

    glBegin(GL_QUADS);

    double textureScaleX = 1.0;  
    double textureScaleY = 1.0;
    double textureScaleZ = 1.0;

    // Front face (zEnd)
    glNormal3f(0, 0, 1);
    glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(textureScaleX, 0); glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(textureScaleX, textureScaleY); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(0, textureScaleY); glVertex3f(-0.5, 0.5, 0.5);

    // Back face (zStart)
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(textureScaleX, 0); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(textureScaleX, textureScaleY); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(0, textureScaleY); glVertex3f(-0.5, 0.5, -0.5);

    // Left face (xStart)
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(textureScaleZ, 0); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(textureScaleZ, textureScaleY); glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(0, textureScaleY); glVertex3f(-0.5, 0.5, -0.5);

    // Right face (xEnd)
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(textureScaleZ, 0); glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(textureScaleZ, textureScaleY); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(0, textureScaleY); glVertex3f(0.5, 0.5, -0.5);

    // Top face (yEnd)
    glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(textureScaleX, 0); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(textureScaleX, textureScaleZ); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(0, textureScaleZ); glVertex3f(-0.5, 0.5, 0.5);

    // Bottom face (yStart)
    glNormal3f(0, -1, 0);
    glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(textureScaleX, 0); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(textureScaleX, textureScaleZ); glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(0, textureScaleZ); glVertex3f(-0.5, -0.5, 0.5);

    glEnd();

    glPopMatrix();

    glEnable(GL_LIGHTING);

    glColor3f(1, 1, 1);
}

void LoadAssetsL2()
{
    // Loading Model files

    // Remember in the Level2.cpp Display method to call their Draw function!
    // and in Level2Obstacles.h


    // sky box
    glPushMatrix();

    GLUquadricObj* qobj;
    qobj = gluNewQuadric();
    glTranslated(50, 0, 0);
    glRotated(90, 1, 0, 1);
    glBindTexture(GL_TEXTURE_2D, texL2);
    gluQuadricTexture(qobj, true);
    gluQuadricNormals(qobj, GL_SMOOTH);
    gluSphere(qobj, 100, 32, 16);
    gluDeleteQuadric(qobj);


    glPopMatrix();

    // Textures

    icetex.Load("Textures/snow.bmp");


    //checkpoint flags

    flag1L2.Load();
    flag1L2.SetPosition(42.0f, 2.1f, 37.0f);

    flag2L2.Load();
    flag2L2.SetPosition(28.0f, 2.1f, 82.0f);

    //flag3L2.Load();
    //flag3L2.SetPosition(-27.05, 2.2f, 46.34f);

    // collectibles

    coinsL2[0]->Load();
    coinsL2[0]->SetPosition(48.54f, 1.08f, -1.08);

    coinsL2[1]->Load();
    coinsL2[1]->SetPosition(49.3f, 0.1f, 50.22f);

    coinsL2[2]->Load();
    coinsL2[2]->SetPosition(11.4f, 1.0f, 81.76f);

    coinsL2[3]->Load();
    coinsL2[3]->SetPosition(42.02f, 0.1f, 41.56f);

    coinsL2[4]->Load();
    coinsL2[4]->SetPosition(-27.45f, 0.1f, 77.18f);


    // goal
    goalL2.Load();
    goalL2.SetPosition(-27.5, 0.5, 56.0);
    

    //dragon
    dinosaur.Load("Models/dinosaur/body.3ds");
    dinosaur.pos.x = 20.81;
    dinosaur.pos.y = 0.52;
    dinosaur.pos.z = 55.12;
    dinosaur.rot.y = 110;

    //torches

    //torchL2.Load("models/torch/candle.3ds");
    //torchL2.scale = 0.03;
    //torchL2.pos.x = 0.22;
    //torchL2.pos.y = 1.5;
    //torchL2.pos.z = 15.12;

    //torch2L2.Load("models/torch/candle.3ds");
    //torch2L2.scale = 0.03;
    //torch2L2.pos.x = 5.8;
    //torch2L2.pos.y = 1.5;
    //torch2L2.pos.z = 26.18;
    //torch2L2.rot.y = 180;

    //torch3L2.Load("models/torch/candle.3ds");
    //torch3L2.scale = 0.03;
    //torch3L2.pos.x = 0.23;
    //torch3L2.pos.y = 1.5;
    //torch3L2.pos.z = 35.9;

    //torch4L2.Load("models/torch/candle.3ds");
    //torch4L2.scale = 0.03;
    //torch4L2.pos.x = 0.54;
    //torch4L2.pos.y = 1.5;
    //torch4L2.pos.z = 49.88;
    //torch4L2.rot.y = 90;

    // Chandeliers
    for (int i = 0; i < 15; i++)
    { // final touches spread them out aktar ka y values
        float maxY = 10.0f;
        //float yInitial = (i * maxY) / 15.0f; // Initial Y position
        //float yInitial = (maxY * pow(5, i)) / 6103515625.0f;
        float yInitial = 2.0f * pow(2,(15 - i));
        //float initialSpeed = -1.0f * sqrt(2.0f * (-1.0f * fallAcceleration) * yInitial * deltaTime); // fallAcc is -ve inside sqrt so we get the magnitude and add the sign back later
        //printf("initial y: %f, speed: %f\n", yInitial, initialSpeed);
        //float initialSpeed = -(3.0f * (15-i)) / 15.0f;
        float initialSpeed = 0;
        chandeliers[i]->Load();
        chandeliers[i]->SetBoundaries(40.0f, 50.0f, 0.0f, maxY, 40.0f, 60.0f);
        chandeliers[i]->SetPosition(chandeliers[i]->GetPosX(), yInitial, chandeliers[i]->GetPosZ());
        chandeliers[i]->SetFallingSpeed(initialSpeed);
    }

    //drawSkybox();
}
