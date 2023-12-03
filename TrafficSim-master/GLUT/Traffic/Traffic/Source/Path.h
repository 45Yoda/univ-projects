#pragma once

#include <iostream>
#include <vector>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"

#include "Parser.h"



using namespace glm;
using namespace std;

class Path {

	public:

		struct Segment {
			vec3 a;
			vec3 b;
			vec3 c;
			vec3 d;
		};


		Path() {};

		void generatePath();
		void pushInfo(long long id, vec3 points);

		vector<Segment> segments;

		// isIntersection flag values: 0 not intersection, 1 intersection at start, 2 intersection at end;
		int isIntersection = 0;

		long long intersectionPoint;
		

		vec3 getPoint(int segment, float t);

		vec3 getDerivative(int segment, float t);
		
		bool isEmpty();

		bool wasPushed(long long id);

		int getSegmentNumber();

		//float calcDistance();

		//float calcDistanceJunc(vector<Parser::Node*>junc);

		//float calcDelta(float distance, float speed);


		void calcDistanceBetween(vec3 node1, vec3 node2);
		
		vector<float> calcDeltaTs(float speed);

		vector<float> recalcDeltaTs(float speed, vector<float> oldDeltas, int currentSegment);

		vector<float> distances; 
		

		void askInfo();

		vector<long long> getInfo();

		vector<vec3> getPoints();

	private:

		void generateSegment(vector<vec3>pointList);

		void removeInfo();

		vector<vec3> points;
		vector<long long> ids;
};