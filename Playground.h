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
#include "Engine.h"
#include "Lighting.h"
#include <glut.h>

// Constants
#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925)



// Lighting setup functions
void setupLights();

// Display function
void Display();


#endif // PLAYGROUND_H
