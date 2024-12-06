#ifndef Chandelier_H
#define Chandelier_H

#include "Common/CommonH/Model_3DS.h"

class Chandelier {
public:
    Model_3DS model;  

    float boundaryStartX, boundaryEndX, boundaryStartY, boundaryEndY, boundaryStartZ, boundaryEndZ;

    float posX, posY, posZ; 
    float rot;
    float scale;  
    float rotationSpeed;
    int rotationDirection;
    float fallingSpeed;
    float length, width, height;
   
    Chandelier();

    void Load();

    void SetPosition(float x, float y, float z);
    void Chandelier::SetBoundaries(float xStart, float xEnd, float yStart, float yEnd, float zStart, float zEnd);
    void Chandelier::SetFallingSpeed(float speed);
    void Chandelier::resetPosition();
    float Chandelier::getSideLength();

    void SetRotation(float rot);
    void SetRotationSpeed(float speed);

    float GetLength() const { return length; }
    float GetWidth() const { return width; }
    float GetHeight() const { return height; }
    float GetPosX() const { return posX; }
    float GetPosY() const { return posY; }
    float GetPosZ() const { return posZ; }
    float GetRot() const { return rot; }

    void Chandelier::SetScale(float s);
    void SetDimensions(float l, float w, float h);

    void Chandelier::drawXMark();
    void Draw();
};

#endif
