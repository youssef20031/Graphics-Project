#include "../Level1H/Level1Obstacles.h"


extern GLfloat L1obstacles[L1numberOfObstacles][6];


// obstacles
GLfloat L1obstacles[L1numberOfObstacles][6] = {
   { 0.0f, 6.0f, 0.0f, 0.1f, 0.0f, 51.0f },  // cave ground
   { 0.0f, 0.1f, 0.0f, 3.0f, 0.0f, 45.0f },  // cave right wall
   { 5.9f, 6.0f, 0.0f, 3.0f, 0.0f, 51.0f },  // cave left wall
   { 0.0f, 6.0f, 0.0f, 3.0f, 0.0f, 0.1f },   // cave back wall
   { 0.0f, 6.0f, 3.0f, 3.1f, 0.0f, 51.0f },  // cave roof
   { 3.0f, 6.0f, 0.0f, 3.0f, 15.0f, 16.0f }, // cave middle wall 1
   { 0.0f, 3.0f, 0.0f, 3.0f, 25.0f, 26.0f }, // cave middle wall 2

   { 6.0f, -15.0f, 0.0f, 3.0f, 50.0f, 51.0f }, // left side wall turning right
   { 0.1f, -15.0f, 0.0f, 3.0f, 45.0f, 46.0f },  // right side wall turning right
   { 0.0f, -15.0f, 0.0f, 0.1f, 45.0f, 51.0f },  // cave ground
};
