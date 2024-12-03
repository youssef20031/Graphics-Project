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

Model_3DS dragonL2;

Model_3DS torchL2;
Model_3DS torch2L2;
Model_3DS torch3L2;
Model_3DS torch4L2;

// obstacles
GLfloat L2obstacles[L2numberOfObstacles][6] = {

    // CAVE SECTION (STAGE 0)

   { -5.0f, 25.0f, 0.0f, 0.1f, -10.0f, 10.0f },  // cave ground
   { -5.0f, 25.0f, 3.0f, 3.1f, -10.0f, 10.0f },  // cave roof
   { -5.0f, -5.1f, 0.0f, 3.0f, -10.0f, 10.0f },   // cave back wall
   { -5.0f, 25.0f, 0.0f, 3.0f, -10.0f, -10.1f },   // cave left wall
   { -5.0f, 25.0f, 0.0f, 3.0f, 10.0f, 10.1f },   // cave right wall
   { 25.0f, 25.1f, 0.0f, 3.0f, -10.0f, -2.0f },   // cave front left wall
   { 25.0f, 25.1f, 0.0f, 3.0f, 10.0f, 2.0f },   // cave front right wall
   //{ 3.0f, 6.0f, 0.0f, 3.0f, 15.0f, 16.0f }, // cave middle wall 1
   //{ 0.0f, 3.0f, 0.0f, 3.0f, 25.0f, 26.0f }, // cave middle wall 2
   //{ 2.0f, 9.0f, 0.0f, 3.0f, 35.0f, 36.0f }, // cave middle wall 3


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

    double textureScaleX = scaleX * 1.3;     //can be masalan 1.5,1.2,1.8  -- experiment with values
    double textureScaleY = scaleY * 1.7;
    double textureScaleZ = scaleZ * 1.2;

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

    icetex.Load("Textures/rockwall3.bmp");


    //checkpoint flags

    flag1L2.Load();
    flag1L2.SetPosition(-144.63f, 6.2f, 43.75f);

    flag2L2.Load();
    flag2L2.SetPosition(-76.34, 2.2f, 45.56f);

    flag3L2.Load();
    flag3L2.SetPosition(-27.05, 2.2f, 46.34f);

    // collectibles

    coinsL2[0]->Load();
    coinsL2[0]->SetPosition(-178.21f, 4.3f, 37.28f);

    coinsL2[1]->Load();
    coinsL2[1]->SetPosition(-92.07f, 0.4f, 46.73f);

    coinsL2[2]->Load();
    coinsL2[2]->SetPosition(4.64f, 0.2f, 17.19f);

    coinsL2[3]->Load();
    coinsL2[3]->SetPosition(-45.97f, 0.3f, 48.12f);

    coinsL2[4]->Load();
    coinsL2[4]->SetPosition(-192.63f, 4.2f, 56.22f);


    // goal
    goalL2.Load();
    goalL2.SetPosition(-237.8, 10.5, 56.96);

    //dragon
    dragonL2.Load("Models/dragon/Drachen_1.0_3ds.3ds");
    dragonL2.pos.x = -90.51;
    dragonL2.pos.y = 0.2;
    dragonL2.pos.z = 70.12;
    dragonL2.rot.y = 110;

    //torches

    torchL2.Load("models/torch/candle.3ds");
    torchL2.scale = 0.03;
    torchL2.pos.x = 0.22;
    torchL2.pos.y = 1.5;
    torchL2.pos.z = 15.12;

    torch2L2.Load("models/torch/candle.3ds");
    torch2L2.scale = 0.03;
    torch2L2.pos.x = 5.8;
    torch2L2.pos.y = 1.5;
    torch2L2.pos.z = 26.18;
    torch2L2.rot.y = 180;

    torch3L2.Load("models/torch/candle.3ds");
    torch3L2.scale = 0.03;
    torch3L2.pos.x = 0.23;
    torch3L2.pos.y = 1.5;
    torch3L2.pos.z = 35.9;

    torch4L2.Load("models/torch/candle.3ds");
    torch4L2.scale = 0.03;
    torch4L2.pos.x = 0.54;
    torch4L2.pos.y = 1.5;
    torch4L2.pos.z = 49.88;
    torch4L2.rot.y = 90;

    //drawSkybox();
}
