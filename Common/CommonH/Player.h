#pragma once
#include <math.h>
#include "stdio.h"
#include "Vector3f.h"
#include "Controls.h"
#include "Camera.h"
#include "../../Level1/Level1H/PlaygroundObstacles.h"
#include "../../Level1/Level1H/Level1Obstacles.h"
#include "../../Level1/Level1H/Level1.h"
#include "../../Common/CommonH/Engine.h"
#include <glut.h>

#pragma once

extern Model_3DS wolfplayermodel;

// Player properties
extern GLfloat playerX;
extern GLfloat playerY;
extern GLfloat playerZ;
extern GLfloat playerHeight;
extern GLfloat playerWidth;
extern GLfloat playerMovementSpeed;

extern GLfloat slidingSpeedX;
extern GLfloat slidingSpeedZ;
extern bool isMoving;
extern bool isSliding;

// Player rotation variables
extern GLfloat playerDirectionRotationFacing; // Direction player is facing
extern GLfloat playerDirectionRotationFacingVertical; // Direction player is facing up and down
extern GLfloat playerDirectionRotationFacingVerticalMin; 
extern GLfloat playerDirectionRotationFacingVerticalMax; 
extern GLfloat playerDirectionRotationBody;   // Direction player body is animating
extern GLfloat playerRotationAnimationSpeed;
extern GLfloat playerRotationSpeed;

// Movement state flags
extern bool rotatingLeft;
extern bool rotatingRight;
extern bool rotatingForward;
extern bool rotatingBack;

// Jumping Stuff
extern bool isPlayerJumping;
extern GLfloat playerVerticalSpeed;
extern GLfloat playerVerticalJumpInitialSpeed;

//checkpoint
extern Vector3f spawnPoint;
extern bool showCheckpointMessage;
extern float checkpointMessageStartTime;

extern int whichCp;

// Function declarations
void updatePlayerRotation();    // Updates player's body rotation for animation
void updatePlayerMovement();    // Handles player movement logic
void updatePlayerVerticalMovement();
bool updateFalling();
void drawCuboid(double xStart, double xEnd, double yStart, double yEnd, double zStart, double zEnd); // Draw a cuboid
void drawPlayer();              // Renders the player in the scene
void updateCheckpoint();
void updateWinLevel1();