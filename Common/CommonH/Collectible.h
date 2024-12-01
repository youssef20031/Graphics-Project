#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include "Model_3DS.h"

class Collectible {
public:
    Model_3DS model;
    float posX, posY, posZ;
    float rotX, rotY, rotZ;
    float scale;
    float rotationSpeed;
    float maxRotation;
    float minRotation;
    int rotationDirection;
    bool isCollected;

    Collectible();

    void Load();

    void SetPosition(float x, float y, float z);

    void SetRotation(float x, float y, float z);



    float GetPosX() const { return posX; }
    float GetPosY() const { return posY; }
    float GetPosZ() const { return posZ; }
    float GetRotX() const { return rotX; }
    float GetRotY() const { return rotY; }
    float GetRotZ() const { return rotZ; }
    bool IsCollected() const { return isCollected; }
    void Collect() { isCollected = true; }


    void Collectible::SetScale(float s);





    void Draw();
};

#endif
