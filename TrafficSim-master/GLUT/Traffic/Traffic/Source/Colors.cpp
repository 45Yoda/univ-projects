#include "Colors.h"


#include <iostream>

using namespace std;



vec3 Colors::getRandomColor() {

	static Colors* instance;
	if (instance == nullptr)
		instance = new Colors();

	return instance->pickRandom();
}

Colors::Colors() {

	amount = 6;
	colors = new vec3[amount];

	
	colors[0] = vec3(1, 0, 0);
	colors[1] = vec3(0, 1, 0);
	colors[2] = vec3(0, 0, 1);
	colors[3] = vec3(1, 0, 1);
	colors[4] = vec3(1, 1, 0);
	colors[5] = vec3(0, 1, 1);
	
}

vec3 Colors::pickRandom() {
	
	//Will be used to obtain a seed for the random number engine
	random_device rd; 
	//Standard mersenne_twister_engine seeded with rd()
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(0, amount-1);

	vec3 col = colors[distrib(gen)];

	return col;
}
