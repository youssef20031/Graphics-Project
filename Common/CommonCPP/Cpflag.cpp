#include "../CommonH/Cpflag.h"

#include <glut.h>

Cpflag::Cpflag() {
    posX = 0.0f;
    posY = 0.0f;
    posZ = 0.0f;
    rotX = 0.0f;
    rotY = 180.0f;
    rotZ = 0.0f;
    scale = 0.005f;
  
}


void Cpflag::Load() {
    model.Load("Models/flag/flag^shtock_spktr.3ds");
}


void Cpflag::SetPosition(float x, float y, float z) {
    posX = x;
    posY = y;
    posZ = z;
}


void Cpflag::SetRotation(float x, float y, float z) {
    rotX = x;
    rotY = y;
    rotZ = z;
}

void Cpflag::SetScale(float s) {
    scale = s;
}



void Cpflag::Draw() {

    

    glPushMatrix();
    glTranslatef(posX, posY, posZ);
    glScalef(scale, scale, scale);
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
    model.Draw();
    glPopMatrix();
}
