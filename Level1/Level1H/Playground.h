#pragma once
#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include "../../Common/CommonH/Vector3f.h"
#include <math.h>
#include "../../Common/CommonH/Camera.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../Common/CommonH/Player.h"
#include "../../Common/CommonH/Camera.h"
#include "../../Common/CommonH/Engine.h"
#include "../../Common/CommonH/Lighting.h"
#include <glut.h>

// Constants
#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925)



// Lighting setup functions
//void setupLights();

// Display function
void Display();


#endif // PLAYGROUND_H
