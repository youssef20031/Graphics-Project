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
