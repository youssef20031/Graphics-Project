#include "../../Level1/Level1H/Level1.h"
#include "../CommonH/Lighting.h"


void setupLights() {
	glEnable(GL_LIGHTING);

	GLfloat global_ambient[] = { 0.05f, 0.05f, 0.05f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

	// Configure torch lights
	configureTorchLight(GL_LIGHT0, torch.pos.x, torch.pos.y, torch.pos.z);
	configureTorchLight(GL_LIGHT1, torch2.pos.x, torch2.pos.y, torch2.pos.z);
	configureTorchLight(GL_LIGHT2, torch3.pos.x, torch3.pos.y, torch3.pos.z);
	configureTorchLight(GL_LIGHT3, torch4.pos.x, torch4.pos.y, torch4.pos.z);


    // Cave and Stage 1 Lighting

    GLfloat light_position[] = { -50.3f, 16.59f, 49.32f, 1.0f };
    GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };       
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };      

    GLfloat constant_attenuation = 0.8f; 
    GLfloat linear_attenuation = 0.05f; 
    GLfloat quadratic_attenuation = 0.02f;

    glLightfv(GL_LIGHT4, GL_POSITION, light_position);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT4, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT4, GL_AMBIENT, light_ambient);

    glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, constant_attenuation);
    glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, linear_attenuation);
    glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, quadratic_attenuation);

    glEnable(GL_LIGHT4);
}
