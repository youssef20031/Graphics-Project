
#ifndef LEVEL2_OBSTACLES_H
#define LEVEL2_OBSTACLES_H

#include "Common/CommonH/Model_3DS.h"
#include "../../Common/CommonH/Collisions.h"
#include "../../Common/CommonH/Player.h"
#include "../../Common/CommonH/Cpflag.h"
#include "../../Common/CommonH/Collectible.h"
#include "../../Common/CommonH/Goal.h"
#include "Chandelier.h"
#include "SnowBall.h"
#include <glut.h>

// Define the number of obstacles
const int L2numberOfObstacles = 100;

// Declare the external obstacles array
extern GLfloat L2obstacles[L2numberOfObstacles][6];

extern GLTexture rocktex;
extern GLuint texL2;

extern Cpflag flag1L2;
extern Cpflag flag2L2;
extern Cpflag flag3L2;

extern Collectible coin1L2;
extern Collectible coin2L2;
extern Collectible coin3L2;
extern Collectible coin4L2;
extern Collectible coin5L2;

extern Collectible* coinsL2[5];


extern Goal goalL2;

extern Model_3DS dinosaur;

extern Model_3DS torchL2;
extern Model_3DS torch2L2;
extern Model_3DS torch3L2;
extern Model_3DS torch4L2;

extern Model_3DS snowman;

// Chandelier
extern Chandelier chandelier1;
extern Chandelier chandelier2;
extern Chandelier chandelier3;
extern Chandelier chandelier4;
extern Chandelier chandelier5;
extern Chandelier chandelier6;
extern Chandelier chandelier7;
extern Chandelier chandelier8;
extern Chandelier chandelier9;
extern Chandelier chandelier10;
extern Chandelier chandelier11;
extern Chandelier chandelier12;
extern Chandelier chandelier13;
extern Chandelier chandelier14;
extern Chandelier chandelier15;

extern Chandelier* chandeliers[15];

// snowballs
extern SnowBall snowBall1;
extern SnowBall snowBall2;
extern SnowBall snowBall3;
extern SnowBall snowBall4;
extern SnowBall snowBall5;
extern SnowBall snowBall6;
extern SnowBall snowBall7;
extern SnowBall snowBall8;
extern SnowBall snowBall9;
extern SnowBall snowBall10;
extern SnowBall snowBall11;
extern SnowBall snowBall12;
extern SnowBall snowBall13;
extern SnowBall snowBall14;
extern SnowBall snowBall15;

extern SnowBall* snowBalls[15];


void drawTexturedCuboidL2(double xStart, double xEnd, double yStart, double yEnd, double zStart, double zEnd);
void drawTexturedCuboidL2Sliding(double xStart, double xEnd, double yStart, double yEnd, double zStart, double zEnd);
void drawTexturedCuboidL2BigWalls(double xStart, double xEnd, double yStart, double yEnd, double zStart, double zEnd);


void LoadAssetsL2();

#endif