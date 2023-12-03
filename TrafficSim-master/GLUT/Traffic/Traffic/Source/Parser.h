#pragma once

#include <glm/glm.hpp>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <queue>

#ifndef M_PI
#define M_PI 3.1415926535
#endif

#include <cmath>

#include "tinyxml2.h"


using namespace std;
using namespace glm;
using namespace tinyxml2;

class Parser {

public:

	struct Node {
		long long id;
		double lat;
		double lon;
		int drawn;
		int ocur;

		int isJunc;

		Node() : id(0), lat(0.0f), lon(0.0f), drawn(0), ocur(0), isJunc(0){}
	};

	struct Way {
		long long way_id;
		vector<long long> node_refs;

		int type;
		
	
		Way() : way_id(0), type(0)  {}
		
		
	};

	struct Junction {
		vector<Node*> fullWay;

		vector<long long> exits;

		int junc_id;

		//each 'exit' has vectors for each segment that have a distance "table"
		vector<vector<vector<double>>> distanceTables;
		//table is always the same only need one
		vector<double> tvalue;
		//each 'exit' has vectors for each segment that have the distance value 
		vector<vector<double>> distanceSegments;

		//Tags in the junction, includes maxspeed and lanes
		vector < pair<string, string>> tags;
	};
	

	vector<Node> nodes;

	vector<Way> ways;

	vector<Way> buildings;

	vector<Way> pedestrians;
	
	// Added
	vector<Way> nodesToDelete;

	struct WayData {

		long long way_id;

		vector<vector<Node*>> choices;
		
		//each 'choice' has vectors for each segment that have a distance "table"
		vector<vector<vector<double>>> distanceTables;
		//table is always the same only need one
		vector<double> tvalue;
		//each 'choice' has vectors for each segment that have the distance value 
		vector<vector<double>> distanceSegments;
		//totalDistance for all the available choices
		vector<double> totalDistance;
	
		//Tags in the way, includes maxspeed and lanes
		vector <pair<string, string>> tags;
	};

	struct DrawData {
		long long way_id;

		vector<vector<Node*>> draw_choices;

		vector<pair<string, string>> tags;
	};

	vector <long long> allWayIDS;
	vector <long long> allJuncIDS;

	vector<vector<double>> calcDistances(vector<Node*> wayToAdd, double* totalD, vector<double>* distSegment);

	vector<double> tvals;

	void setupTVals();

	static map<long long, WayData> allWays;
	static map<long long, DrawData> waysToDraw;

	// ADDED
	static map<long long, Junction> allJunctions;


	//ADDED
	static vector<Junction> juncsToDraw;

	//Added
	map<long long, vector<pair<string, string>>> wayTags;

	vector<Way> junctions;

	vector<long long> nodesToAdd;

	vector<long long> intersections;

	// Intersection structure
	struct Intersection {
		vector<vector<Node*>> connectedRoads;
		Node* intersectionPoint;
		vector<pair<vec3, vec3>> connectionPoints;
		// isIntersection flag values: 0 not intersection, 1 intersection at start, 2 intersection at end;
		vector<int>intersectionTypes;
	};

	map<long long, Intersection>* getAllIntersections();

	// new intersection structure
	// <intersection point, Intersection structure>
	map<long long, Intersection> allIntersections;

	// flag for intersections
	int interFound = 0;
	//Node* interPoint;

	vector<Node*> interPoints;

	//NEW and Improved, type: 0 for exits, 1 for oneways
	Junction calcDistForJunction(long long id, Junction junc);

	//Change the vector position to the correct id
	Junction orderVectorByNode(long long id, Junction junc);

	//Entrances and Exits
	vector<long long> mapEntrances;
	vector<long long> mapExits;

	vector<long long> getEntrances();
	vector<long long> getExits();


	Parser() {};
	void loadFile(char* fileName);
	vector<Node> getNodes();
	vector<Way> getWays();

	static map<long long, WayData> getMap();

	static map<long long, DrawData> getMapToDraw();

	vector<long long> getIntersections();

	static map<long long, Junction> getJunctions();

	static vector<Junction> getJuncsToDraw();

	static vector<int> numbers;

	void discoverEntranceAndExit();

	vector<long long> getWayIDS();
	vector<long long> getJuncIDS();

	
private:

	void createGraph();

	// Add the roads that are connected to the intersections to the intersection map
	void addConnectedRoads(vector <vector<Node*>> waysToCheck);

	// junctions junctions junctions
	void createJunctions();

	// remove any Vec nodes
	void removeFromVec(vector<Way> someVec);

	// remove building nodes
	void removeBuildings();

	// remove pedestrian nodes
	void removePedestrians();
};
