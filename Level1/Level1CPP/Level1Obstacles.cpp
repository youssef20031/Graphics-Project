#include "../Level1H/Level1Obstacles.h"
#include <iostream>
#include <cmath>  
#include <cstdlib>




extern GLfloat L1obstacles[L1numberOfObstacles][6];


Axe axe;
Axe axe2;
Axe axe3;
Axe axe4;
Axe axe5;

Axe* axes[5] = {
    &axe,
    &axe2,
    &axe3,
    &axe4,
    &axe5
};


GLTexture rocktex;
GLTexture lavatex;
GLuint texL1;

Cpflag flag1;
Cpflag flag2;
Cpflag flag3;

Collectible coin1;
Collectible coin2;
Collectible coin3;
Collectible coin4;
Collectible coin5;

Collectible* coins[5] = {
    &coin1,
    &coin2,
    &coin3,
    &coin4,
    &coin5
};

Goal goal;

Model_3DS barrel;

Model_3DS dragon;

Model_3DS torch;
Model_3DS torch2;
Model_3DS torch3;
Model_3DS torch4;


// obstacles
GLfloat L1obstacles[L1numberOfObstacles][6] = {

	// CAVE SECTION (STAGE 0)

   { 0.0f, 6.0f, 0.0f, 0.1f, 0.0f, 51.0f },  // cave ground
   { 0.0f, 0.1f, 0.0f, 3.0f, 0.0f, 45.0f },  // cave right wall
   { 5.9f, 6.0f, 0.0f, 3.0f, 0.0f, 51.0f },  // cave left wall
   { 0.0f, 6.0f, 0.0f, 3.0f, 0.0f, 0.1f },   // cave back wall
   { 0.0f, 6.0f, 3.0f, 3.1f, 0.0f, 51.0f },  // cave roof
   { 3.0f, 6.0f, 0.0f, 3.0f, 15.0f, 16.0f }, // cave middle wall 1
   { 0.0f, 3.0f, 0.0f, 3.0f, 25.0f, 26.0f }, // cave middle wall 2
   { 2.0f, 9.0f, 0.0f, 3.0f, 35.0f, 36.0f }, // cave middle wall 3

   { 6.0f, -15.0f, 0.0f, 3.0f, 50.0f, 51.0f }, // left side wall turning right
   { 0.1f, -15.0f, 0.0f, 3.0f, 45.0f, 46.0f },  // right side wall turning right
   { 0.0f, -35.0f, 0.0f, 0.1f, 45.0f, 51.0f },  // cave ground 2
   { 0.0f, -15.0f, 3.0f, 3.1f, 45.0f, 51.0f }, // cave roof 2
   { -7.48, -8.41f, 0.1f, 0.6f, 49.9f, 46.14f }, // small platform to jump 


   // AXE SECTION (STAGE 1)

	
	{ -23.02, -23.35f, 0.1+200.0f, 0.2+200.0f, 50.97f, 45.09f }, // checkpoint platform   i=13
	{ -32.8, -70.35f, 0.1f, 0.2f, 46.87f, 48.44f }, // Stage 1 ground


    // PLATFORMING SECTION (STAGE 2)

    { -70.36, -80.35f, 0.1f, 0.2f, 52.87f, 42.44f }, // stage 2 ground
    { -73.45, -73.5f, 0.2+200.0f, 0.3+200.0f, 53.25f, 42.2f }, // checkpoint platform stage 2   i=16
    { -82.45, -84.7f, -2.0f, 0.3f, 50.25f, 51.2f }, // platform 1
    { -86.45, -87.7f, -2.0f, 0.3f, 48.25f, 49.2f }, // platform 2
    { -91.45, -92.7f, -2.0f, 0.3f, 46.25f, 47.2f }, // platform 3
    { -91.45, -92.7f, -2.0f, 0.3f, 46.25f, 47.2f }, // platform 4
    { -88.45, -89.7f, -2.0f, 0.6f, 50.25f, 51.2f }, // platform 4
    { -93.45, -94.7f, -2.0f, 0.8f, 49.25f, 50.2f }, // platform 4

    { -97.45, -98.7f, 0.5f, 1.0f, 47.25f, 48.2f }, // platform 5
    { -102.45, -103.7f, 1.3f, 1.8f, 46.15f, 47.1f }, // platform 6
    { -107.45, -108.7f, 2.3f, 2.6f, 45.0f, 46.0f }, // platform 7
    { -112.45, -113.7f, 2.9f, 3.4f, 43.9f, 44.8f }, // platform 8
    { -117.45, -118.7f, 3.7f, 4.1f, 42.8f, 43.7f }, // platform 9

    { -122.45, -123.7f, 3.7f, 4.1f, 42.8f, 43.7f }, // platform 10
    { -127.45, -128.7f, 3.7f, 4.1f, 42.8f, 43.7f }, // platform 11
    { -133.36, -150.35f, 4.1f, 4.2f, 42.87f, 47.44f }, // stage 2 exit ground


    // INVISIBLE PLATFORM SECTION (STAGE 3)
    { -141.78, -141.96, 4.2+200.0f, 4.3+200.0f, 47.54f, 42.92f }, // checkpoint platform stage 3   i=31
   
    { -153.45, -176.7f, 3.7f, 4.1f, 44.8f, 45.7f }, // invisible platform 1 i=32
    { -177.45, -178.7f, 3.7f, 4.1f, 44.8f, 54.7f }, // invisible platform 2 i=33
    { -178.45, -186.7f, 3.7f, 4.1f, 55.8f, 56.7f }, // invisible platform 3 i=34  
    { -177.45, -178.7f, 3.7f, 4.1f, 40.8f, 36.7f }, // invisible platform 3 i=35   one of the coins will be placed there
    { -190.45, -195.7f, 3.7f, 4.1f, 55.8f, 56.7f }, // normal platform
    { -198.45, -199.7f, 3.7f, 4.1f, 55.8f, 56.7f }, // moving platform (upwards) i=37
    { -201.45, -202.7f, 9.5f, 9.9f, 55.8f, 56.7f }, // platform
    { -204.450, -205.7f, 9.5f, 9.9f, 55.8f, 56.7f }, // moving platform (horizontal) i=39
    


    // VICTORY PLATFORM
     

{ -240.7f, -230.45f, 9.5f, 9.7f, 45.8f, 70.7f },  // Ground

{ -240.9f, -240.5f, 9.5f, 16.5f, 45.9f, 70.8f },  // Back Wall

{ -240.7f, -230.45f, 9.5f, 16.5f, 45.8f, 46.0f },  // Right Wall

{ -240.7f, -230.45f, 9.5f, 16.5f, 70.6f, 70.8f },  // Left Wall

{ -240.7f, -230.45f, 16.5f, 16.7f, 45.8f, 70.7f },  // Roof




    // Checkpoint Model Collisions
   
    
    // Stage 3 checkpoint i=45
    { -144.63f, -144.85f, 4.2f, 8.2f, 43.4f, 43.8f },
    
    // Stage 2 checkpoint i=46
    { -76.34f, -76.54, 0.2f, 4.2f, 45.56f, 45.0f }, 

    // Stage 1 checkpoint i=47
    { -27.05f, -27.25, 0.2f, 4.2f, 46.34f, 45.8f },

    // Barrel Model Collision  i=48

    { -79.81f, -79.0, 0.2f, 1.2f, 51.7f, 52.5f },


    // Dragon Platform i=49

    { -60.69f, -97.32, -11.1+1000.0f, -50.5f+1000.0, 50.41f, 80.45f },


    // lava floor i=50
   {-300,80,-21,-23,100,-100}

    


    




};

void drawTexturedCuboid(double xStart, double xEnd, double yStart, double yEnd, double zStart, double zEnd) {

    glColor3f(0.6, 0.6, 0.6);

    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, rocktex.texture[0]);

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

    double textureScaleX = scaleX*1.3;     //can be masalan 1.5,1.2,1.8  -- experiment with values
    double textureScaleY = scaleY*1.7;
    double textureScaleZ = scaleZ*1.2; 

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


void drawLavaCuboid(double xStart, double xEnd, double yStart, double yEnd, double zStart, double zEnd) {
    glDisable(GL_LIGHTING);

    glColor3f(0.6, 0.6, 0.6);

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, lavatex.texture[0]);

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


void drawSkybox() {
    glPushMatrix();

    glTranslatef(playerX, playerY, playerZ);

    glRotatef(90, 1, 0, 1);

    glBindTexture(GL_TEXTURE_2D, texL1);

    GLUquadricObj* qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);
    gluQuadricNormals(qobj, GL_SMOOTH);
    gluSphere(qobj, 100.0, 32, 16);
    gluDeleteQuadric(qobj);

    glPopMatrix();
}


void configureTorchLight(GLenum light, float x, float y, float z, float time) {
    GLfloat base_diffuse[] = { 1.0f, 0.5f, 0.0f, 1.0f }; 
    GLfloat base_specular[] = { 1.0f, 0.5f, 0.0f, 1.0f };
    GLfloat base_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 

    if (level == 2) {  // blue light
        base_diffuse[0] = 0.0f;
        base_diffuse[1] = 0.5f;
        base_diffuse[2] = 1.0f;
        base_specular[0] = 0.0f;
        base_specular[1] = 0.5f;
        base_specular[2] = 1.0f;
    }

    float flickerAmplitude = 0.2f;  
    float flickerSpeed = 3.0f;         


     float flicker = 1.0f + flickerAmplitude * ((float)rand() / RAND_MAX * 2.0f - 1.0f);

    GLfloat dynamic_diffuse[] = { base_diffuse[0] * flicker, base_diffuse[1] * flicker, base_diffuse[2] * flicker, base_diffuse[3] };
    GLfloat dynamic_specular[] = { base_specular[0] * flicker, base_specular[1] * flicker, base_specular[2] * flicker, base_specular[3] };

    GLfloat light_position[] = { x, y, z, 1.0f }; 

   
    GLfloat constant_attenuation = 1.0f;
    GLfloat linear_attenuation = 0.1f;
    GLfloat quadratic_attenuation = 0.05f;

    glLightfv(light, GL_POSITION, light_position);
    glLightfv(light, GL_DIFFUSE, dynamic_diffuse);
    glLightfv(light, GL_SPECULAR, dynamic_specular);
    glLightfv(light, GL_AMBIENT, base_ambient);

    glLightf(light, GL_CONSTANT_ATTENUATION, constant_attenuation);
    glLightf(light, GL_LINEAR_ATTENUATION, linear_attenuation);
    glLightf(light, GL_QUADRATIC_ATTENUATION, quadratic_attenuation);

    glEnable(light);
}





void LoadAssetsL1()
{
    // Loading Model files

    // Remember in the Level1.cpp Display method to call their Draw function!
    // and in Level1Obstacles.h


    // sky box
    glPushMatrix();

    GLUquadricObj* qobj;
    qobj = gluNewQuadric();
    glTranslated(50, 0, 0);
    glRotated(90, 1, 0, 1);
    glBindTexture(GL_TEXTURE_2D, texL1);
    gluQuadricTexture(qobj, true);
    gluQuadricNormals(qobj, GL_SMOOTH);
    gluSphere(qobj, 100, 32, 16);
    gluDeleteQuadric(qobj);


    glPopMatrix();

    

    // Axes

    axe.Load();
    axe.SetPosition(-38.45f, 0.3f, 51.3f);
    axe.SetRotation(90.0f, 0.0f, -90.0f);
    axe.SetRotationSpeed(0.5f);  
    axe.SetRotationLimits(-90.0f, 90.0f);

    axe2.Load();
    axe2.SetPosition(-43.45f, 0.6f, 51.3f);
    axe2.SetRotation(90.0f, 0.0f, -90.0f);
    axe2.SetRotationSpeed(0.75f);
    axe2.SetRotationLimits(-90.0f, 90.0f);

    axe3.Load();
    axe3.SetPosition(-49.45f, 0.6f, 51.3f);
    axe3.SetRotation(90.0f, 0.0f, -90.0f);
    axe3.SetRotationSpeed(0.6f);
    axe3.SetRotationLimits(-90.0f, 90.0f);

    axe4.Load();
    axe4.SetPosition(-54.45f, 0.6f, 51.3f);
    axe4.SetRotation(90.0f, 0.0f, -90.0f);
    axe4.SetRotationSpeed(0.68f);
    axe4.SetRotationLimits(-90.0f, 90.0f);

    axe5.Load();
    axe5.SetPosition(-59.45f, 0.6f, 51.3f);
    axe5.SetRotation(90.0f, 0.0f, -90.0f);
    axe5.SetRotationSpeed(0.8f);
    axe5.SetRotationLimits(-90.0f, 90.0f);

    // Textures

    rocktex.Load("Textures/rockwall3.bmp");
    lavatex.Load("Textures/lava.bmp");

    // Player model

    wolfplayermodel.Load("Models/wolf/balto.3ds");
    wolfplayermodel.scale = 0.4;


    //checkpoint flags
  
    flag1.Load();
    flag1.SetPosition(-144.63f, 6.2f, 43.75f);
    
    flag2.Load();
    flag2.SetPosition(-76.34,2.2f, 45.56f);

    flag3.Load();
    flag3.SetPosition(-27.05, 2.2f, 46.34f);

  



    // collectibles


    coins[0]->Load();
    coins[0]->SetPosition(-178.21f, 4.3f, 37.28f);

    coins[1]->Load();
    coins[1]->SetPosition(-92.07f, 0.4f, 46.73f);

    coins[2]->Load();
    coins[2]->SetPosition(4.64f, 0.2f, 17.19f);

    coins[3]->Load();
    coins[3]->SetPosition(-45.97f, 0.3f, 48.12f);

    coins[4]->Load();
    coins[4]->SetPosition(-192.63f, 4.2f, 56.22f);


    // goal
    goal.Load();
    goal.SetPosition(-237.8,10.5,56.96);


    // barrel
    barrel.Load("Models/barrel/ton3_low.3ds");
    barrel.pos.x = -79.51;
    barrel.pos.y = 0.2;
    barrel.pos.z = 51.88;
    barrel.scale = 1;

    //dragon
    dragon.Load("Models/dragon/Drachen_1.0_3ds.3ds");
    dragon.pos.x = -90.51;
    dragon.pos.y = 3.2;
    dragon.pos.z = 70.12;
    dragon.rot.y = 110;

    //torches

    torch.Load("models/torch/candle.3ds");
    torch.scale = 0.03;
    torch.pos.x = 0.22;
    torch.pos.y = 1.5;
    torch.pos.z = 15.12;

    torch2.Load("models/torch/candle.3ds");
    torch2.scale = 0.03;
    torch2.pos.x = 5.8;
    torch2.pos.y = 1.5;
    torch2.pos.z = 26.18;
    torch2.rot.y = 180;

    torch3.Load("models/torch/candle.3ds");
    torch3.scale = 0.03;
    torch3.pos.x = 0.23;
    torch3.pos.y = 1.5;
    torch3.pos.z = 35.9;

    torch4.Load("models/torch/candle.3ds");
    torch4.scale = 0.03;
    torch4.pos.x = 0.54;
    torch4.pos.y = 1.5;
    torch4.pos.z = 49.88;
    torch4.rot.y = 90;



    
    
    


    //drawSkybox();



   



    
}
