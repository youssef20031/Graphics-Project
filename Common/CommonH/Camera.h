#pragma once

#include <math.h>
#include "stdio.h"
#include "Vector3f.h"
#include "Controls.h"
#include "Player.h"
#include <glut.h>

// Constants
#define DEG2RAD(a) (a * 0.0174532925)

enum ViewMode { FIRST_PERSON, THIRD_PERSON, FREE };

// Camera class definition
class Camera {
public:
    Vector3f eye, center, up;  // Camera position, look-at point, and up vector

    // Constructor to initialize camera parameters
    Camera(float eyeX = 3.0f, float eyeY = 3.0f, float eyeZ = 3.0f,
        float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f,
        float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f);

    // Movement functions
    void moveX(float d);  // Move along the X-axis
    void moveY(float d);  // Move along the Y-axis
    void moveZ(float d);  // Move along the Z-axis

    // Rotation functions
    void rotateX(float a);  // Rotate around the X-axis
    void rotateY(float a);  // Rotate around the Y-axis

    // Set camera view
    void look();  // Apply the current view transformation
    void setView(float eyeX = 3.0f, float eyeY = 3.0f, float eyeZ = 3.0f,
        float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f,
        float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f);  // Update the camera position and orientation
};
void setupCamera();
void displayCameraCoords();
void updateCameraMovement();
void setFirstPersonCamera();
void setThirdPersonCamera();
void renderBitmapString(float x, float y, void* font, const char* string);


// Camera instance declaration

extern Camera camera;
extern ViewMode viewMode;

