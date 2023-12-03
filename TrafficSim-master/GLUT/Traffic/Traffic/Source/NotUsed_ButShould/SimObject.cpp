#include "SimObject.h"

SimObject::SimObject() {
	pos = vec3(0);
	rot = vec3(0);
}

float SimObject::randFloat(const float minV, const float maxV) {
	
	float d = maxV - minV;
	return minV + d*(rand() % 1000) / 1000.0;
}

int SimObject::randInt(const int minV, const int maxV) {

	int d = maxV - minV + 1;
	return minV + rand() % d;
}

void SimObject::setPos(const vec3 p) {
	pos = p;
}

void SimObject::setRot(const vec3 r) {
	rot = r;
}

vec3 SimObject::getPos() const {
	return pos;
}

vec3 SimObject::getRot() const {
	return rot;
}


void SimObject::drawObject() {
	
	//pushMatrix();

	//translate(pos);
	//rotateY(rot.y);
	//rotateX(rot.x);
	//rotateZ(rot.z);

	//draw();
	//glPopMatrix();
	
}

void SimObject::updateObject(const float delta) {
	update(delta);
}

void SimObject::update(const float delta){}