#pragma once

#include "Colors.h"
#include "Path.h"
#include "Parser.h"

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include <chrono>
#include <cmath>

#include <random>

class Manager;

class Car {

public:

	
	Car(Parser::WayData, int id);

	void draw();

	//void reset();

	float lerp(float a, float b, float f);

	vec3 color;

	vec3 position;

	vec3 newPos;

	int exited = 0;

	vec3 derivStore;
	float* deriv;

	float up[3];

	void normalize(float* a);

	void cross(float* a, float* b, float* res);

	void curveRotation(float* der, float* up);


	void startSlowing();


	float speed = 0.06;


	int currentSegment = 0;

	Path* currentPath;


	void incrSegment();

	int shouldExit = 0;

	int inJunc = 0;
	int stop = 0;

	int countExits = 0;

	int timeFlag = 0;
	


	// Hack, new function for mov
	void distandTval(double time);
	
	
	double calcDistanceToTravel(double time);
	double calculateTValue(double distance, vector<double> distances, vector<double> tvalues, int* give);
	
	vector<vector<double>> currentDistances;
	vector<double> currentTValues;
	vector<double> segmentDistances;

	vector<double> totalDists;

	double oldDistance = 0.0;
	double totalDistTraveled = 0.0;


	//oh no
	vector<Parser::Node*> firstVector;


	// REMOVE THIS
	void setCars(Car* c);


	//HACK THIS IS NEW
	vector<Parser::Node*> currentVector;

	void createPath(vector<Parser::Node*> wayVec);

	void update();

	void giveVector(Parser::Node* lastNode);

	Parser::Node* firstPosLastVec;

	int finalStop = 0;

	//REMOVE
	Car* testCar;

	//HACK THIS is new
	chrono::time_point<chrono::steady_clock> start;
	chrono::time_point<chrono::steady_clock> check;


	int carID;



	// THIS IS NEW part 2
	vector<float> deltaTs;
	double comparedTime;


	void reset();

	// Exits of the current map. Set in the manager after creation
	vector<long long> mapExits;

private:


	void drawCube(float x, float y, float z) const;

	void setColor(const float r, const float g, const float b);

	void setColor(const vec3 color);
};