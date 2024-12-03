#pragma once


#include "Player.h"
#include "../../Level1/Level1H/Axe.h"
#include "../CommonH/Collectible.h"
#include <glut.h>

#include <windows.h>
#include <mmsystem.h>


bool checkCollision(GLfloat x1, GLfloat y1, GLfloat z1,
    GLfloat x2Start, GLfloat x2End,
    GLfloat y2Start, GLfloat y2End,
    GLfloat z2Start, GLfloat z2End);

bool isColliding(GLfloat deltaX, GLfloat deltaY, GLfloat deltaZ);

void handleAxeCollision(Axe& axe);

bool checkAxeCollision(Axe& axe);

void handleMovingPlatformHorizontal();

void handleCoinCollision(Collectible& coin);

// level 2 stuff

void handleSlipperyFloor();
