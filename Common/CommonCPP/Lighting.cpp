#include "../../Level1/Level1H/Level1.h"
#include "../CommonH/Lighting.h"


void setupLights() {
	glEnable(GL_LIGHTING);

	// Global Ambient Light
	GLfloat global_ambient[] = { 0.05f, 0.05f, 0.05f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

	// Configure torch lights
	configureTorchLight(GL_LIGHT0, torch.pos.x, torch.pos.y, torch.pos.z);
	configureTorchLight(GL_LIGHT1, torch2.pos.x, torch2.pos.y, torch2.pos.z);
	configureTorchLight(GL_LIGHT2, torch3.pos.x, torch3.pos.y, torch3.pos.z);
	configureTorchLight(GL_LIGHT3, torch4.pos.x, torch4.pos.y, torch4.pos.z);
}

//void setupLights() {
//	GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
//	GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
//	GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
//	GLfloat shininess[] = { 50 };
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
//
//	GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
//	GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
//	glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
//}
