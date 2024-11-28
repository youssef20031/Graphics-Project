#include "../Level1H/Level1Obstacles.h"


extern GLfloat L1obstacles[L1numberOfObstacles][6];


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
	{ -34.8, -60.35f, 0.1f, 0.2f, 46.87f, 49.44f }, // Stage 1 ground


};
