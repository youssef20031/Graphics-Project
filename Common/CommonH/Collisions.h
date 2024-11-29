#pragma once

#include <glut.h>

bool checkCollision(GLfloat x1, GLfloat y1, GLfloat z1,
    GLfloat x2Start, GLfloat x2End,
    GLfloat y2Start, GLfloat y2End,
    GLfloat z2Start, GLfloat z2End);

bool isColliding(GLfloat deltaX, GLfloat deltaY, GLfloat deltaZ);
