
#include "Playground.h"
#include <cmath>  // for sqrt() and cos(), sin()

#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925)

bool keyStates[256] = { false }; // to track state of keys pressed
bool specialKeyStates[256] = { false }; // to track state of special keys pressed

// Vector3f class constructor and methods
Vector3f::Vector3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

// Vector addition
Vector3f Vector3f::operator+(Vector3f& v) {
	return Vector3f(x + v.x, y + v.y, z + v.z);
}

// Vector subtraction
Vector3f Vector3f::operator-(Vector3f& v) {
	return Vector3f(x - v.x, y - v.y, z - v.z);
}

// Scalar multiplication
Vector3f Vector3f::operator*(float n) {
	return Vector3f(x * n, y * n, z * n);
}

// Scalar division
Vector3f Vector3f::operator/(float n) {
	return Vector3f(x / n, y / n, z / n);
}

// Unit vector
Vector3f Vector3f::unit() {
	return *this / sqrt(x * x + y * y + z * z);
}

// Cross product
Vector3f Vector3f::cross(Vector3f v) {
	return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

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

Camera camera;

void drawWall(double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd) {
	glPushMatrix();

	double centerX = (xStart + xEnd) / 2.0;
	double centerY = (yStart + yEnd) / 2.0;
	double centerZ = (zStart + zEnd) / 2.0;

	double scaleX = fabs(xEnd - xStart);
	double scaleY = fabs(yEnd - yStart);
	double scaleZ = fabs(zEnd - zStart);

	glTranslated(centerX, centerY, centerZ);

	glScaled(scaleX, scaleY, scaleZ);

	glutSolidCube(1);

	glPopMatrix();
}



void setupLights() {
	GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
	GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
	GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
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

void drawAxis() {
	glPushMatrix();

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 10.0f);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 10.0f, 0.0f);
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, 0.0f);
	glEnd();

	glPopMatrix();
}

/////////////////////////////// Display ////////////////////////////////

void Display() {
	setupCamera();
	setupLights();

	glutFullScreen();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	displayCameraCoords();

	drawAxis();

	glColor3f(0.2f, 0.7f, 0.8f);
	//drawWall(0.0f, 0.0f, 0.0f, 0.1f, 2.0f, 2.0f);
	drawWall(0.0f, 0.0f, 0.0f, 0.3f, 0.2f, 0.1f);


	glFlush();
}
void Keyboard(unsigned char key, int x, int y) {
	switch (key) {
		// player movement
	case 'w':
		keyStates['w'] = true;
		break;
	case 's':
		keyStates['s'] = true;
		break;
	case 'a':
		keyStates['a'] = true;
		break;
	case 'd':
		keyStates['d'] = true;
		break;
	case ' ':
		keyStates[' '] = true;
		break;

		// camera states
	case '1':
		printf("Top View Active\n");
		//setTopView();
		break;
	case '2':
		printf("Front View Active\n");
		//setFrontView();
		break;

		// camera movement
	case 'i':
		keyStates['i'] = true;
		break;
	case 'k':
		keyStates['k'] = true;
		break;
	case 'j':
		keyStates['j'] = true;
		break;
	case 'l':
		keyStates['l'] = true;
		break;
	case 'u':
		keyStates['u'] = true;
		break;
	case 'o':
		keyStates['o'] = true;
		break;

	case GLUT_KEY_ESCAPE:
		exit(EXIT_SUCCESS);
	}

	glutPostRedisplay();
}
void KeyboardUp(unsigned char key, int x, int y) {
	switch (key) {
		// player movement
	case 'w':
		keyStates['w'] = false;
		break;
	case 's':
		keyStates['s'] = false;
		break;
	case 'a':
		keyStates['a'] = false;
		break;
	case 'd':
		keyStates['d'] = false;
		break;
	case ' ':
		keyStates[' '] = false;
		break;

		// camera movement
	case 'i':
		keyStates['i'] = false;
		break;
	case 'k':
		keyStates['k'] = false;
		break;
	case 'j':
		keyStates['j'] = false;
		break;
	case 'l':
		keyStates['l'] = false;
		break;
	case 'u':
		keyStates['u'] = false;
		break;
	case 'o':
		keyStates['o'] = false;
		break;
	}

	glutPostRedisplay();
}
void Special(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		specialKeyStates[GLUT_KEY_UP] = true;
		break;
	case GLUT_KEY_DOWN:
		specialKeyStates[GLUT_KEY_DOWN] = true;
		break;
	case GLUT_KEY_LEFT:
		specialKeyStates[GLUT_KEY_LEFT] = true;
		break;
	case GLUT_KEY_RIGHT:
		specialKeyStates[GLUT_KEY_RIGHT] = true;
		break;
	}

	glutPostRedisplay();
}
void SpecialUp(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		specialKeyStates[GLUT_KEY_UP] = false;
		break;
	case GLUT_KEY_DOWN:
		specialKeyStates[GLUT_KEY_DOWN] = false;
		break;
	case GLUT_KEY_LEFT:
		specialKeyStates[GLUT_KEY_LEFT] = false;
		break;
	case GLUT_KEY_RIGHT:
		specialKeyStates[GLUT_KEY_RIGHT] = false;
		break;
	}

	glutPostRedisplay();
}

void updateKeys() {
	float d = 0.0000002;
	float a = 0.00002;

	if (keyStates['i']) {
		camera.moveY(d);
	}
	if (keyStates['k']) {
		camera.moveY(-d);
	}
	if (keyStates['j']) {
		camera.moveX(d);
	}
	if (keyStates['l']) {
		camera.moveX(-d);
	}
	if (keyStates['u']) {
		camera.moveZ(d);
	}
	if (keyStates['o']) {
		camera.moveZ(-d);
	}

	if (specialKeyStates[GLUT_KEY_UP]) {
		camera.rotateX(a);
	}
	if (specialKeyStates[GLUT_KEY_DOWN]) {
		camera.rotateX(-a);
	}
	if (specialKeyStates[GLUT_KEY_LEFT]) {
		camera.rotateY(a);
	}
	if (specialKeyStates[GLUT_KEY_RIGHT]) {
		camera.rotateY(-a);
	}


}
