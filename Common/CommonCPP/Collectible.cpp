#include "../CommonH/Collectible.h"

#include <glut.h>

Collectible::Collectible() {
    posX = 0.0f;
    posY = 0.0f;
    posZ = 0.0f;
    rotX = 0.0f;
    rotY = 0.0f;
    rotZ = 0.0f;
    scale = 0.3f;
    isCollected = false;

    rotationSpeed = 0.5f;
    maxRotation = 90.0f;
    minRotation = -90.0f;
    rotationDirection = 1;

}


void Collectible::Load() {
    model.Load("Models/coin/coin.3ds");
}


void Collectible::SetPosition(float x, float y, float z) {
    posX = x;
    posY = y;
    posZ = z;
}


void Collectible::SetRotation(float x, float y, float z) {
    rotX = x;
    rotY = y;
    rotZ = z;
}

void Collectible::SetScale(float s) {
    scale = s;
}



void Collectible::Draw() {

    if (isCollected)
        return;

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
