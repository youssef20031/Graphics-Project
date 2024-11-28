#include "../../Level1/Level1H/Axe.h"

Axe::Axe() : rotationSpeed(0.1f), rotationAngle(0) {}

void Axe::LoadModel() {
    
    const std::string modelPath = "../../models/axe/untitled.3ds";

    
    model_axe.Load(const_cast<char*>(modelPath.c_str()));
    

  
    model_axe.scale = 0.5f;
    model_axe.pos.x = -38.45f;
    model_axe.pos.y = 0.3f;
    model_axe.pos.z = 51.3f;
}


void Axe::UpdateRotation() {
    rotationAngle += rotationSpeed;
    if (rotationAngle > 360) rotationAngle = 0; 
}

void Axe::Draw() {
    glPushMatrix();
    glTranslatef(model_axe.pos.x, model_axe.pos.y, model_axe.pos.z);  
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f); 
    model_axe.Draw();
    glPopMatrix();
}
