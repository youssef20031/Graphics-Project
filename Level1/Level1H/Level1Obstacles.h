
#ifndef LEVEL1_OBSTACLES_H
#define LEVEL1_OBSTACLES_H


#include "Common/CommonH/Model_3DS.h"
#include "Axe.h"
#include <glut.h>


// Define the number of obstacles
const int L1numberOfObstacles = 100;

// Declare the external obstacles array
 extern GLfloat L1obstacles[L1numberOfObstacles][6];

 // Axe Obstacle
 extern Axe axe;
 extern Axe axe2;

 void LoadAssetsL1();

#endif // PLAYGROUND_OBSTACLES_H
