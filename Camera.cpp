
#include "Camera.h"
#include "stdio.h"

// Camera class constructor and methods




Camera::Camera(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) {
	eye = Vector3f(eyeX, eyeY, eyeZ);
	center = Vector3f(centerX, centerY, centerZ);
	up = Vector3f(upX, upY, upZ);
}

// Move camera along the X axis
void Camera::moveX(float d) {
	Vector3f right = up.cross(center - eye).unit();
	eye = eye + right * d;
	center = center + right * d;
}

// Move camera along the Y axis
void Camera::moveY(float d) {
	eye = eye + up.unit() * d;
	center = center + up.unit() * d;
}

// Move camera along the Z axis
void Camera::moveZ(float d) {
	Vector3f view = (center - eye).unit();
	eye = eye + view * d;
	center = center + view * d;
}

// Rotate camera around the X axis
void Camera::rotateX(float a) {
	Vector3f view = (center - eye).unit();
	Vector3f right = up.cross(view).unit();
	view = view * cos(DEG2RAD(a)) + up * sin(DEG2RAD(a));
	up = view.cross(right);
	center = eye + view;
}

// Rotate camera around the Y axis
void Camera::rotateY(float a) {
	Vector3f view = (center - eye).unit();
	Vector3f right = up.cross(view).unit();
	view = view * cos(DEG2RAD(a)) + right * sin(DEG2RAD(a));
	right = view.cross(up);
	center = eye + view;
}

// Set camera position and orientation
void Camera::look() {
	gluLookAt(
		eye.x, eye.y, eye.z,
		center.x, center.y, center.z,
		up.x, up.y, up.z
	);
}

void Camera::setView(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) {
	eye = Vector3f(eyeX, eyeY, eyeZ);
	center = Vector3f(centerX, centerY, centerZ);
	up = Vector3f(upX, upY, upZ);
}
void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 640 / 480, 0.001, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera.look();
}

void renderBitmapString(float x, float y, void* font, const char* string) {
	glRasterPos2f(x, y);
	while (*string) {
		glutBitmapCharacter(font, *string);
		string++;
	}
}


void displayCameraCoords() {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	glColor3f(0.0f, 0.0f, 0.0f);

	char coords[100];
	snprintf(coords, sizeof(coords), "Camera Position: (%.2f, %.2f, %.2f)", camera.eye.x, camera.eye.y, camera.eye.z);
	renderBitmapString(10, 420, GLUT_BITMAP_HELVETICA_18, coords);

	char centerCoords[100];
	snprintf(centerCoords, sizeof(centerCoords), "Camera Center: (%.2f, %.2f, %.2f)", camera.center.x, camera.center.y, camera.center.z);
	renderBitmapString(10, 400, GLUT_BITMAP_HELVETICA_18, centerCoords);

	char upCoords[100];
	snprintf(upCoords, sizeof(upCoords), "Camera Up: (%.2f, %.2f, %.2f)", camera.up.x, camera.up.y, camera.up.z);
	renderBitmapString(10, 380, GLUT_BITMAP_HELVETICA_18, upCoords);

	glEnable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

Camera camera;


