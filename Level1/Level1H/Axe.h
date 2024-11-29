#ifndef AXE_H
#define AXE_H

#include "Common/CommonH/Model_3DS.h"

class Axe {
public:
    Model_3DS model;  
    float posX, posY, posZ; 
    float rotX, rotY, rotZ;  
    float scale;  
    float rotationSpeed;
    float maxRotation;
    float minRotation;
    int rotationDirection;
    float width, height,depth;

   
    Axe();

    void Load();

    void SetPosition(float x, float y, float z);

    void SetRotation(float x, float y, float z);


    void SetRotationSpeed(float speed);

    void SetRotationLimits(float min, float max);

    float GetWidth() const { return width; }
    float GetHeight() const { return height; }
    float GetPosX() const { return posX; }
    float GetPosY() const { return posY; }
    float GetPosZ() const { return posZ; }


    void Axe::SetScale(float s);
    void SetDimensions(float w, float h);




    void Draw();
};

#endif
