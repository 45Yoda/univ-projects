#pragma once

#include "DrawAux.h"

#include "glm/glm.hpp"
#include <string>

using namespace glm;

class SimObject : public DrawAux {

public:

	SimObject();
	virtual ~SimObject() {};

	void updateObject(const float delta);
	void drawObject();

	void setPos(const vec3 p);
	void setRot(const vec3 r);
	vec3 getPos() const;
	vec3 getRot() const;
	int id;

	

protected:
	vec3 pos;
	vec3 rot;

	virtual void update(const float delta);
	static float randFloat(const float minV, const float maxV);
	static int randInt(const int minV, const int maxV);
	

};