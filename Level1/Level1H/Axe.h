#ifndef AXE_H
#define AXE_H

#include "../../Common/CommonH/TextureBuilder.h"
#include "../../Common/CommonH/Model_3DS.h"
#include "../../Common/CommonH/Vector3f.h"
#include "../../GLTexture.h"
#include <string>
#include <glut.h>

class Axe {
public:
    Model_3DS model_axe;
    float rotationSpeed;
    float rotationAngle;

    Axe();
    void LoadModel();
    void UpdateRotation();
    void Draw();
};

#endif 
