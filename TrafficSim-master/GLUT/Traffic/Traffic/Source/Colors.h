#pragma once

#include "glm/glm.hpp"

#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <random>

using namespace glm;

class Colors {

public:
	static vec3 getRandomColor();

private:
	vec3* colors;
	int amount;
	Colors();

	vec3 pickRandom();
};