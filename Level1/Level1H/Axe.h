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

   
    Axe();

    void Load();

    void SetPosition(float x, float y, float z);

    void SetRotation(float x, float y, float z);


    void SetRotationSpeed(float speed);

    void SetRotationLimits(float min, float max);


    void Axe::SetScale(float s);




    void Draw();
};

#endif
