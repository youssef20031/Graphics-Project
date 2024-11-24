#pragma once
#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include "Vector3f.h"
#include <math.h>
#include "Camera.h"
#include <stdio.h>
#include <stdlib.h>
#include "Player.h"
#include "Controls.h"
#include <glut.h>

// Constants
#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925)



// Lighting setup functions
void setupLights();

// Camera setup function
void setupCamera();

// Display function
void Display();

// Keyboard and special key functions
void Keyboard(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void Special(int key, int x, int y);
void SpecialUp(int key, int x, int y);

void updateStates();
void updateCameraMovement();
void updatePlayerMovement();

#endif // PLAYGROUND_H
