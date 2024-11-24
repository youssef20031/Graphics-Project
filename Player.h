#pragma once
#include <math.h>
#include "stdio.h"
#include "Vector3f.h"
#include "Controls.h"
#include "Camera.h"
#include <glut.h>

#pragma once

// Player properties
extern GLfloat playerX;
extern GLfloat playerY;
extern GLfloat playerZ;
extern GLfloat playerHeight;
extern GLfloat playerWidth;
extern GLfloat playerMovementSpeed;

// Player rotation variables
extern GLfloat playerDirectionRotationFacing; // Direction player is facing
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
extern GLfloat fallAcceleration; // e3tebro gravity

const int numberOfObstacles = 7;
extern GLfloat obstacles[numberOfObstacles][6];

// Function declarations
void updatePlayerRotation();    // Updates player's body rotation for animation
void updatePlayerMovement();    // Handles player movement logic
void updatePlayerVerticalMovement();
bool updateFalling();
bool checkCollision(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2Start, GLfloat x2End, GLfloat y2Start, GLfloat y2End, GLfloat z2Start, GLfloat z2End);
bool isColliding(GLfloat deltaX, GLfloat deltaY, GLfloat deltaZ);
void drawCuboid(double xStart, double xEnd, double yStart, double yEnd, double zStart, double zEnd); // Draw a cuboid
void drawPlayer();              // Renders the player in the scene