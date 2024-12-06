#pragma once
#ifndef LEVEL2_H
#define LEVEL2_H

#include "../../Common/CommonH/Vector3f.h"
#include <math.h>
#include "../../Common/CommonH/Camera.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../Common/CommonH/Player.h"
#include "../../Common/CommonH/Camera.h"
#include "../../Common/CommonH/Engine.h"
#include "../../Common/CommonH/Lighting.h"
#include "Level2Obstacles.h"
#include <glut.h>
#include <windows.h>
#include <mmsystem.h>

extern Vector3f spawnPoint0L2;
extern GLfloat spawnPoint0DirectionL2;
extern Vector3f spawnPoint1L2;
extern GLfloat spawnPoint1DirectionL2;
extern Vector3f spawnPoint2L2;
extern GLfloat spawnPoint2DirectionL2;
extern Vector3f spawnPoint3L2;
extern GLfloat spawnPoint3DirectionL2;

void DisplayL2();


#endif