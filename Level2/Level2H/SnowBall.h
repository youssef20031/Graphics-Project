#ifndef SnowBall_H
#define SnowBall_H

#include "Common/CommonH/Model_3DS.h"

class SnowBall {
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

    SnowBall();

    void Load();

    void SetPosition(float x, float y, float z);
    void SnowBall::SetBoundaries(float xStart, float xEnd, float yStart, float yEnd, float zStart, float zEnd);
    void SnowBall::SetFallingSpeed(float speed);
    void SnowBall::resetPosition();
    float SnowBall::getSideLength();

    void SetRotation(float rot);
    void SetRotationSpeed(float speed);

    float GetLength() const { return length; }
    float GetWidth() const { return width; }
    float GetHeight() const { return height; }
    float GetPosX() const { return posX; }
    float GetPosY() const { return posY; }
    float GetPosZ() const { return posZ; }
    float GetRot() const { return rot; }

    void SnowBall::SetScale(float s);
    void SetDimensions(float l, float w, float h);

    void Draw();
};

#endif
