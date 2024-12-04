#include "../Level2H/Chandelier.h"
#include "Common/CommonH/Engine.h"

#include <glut.h>

Chandelier::Chandelier() {
    boundaryStartX = 0.0f;
    boundaryEndX = 0.0f;
    boundaryStartY = 0.0f;
    boundaryEndY = 0.0f;
    boundaryStartZ = 0.0f;
    boundaryEndZ = 0.0f;

    posX = 0.0f;
    posY = 0.0f;
    posZ = 0.0f;
    rot = 0.0f;
    scale = 0.003f;

    rotationSpeed = 0.5f;  
    rotationDirection = 1;

    fallingSpeed = 0.0f;

    width = 2.0f;   
    length = 2.0f;
    height = 6.0f;     
}


void Chandelier::Load() {
    model.Load("Models/chandelier/chandelier.3ds");
}


void Chandelier::SetPosition(float x, float y, float z) {
    posX = x;
    posY = y;
    posZ = z;
}

float Chandelier::getSideLength() {
    return scale * 333.33f;
}

void Chandelier::SetBoundaries(float xStart, float xEnd, float yStart, float yEnd, float zStart, float zEnd) {
    boundaryStartX = xStart;
    boundaryEndX = xEnd;
    boundaryStartY = yStart;
    boundaryEndY = yEnd;
    boundaryStartZ = zStart;
    boundaryEndZ = zEnd;
}

void Chandelier::SetFallingSpeed(float speed) {
    fallingSpeed = speed;
}

void Chandelier::SetDimensions(float l, float w, float h) {
    length = h;
    width = w;
    height = h;
}


void Chandelier::SetRotation(float rot) {
    rot = rot;
}

void Chandelier::SetScale(float s) {
    scale = s;
}

void Chandelier::SetRotationSpeed(float speed) {
    rotationSpeed = speed;
}

void Chandelier::resetPosition() {
    float minY = boundaryStartY;
    float maxY = boundaryEndY;

    if (boundaryStartY > boundaryEndY) {
        minY = boundaryEndY;
        maxY = boundaryStartY;
    }

    // generate new X, Z coordinates inside X, Z boundaries when reaches minY
    if (posY <= minY) {
        float minX = boundaryStartX;
        float maxX = boundaryEndX;
        float minZ = boundaryStartZ;
        float maxZ = boundaryEndZ;

        if (boundaryStartX > boundaryEndX) {
            minX = boundaryEndX;
            maxX = boundaryStartX;
        }
        if (boundaryStartZ > boundaryEndZ) {
            minZ = boundaryEndZ;
            maxZ = boundaryStartZ;
        }

        float randomFloatX = minX + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxX - minX)));
        float randomFloatZ = minZ + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxZ - minZ)));

        fallingSpeed = 0.0f;
        SetPosition(randomFloatX, maxY, randomFloatZ);
    }
}

void Chandelier::Draw() {
    // checks if chandelier has to reset position and resets it if it has to
    resetPosition();

    // make chandelier fall
    fallingSpeed += fallAcceleration * deltaTime;
    SetPosition(posX, posY + fallingSpeed, posZ);

    rot += rotationSpeed * rotationDirection;
    glPushMatrix();
    glTranslatef(posX, posY, posZ); 
    /// Rotation animation
    glRotatef(rot, 0.0f, 1.0f, 0.0f);
    glScalef(scale, scale, scale);
    model.Draw();

    glPopMatrix();
}
