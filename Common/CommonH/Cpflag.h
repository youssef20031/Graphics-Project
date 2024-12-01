#ifndef CPFLAG_H
#define CPFLAG_H

#include "Model_3DS.h"

class Cpflag {
public:
    Model_3DS model;
    float posX, posY, posZ;
    float rotX, rotY, rotZ;
    float scale;
    
    Cpflag();

    void Load();

    void SetPosition(float x, float y, float z);

    void SetRotation(float x, float y, float z);


  
    float GetPosX() const { return posX; }
    float GetPosY() const { return posY; }
    float GetPosZ() const { return posZ; }
    float GetRotX() const { return rotX; }
    float GetRotY() const { return rotY; }
    float GetRotZ() const { return rotZ; }


    void Cpflag::SetScale(float s);





    void Draw();
};

#endif
