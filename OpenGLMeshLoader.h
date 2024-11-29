#pragma once
#ifndef OPENGL_MESH_LOADER_H
#define OPENGL_MESH_LOADER_H

#include "Common/CommonH/TextureBuilder.h" 
#include "Common/CommonH/Model_3DS.h"  // class to view .3d models that we'll import
#include "GLTexture.h" // class to load 
#include <glut.h> // Include OpenGL and GLUT headers


//Axe axe1;

// Variable declarations
extern int WIDTH;
extern int HEIGHT;
extern GLuint tex;
extern char title[];

extern int cameraZoom;
extern Model_3DS model_house;
extern Model_3DS model_tree;
//extern Model_3DS model_axe;
extern GLTexture tex_ground;

// Vector class declaration
class Vector {
public:
    GLdouble x, y, z;
    Vector();
    Vector(GLdouble _x, GLdouble _y, GLdouble _z);
    void operator +=(float value);
};

// Function declarations
void InitLightSource();
void InitMaterial();
void myInit(void);
void RenderGround();
void myDisplay(void);
void myKeyboard(unsigned char button, int x, int y);
void myMotion(int x, int y);
void myMouse(int button, int state, int x, int y);
void myReshape(int w, int h);
//void LoadAssets();

#endif // OPENGL_MESH_LOADER_H
