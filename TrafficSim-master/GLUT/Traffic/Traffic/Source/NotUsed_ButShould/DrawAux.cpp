
#include "DrawAux.h"


const unsigned int DrawAux::QUADS = GL_QUADS;
const unsigned int DrawAux::TRIANGLES = GL_TRIANGLES;
const unsigned int DrawAux::POLYGON = GL_POLYGON;
const unsigned int DrawAux::LINES = GL_LINES;

void DrawAux::draw() {}



void DrawAux::drawCube(float a) const {
	drawCube(a, a, a);
}



void DrawAux::drawCube(float x, float y, float z) const {


	x /= 2;
	y /= 2;
	z /= 2;

	glBegin(GL_TRIANGLES);

	// Front
	glVertex3f(x, y, z);
	glVertex3f(-x, y, z);
	glVertex3f(-x, -y, z);

	glVertex3f(-x, -y, z);
	glVertex3f(x, -y, z);
	glVertex3f(x, y, z);

	// Right
	glVertex3f(x, y, -z);
	glVertex3f(x, y, z);
	glVertex3f(x, -y, z);

	glVertex3f(x, -y, z);
	glVertex3f(x, -y, -z);
	glVertex3f(x, y, -z);

	// Top
	glVertex3f(x, y, -z);
	glVertex3f(-x, y, -z);
	glVertex3f(-x, y, z);

	glVertex3f(-x, y, z);
	glVertex3f(x, y, z);
	glVertex3f(x, y, -z);

	// Left
	glVertex3f(-x, y, z);
	glVertex3f(-x, y, -z);
	glVertex3f(-x, -y, -z);

	glVertex3f(-x, -y, -z);
	glVertex3f(-x, -y, z);
	glVertex3f(-x, y, z);

	// Bottom
	glVertex3f(-x, -y, -z);
	glVertex3f(x, -y, -z);
	glVertex3f(x, -y, z);

	glVertex3f(x, -y, z);
	glVertex3f(-x, -y, z);
	glVertex3f(-x, -y, -z);

	// Back
	glVertex3f(x, -y, -z);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x, y, -z);

	glVertex3f(-x, y, -z);
	glVertex3f(x, y, -z);
	glVertex3f(x, -y, -z);

	glEnd();
	
}

void DrawAux::drawLine(const vec3 b, const vec3 e) const {
	
	glBegin(GL_LINES);
	glVertex3f(b.x, b.y, b.z);
	glVertex3f(e.x, e.y, e.z);
	glEnd();
}


void DrawAux::drawTile(float a)  const {
	
	a /= 2;

	glBegin(GL_TRIANGLES);
	glVertex3f(-a, 0, a);
	glVertex3f(a, 0, a);
	glVertex3f(a, 0, -a);
	
	glVertex3f(-a, 0, -a);
	glVertex3f(-a, 0, a);
	glVertex3f(a, 0, -a);
	glEnd();


}

void DrawAux::setColor(const float r, const float g, const float b) {

	glColor3f(r, g, b);

}

void DrawAux::setColor(const vec3 color) {

	glColor3f(color.x, color.y, color.z);

}

void DrawAux::drawVertex(const vec3 point) const {

	glVertex3f(point.x, point.y, point.z);

}
