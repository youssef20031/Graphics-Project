#pragma once
#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>

// Constants
#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925)

// Vector3f class definition
class Vector3f {
public:
    float x, y, z;

    Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);
    Vector3f operator+(Vector3f& v);
    Vector3f operator-(Vector3f& v);
    Vector3f operator*(float n);
    Vector3f operator/(float n);
    Vector3f unit();
    Vector3f cross(Vector3f v);
};

// Camera class definition
class Camera {
public:
    Vector3f eye, center, up;

    Camera(float eyeX = 3.0f, float eyeY = 3.0f, float eyeZ = 3.0f,
        float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f,
        float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f);

    void moveX(float d);
    void moveY(float d);
    void moveZ(float d);
    void rotateX(float a);
    void rotateY(float a);
    void look();
    void setView(float eyeX = 3.0f, float eyeY = 3.0f, float eyeZ = 3.0f, float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f, float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f);

};

// Camera instance
extern Camera camera;

// Lighting setup functions
void setupLights();

// Camera setup function
void setupCamera();

// Display function
void Display();

// Keyboard and special key functions
void Keyboard(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void Special(int key, int x, int y);
void SpecialUp(int key, int x, int y);

void updateStates();
void updateCameraMovement();
void updatePlayerMovement();

#endif // PLAYGROUND_H
