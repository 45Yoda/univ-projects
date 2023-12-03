#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Camera.h"
#include "Car.h"


//should remove TOOBad
#include "Manager.h"


using namespace std;
using namespace glm;


void renderScene();
void changeSize(int w, int h);
void drawScene();

// Mouse Stuff
void mouseMotionCallback(int x, int y);


void keyboardCallback(unsigned char key, int x, int y);
void keyboardUpCallback(unsigned char key, int x, int y);


// Camera stuff
double eyeX = 0, eyeY = 80, eyeZ = 400;
float camX = 0.0f, camY = 0.0f, camZ = 0.0f;
float camAngle = 180;


Camera* camera;

// Window 

int width = 800;
int height = 600;

int windowId;


vector<Car*> cars;

int carNum = 0;


Manager* Manager::instance = 0;

Manager* manage = manage->getInstance();


int main(int argc, char** argv) {

	// Print help here (Camera and window controls)


	// Ask user for number of cars
	// cout << "How many cars? " << endl;
	//cin >> carNumber;


	manage->init();

	cars = manage->getCars(); 

	carNum = manage->getCarNumber();

	// Run simulator

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	windowId = glutCreateWindow("Traffic...");

	glewInit();

	Camera::KEYBOARD mode = Camera::QWERTY;
	camera = new Camera(mode, -200, 200, -200, 4 * M_PI / 7, M_PI / 4, 0.01, 0.2, width, height);


	//Texture Loading
	manage->generateTex();


	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

	glutKeyboardFunc(keyboardCallback);
	glutKeyboardUpFunc(keyboardUpCallback);


	glutPassiveMotionFunc(mouseMotionCallback);
	glutWarpPointer(width / 2, height / 2 + 40);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glEnable(GL_LIGHT0);
	

	glutMainLoop();

	return 0;
}

void renderScene() {

	// Clear Scene
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// Camera Stuff
	glLoadIdentity();
	camera->translation();
	gluLookAt(camera->getX(), camera->getY(), camera->getZ(),
		camera->getSightX(), camera->getSightY(), camera->getSightZ(),
		0, 1, 0);

	// Draw Scene
	drawScene();


	glutPostRedisplay();
	glutSwapBuffers();
}

void changeSize(int w, int h) {

	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45, ratio, 1, 5000);

	glMatrixMode(GL_MODELVIEW);

}

void drawScene() {

	manage->drawCars();

	manage->drawPaths(); 

	//manage->dTesting();

}




void keyboardCallback(unsigned char key, int x, int y) {
	camera->setKeyboard(key, true);

	if (key == 27) {
		glutDestroyWindow(windowId);
		exit(0);
	}
	glutPostRedisplay();
}

void keyboardUpCallback(unsigned char key, int x, int y) {
	camera->setKeyboard(key, false);
}

void mouseMotionCallback(int x, int y) {
	camera->rotation(x, y);

	if (x >= width - 20 || x <= 0 + 20 || y >= height - 20 || y <= 0 + 20) {

		glutWarpPointer(width / 2, height / 2);
		camera->setMouse(width / 2, height / 2);
	}
}




