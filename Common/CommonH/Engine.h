#pragma once
#pragma once

#include <glut.h>
#include "../../Level1/Level1H/Level1.h"
#include "../../Level2/Level2H/Level2.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

// Constants
#define WIDTH 800  
#define HEIGHT 600 




void realDeal(int argc, char** argv);


void playgroundMain(int argc, char** argv);

// Callback declarations for `realDeal`
void myDisplay();
void myKeyboard(unsigned char key, int x, int y);
void myMotion(int x, int y);
void myMouse(int button, int state, int x, int y);
void myReshape(int w, int h);
void myInit();
void LoadAssets();

// Callback declarations for `playgroundMain`
void Display();
void Keyboard(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void Special(int key, int x, int y);
void SpecialUp(int key, int x, int y);
void updateStates();
void drawAxis();

extern float lastFrameTime;
extern float deltaTime;
extern int level;
extern GLfloat fallAcceleration; // e3tebro gravity

void level2Transition(int value);

void updateDeltaTime();

void stopBackgroundMusic();

void renderBoldStrokeText(float x, float y, float z, const char* text, float scale, float lineWidth);

void drawHUD();

void renderCheckpointMessage(const char* message);
