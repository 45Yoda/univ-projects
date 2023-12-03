#pragma once


#include "SimObject.h"
#include "Car.h"

#include <vector>



#include <glm/glm.hpp>

using namespace glm;
using namespace std;


class Cross;


class Road : public SimObject {

public:

	Road() {};

	//queue<Car*> carsBeg;
	//queue<Car*> carEnd;


	vec3 begPos;
	vec3 endPos;

	float length;
	vec3 direction;

	vec3 normal;

	Cross* crossBeg;
	Cross* crossEnd;

	Road(Cross* begCross, Cross* endCross);

	void draw();

};


class Cross : public Road {

public:
	Cross(vec3 position);



	struct OneStreet {
		Road* street;
		vector<Car*> cars;
		bool enabled = true;
		bool direction;
		vec3 jointPos;

		vector<vector<int>> yield;
	};

	vector<OneStreet> streets;

	void update(float delta);

	void draw();
	
};


class Garage : public Road {

public:
	Garage(vec3 p, Cross* c);

	float frec;
	float curTime;

	void draw();
	void update(float delta);
	string itos(int x);
	void spotCar();


};
