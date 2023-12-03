#pragma once

#include "GL/freeglut.h"
#include "glm/glm.hpp"

using namespace glm;

class DrawAux {

public:
	void drawCube(float a) const;
	void setColor(const float r, const float g, const float b);

protected:

	virtual void draw();
	void drawCube(float x, float y, float z) const;
	void drawLine(const vec3 beginPoint, const vec3 endPoint) const;
	void drawTile(float a) const;
	//void setColor(const float r, const float g, const float b);
	void setColor(const vec3 c);

	void drawVertex(const vec3 a) const;


	static const unsigned int QUADS;
	static const unsigned int TRIANGLES;
	static const unsigned int LINES;
	static const unsigned int POLYGON;
};

