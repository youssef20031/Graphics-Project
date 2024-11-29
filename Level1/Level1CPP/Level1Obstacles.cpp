#include "../Level1H/Level1Obstacles.h"


extern GLfloat L1obstacles[L1numberOfObstacles][6];


Axe axe;
Axe axe2;
Axe axe3;
Axe axe4;
Axe axe5;


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

	
	{ -23.02, -23.35f, 0.1f, 0.2f, 50.97f, 45.09f }, // checkpoint platform
	{ -32.8, -70.35f, 0.1f, 0.2f, 46.87f, 49.44f }, // Stage 1 ground
    //.. incomplete (handle collision of axe with player by setting player back to spawn/checkpoint)


    // PLATFORMING SECTION (STAGE 2)

    { -70.36, -80.35f, 0.1f, 0.2f, 52.87f, 42.44f }, // stage 2 ground
    { -73.45, -73.5f, 0.2f, 0.3f, 53.25f, 42.2f }, // checkpoint platform stage 2
    { -82.45, -84.7f, -2.0f, 0.3f, 50.25f, 51.2f }, // platform 1
    { -86.45, -87.7f, -2.0f, 0.3f, 48.25f, 49.2f }, // platform 2
    { -91.45, -92.7f, -2.0f, 0.3f, 46.25f, 47.2f }, // platform 3
    { -91.45, -92.7f, -2.0f, 0.3f, 46.25f, 47.2f }, // platform 4






};

void LoadAssetsL1()
{
    // Loading Model files

    // Remember in the Level1.cpp Display method to call their Draw function!
    // and in Level1Obstacles.h

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


    
}
