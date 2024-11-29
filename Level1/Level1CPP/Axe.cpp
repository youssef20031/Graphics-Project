#include "../Level1H/Axe.h"

#include <glut.h>

Axe::Axe() {
    posX = 0.0f;
    posY = 0.0f;
    posZ = 0.0f;
    rotX = 0.0f;
    rotY = 0.0f;
    rotZ = 0.0f;
    scale = 0.4f;

    rotationSpeed = 0.5f;  
    maxRotation = 90.0f;  
    minRotation = -90.0f;  
    rotationDirection = 1;

    width = 1.0f;   // beytala3 le odam
    height = 5.0f; // the width 
    depth = 5.0f;  // the height

    // confusing names ana 3aref lol
}


void Axe::Load() {
    model.Load("Models/axe/untitled.3ds");
}


void Axe::SetPosition(float x, float y, float z) {
    posX = x;
    posY = y;
    posZ = z;
}

void Axe::SetDimensions(float w, float h) {
    width = w;
    height = h;
}


void Axe::SetRotation(float x, float y, float z) {
    rotX = x;
    rotY = y;
    rotZ = z;
}

void Axe::SetScale(float s) {
    scale = s;
}

void Axe::SetRotationSpeed(float speed) {
    rotationSpeed = speed;
}

void Axe::SetRotationLimits(float min, float max) {
    minRotation = min;
    maxRotation = max;
}


void Axe::Draw() {

    rotY += rotationSpeed * rotationDirection;
    if (rotY >= maxRotation || rotY <= minRotation) {
        rotationDirection *= -1;
    }
    glPushMatrix();
    glTranslatef(posX, posY, posZ); 
    glRotatef(rotX, 1.0f, 0.0f, 0.0f); 
    /// Rotation animation
    glRotatef(rotY, 1.0f, 0.0f, 0.0f);
    ///
    glRotatef(rotZ, 0.0f, 0.0f, 1.0f); 
    glScalef(scale,scale,scale);
    model.Draw();


    // AXE COLLISION BOUNDING BOX

    glColor3f(1.0f, 0.0f, 0.0f); 
    glBegin(GL_LINE_LOOP);
    
    glVertex3f(-width / 2, -height / 2, depth / 2);  
    glVertex3f(width / 2, -height / 2, depth / 2);  
    glVertex3f(width / 2, height / 2, depth / 2);    
    glVertex3f(-width / 2, height / 2, depth / 2);   
    glEnd();

    glBegin(GL_LINE_LOOP);
 
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glEnd();

    glBegin(GL_LINES);
 
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);

    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);

    glVertex3f(width / 2, height / 2, depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);

    glVertex3f(-width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);

    glPopMatrix();
}
