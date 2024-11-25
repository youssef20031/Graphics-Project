#include "../Level1H/PlaygroundObstacles.h"


extern GLfloat obstacles[numberOfObstacles][6];


// obstacles
GLfloat obstacles[numberOfObstacles][6] = {
	{ 0.0f, 3.0f, 0.0f, 0.1f, 0.0f, 3.0f }, // ground
	{ 0.0f, 3.0f, 0.0f, 0.3f, 1.0f, 1.1f },  // wall 1
	{ 0.0f, 3.0f, 0.0f, 0.5f, 1.1f, 1.2f },  // wall 2
	{ 0.0f, 3.0f, 0.0f, 0.7f, 1.2f, 1.3f },  // wall 3
	{ 0.0f, 3.0f, 0.0f, 0.9f, 1.3f, 1.4f },  // wall 4
	{ 0.0f, 3.0f, 0.0f, 1.1f, 1.4f, 1.5f },  // wall 5
	{ 0.0f, 3.0f, 0.0f, 1.3f, 1.5f, 1.6f }  // wall 6
};