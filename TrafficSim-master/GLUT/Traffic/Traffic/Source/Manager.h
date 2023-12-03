#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Can possibly remove this lets wait
#include <GL/glew.h>
#include <GL/freeglut.h>


#include "Path.h"

#include "Parser.h"

#include "IntersectionAux.h"




class Car;

using namespace std;
using namespace glm;


#include <random>


class Manager{

public:

	// Singleton Stuff to be callable by all classes without creating an instance for each
	static Manager* instance;

	static Manager* getInstance() {
		if (!instance)
			instance = new Manager;
		return instance;
	}


	vector<vector<vec3>> pathsTest;

	Parser parser;


	Path* path = new Path();

	vector<Car*> cars;

	queue<Car*> outCars;

	vector<Parser::Node> nodes;

	int getCarNumber();

	int carNumber;

	int roadHalf = 6;
	int sidewalkHalf = 8;


	float currTime = 0.0f;
	float oldTime = 0.0f;
	float timeFlag = 0;


	// SHOULD THESE BE QUEUES
	map<long long, vector<Car*>> carsInWay;
	map<long long, vector<Car*>> carsInJunc;

	// Setup carsInWay and carsInJunc vectors 
	void setupCarLocationVecs();


	// Using an ID give the currentCars present at the way
	vector<Car*> currentCarsAtWay(long long wayID);
	
	// Using an ID give the currentCars present at the way
	vector<Car*> currentCarsAtJunc(long long juncID);

	// Remove from the old vector of cars and add to a new vector of cars
	// types : 0 -> Way, 1 -> Junc
	// Needs testing
	void removeAndAddToVec(int carID, long long oldID, long long newID, int type1, int type2);

	// Gets car in front's current position
	// carID -> car asking for the position
	// locationID -> current Way or Junc id
	// type : 0 -> Way , 1 -> Junc
	vec3 getCarInFrontPosition(int carID, long long locationID, int type);

	// TODO
	// get car in front speed? or should I add it to the function above?
	// have types of braking maybe?

	// 


	//HACK NEW TRY

	map<long long, Parser::WayData> waysMap;

	// Structure for drawing only MEW
	map<long long, Parser::DrawData> drawMap;

	vector<Parser::Junction> junctsToDraw;

	vector<vector<vec3>>  pathSets;

	vector<vector<vec3>> sidewalkSets;

	vector<vector<vec3>> intersectionsToDraw;

	// SHOULD BE REMOVED AFTER DEBUG 
	int flagTurnOffIntersections = 1;

	void setUpWithMap();

	vector<int> numbers;

	vector<long long> mapEntrances;
	vector<long long> mapExits;

	map<long long, Parser::Intersection>* intersections;


	//Textures
	unsigned int texture;
	
	int generateTex();





	bool compareCrossProd(vec3 dir1, vec3 dir2);



	void shout();

	int init();

	vector<vector<vec3>> getPathSets();

	vector<Car*> getCars();

	void getNewCar();

	void drawCars();

	void drawPaths();

	void dTesting();

	void resetCar(Car* car);

	void orderRoads();

	vector<pair<vec3, vec3>> findPoints (Parser::Intersection, vector<int>* interOrd);

	

	// Create a new car after erasing old one.
	void createNew(int carId);

private:


	Manager();



};