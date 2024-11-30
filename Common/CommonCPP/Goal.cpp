#include "../CommonH/Goal.h"

#include <glut.h>

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
    rotY -= rotationSpeed * rotationDirection;

    glTranslatef(posX, posY, posZ);
    glScalef(scale, scale, scale);
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
    model.Draw();
    glPopMatrix();
}
