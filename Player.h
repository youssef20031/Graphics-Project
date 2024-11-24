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

// Function declarations
void updatePlayerRotation();    // Updates player's body rotation for animation
void drawCuboid(double xStart, double xEnd, double yStart, double yEnd, double zStart, double zEnd); // Draw a cuboid
void drawPlayer();              // Renders the player in the scene
void updatePlayerMovement();    // Handles player movement logic

