#include "../Level1H/Axe.h"

#include <glut.h>

Axe::Axe() {
    posX = 0.0f;
    posY = 0.0f;
    posZ = 0.0f;
    rotX = 0.0f;
    rotY = 0.0f;
    rotZ = 0.0f;
    scale = 0.5f;  
}


void Axe::Load() {
    model.Load("Models/axe/untitled.3ds");
}


void Axe::SetPosition(float x, float y, float z) {
    posX = x;
    posY = y;
    posZ = z;
}


void Axe::SetRotation(float x, float y, float z) {
    rotX = x;
    rotY = y;
    rotZ = z;
}


void Axe::Draw() {
    glPushMatrix();
    glTranslatef(posX, posY, posZ); 
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);  
    glRotatef(rotZ, 0.0f, 0.0f, 1.0f); 
    model.Draw();
    glPopMatrix();
}
