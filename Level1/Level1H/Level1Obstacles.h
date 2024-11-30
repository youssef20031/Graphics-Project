
#ifndef LEVEL1_OBSTACLES_H
#define LEVEL1_OBSTACLES_H


#include "Common/CommonH/Model_3DS.h"
#include "../../Common/CommonH/Collisions.h"
#include "../../Common/CommonH/Player.h"
#include "Axe.h"
#include "../../Common/CommonH/Cpflag.h"
#include <glut.h>


// Define the number of obstacles
const int L1numberOfObstacles = 100;

// Declare the external obstacles array
 extern GLfloat L1obstacles[L1numberOfObstacles][6];

 // Axe Obstacle
 extern Axe axe;
 extern Axe axe2;
 extern Axe axe3;
 extern Axe axe4;
 extern Axe axe5;

extern Cpflag flag1;
extern Cpflag flag2;
extern Cpflag flag3;

extern GLTexture rocktex;

extern GLuint texL1;



 void drawTexturedCuboid(double xStart, double xEnd, double yStart, double yEnd, double zStart, double zEnd);
 void LoadAssetsL1();
 void drawSkybox();

#endif // PLAYGROUND_OBSTACLES_H
