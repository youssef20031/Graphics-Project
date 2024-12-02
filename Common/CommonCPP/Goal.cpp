#include "../CommonH/Goal.h"

#include <glut.h>
#include <cmath>

Goal::Goal() {
    posX = 0.0f;
    posY = 0.0f;
    posZ = 0.0f;
    rotX = 0.0f;
    rotY = 0.0f;
    rotZ = 0.0f;
    scale = 0.3f;

    rotationSpeed = 0.5f;
    maxRotation = 90.0f;
    minRotation = -90.0f;
    rotationDirection = 1;

    minScale = 0.2f;   
    maxScale = 0.4f;    
    scaleSpeed = 0.002f; 
    scalingDirection = 1;

}


void Goal::Load() {
    model.Load("Models/goal/shiled.3ds");
}


void Goal::SetPosition(float x, float y, float z) {
    posX = x;
    posY = y;
    posZ = z;
}


void Goal::SetRotation(float x, float y, float z) {
    rotX = x;
    rotY = y;
    rotZ = z;
}

void Goal::SetScale(float s) {
    scale = s;
}



void Goal::Draw() {
    glPushMatrix();

    model.rot.y = 90;
    scale += scaleSpeed * scalingDirection;

    if (scale >= maxScale) {
        scale = maxScale;
        scalingDirection = -1; 
    }
    else if (scale <= minScale) {
        scale = minScale;
        scalingDirection = 1;  
    }

    glTranslatef(posX, posY, posZ);
    glScalef(scale, scale, scale);

    
    model.Draw();

    glPopMatrix();
}


