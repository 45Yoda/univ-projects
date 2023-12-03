/*#pragma once

#include <vector>
#include <glm/glm.hpp>
//#include "Path.h"



#define MAX_SIZE 1024;

using namespace std;
using namespace glm;



class Graph {

public:

	Graph();
	~Graph() {}; // This is a destructor

	struct City;
	struct Intersection;
	struct Node_In;
	struct Node_Exit;

	// TESTAR COM 1 EDGE PARA CADA LADO EM CONJUNTO COM O PATH


	struct City {

		int numberIntersections = 0;

		vector<Intersection> intersections; // position is the indice of the Intersection (Node);
		vector<vector<int>> street; // connections between different Intersections

	};

	struct Intersection {
	
		vec3 position;
		vector<int> next_Intersections;
		//vector<Node_In*> ins;

	};

	struct Node_In {

		vector<Node_Exit*> exits;  // Possible exits
	};

	struct Node_Exit {

		//Node_In* next;
		int next_Intersection; // indice of next Intersection if exit is taken
		int next_Node_In; // indice do próximo node_In
		//Path path_to_next;
	};


	void addEdge(vector<int> adj[], int u, int v);

};
*/

/*

void Driveable::commonConstructor()
{
	direction = endPos - begPos;
	direction.normalize();

	length = Vec3::dst(begPos, endPos);

	normal = Vec3::cross(Vec3(0, 1, 0), direction);
	normal.normalize();

	reservedSpaceBeg = 0;
	reservedSpaceEnd = 0void Driveable::draw()
	{
		setColor(roadColor);

		Vec3 szer = Vec3::cross(Vec3(0, 1, 0), direction);
		szer.normalize();
		szer *= 0.3;

		Vec3 a = endPos + szer;
		Vec3 b = endPos - szer;
		Vec3 c = begPos + szer;
		Vec3 d = begPos - szer;

		beginDraw(POLYGON);
		setNormal(0, -1, 0);
		drawVertex(a);
		drawVertex(b);
		drawVertex(d);
		drawVertex(c);
		endDraw();
	}
*/