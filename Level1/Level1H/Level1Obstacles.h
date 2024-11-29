
#ifndef LEVEL1_OBSTACLES_H
#define LEVEL1_OBSTACLES_H


#include "Common/CommonH/Model_3DS.h"
#include <glut.h>

extern Model_3DS model_axe;


// Define the number of obstacles
const int L1numberOfObstacles = 100;

// Declare the external obstacles array
 extern GLfloat L1obstacles[L1numberOfObstacles][6];

#endif // PLAYGROUND_OBSTACLES_H
