#include "path.h"




const float alpha = 0.5;
const float tension = 0;


void Path::generateSegment(vector<vec3> pointlist) {

	vec3 p0 = pointlist[0];
	vec3 p1 = pointlist[1];
	vec3 p2 = pointlist[2];
	vec3 p3 = pointlist[3];

	float t01 = pow(distance(p0, p1), alpha);
	float t12 = pow(distance(p1, p2), alpha);
	float t23 = pow(distance(p2, p3), alpha);



	vec3 m1 = (1.0f - tension) * (p2 - p1 + t12 * ((p1 - p0) / t01 - (p2 - p0) / (t01 + t12)));
	vec3 m2 = (1.0f - tension) * (p2 - p1 + t12 * ((p3 - p2) / t23 - (p3 - p1) / (t12 + t23)));


	Segment segment;
	segment.a = 2.0f * (p1 - p2) + m1 + m2;
	segment.b = -3.0f * (p1 - p2) - m1 - m1 - m2;
	segment.c = m1;
	segment.d = p1;


	segments.push_back(segment);
}




vec3 Path::getDerivative(int segment, float t) {

	vec3 der = segments[segment].a * 3.0f * t * t
		+ segments[segment].b * 2.0f * t
		+ segments[segment].c;


	return der;
}

vec3 Path::getPoint(int segment, float t) {
	
	vec3 point = segments[segment].a * t * t * t 
		+ segments[segment].b * t * t 
		+ segments[segment].c * t 
		+ segments[segment].d;

	
	return point;
}


int Path::getSegmentNumber() {
	return segments.size();
}

void Path::generatePath() {

	vector<vec3> segmentPoints;

	if (points.size() < 2) {

		cout << "ERRO NAO DA COM MENOS QUE 2" << endl;
	}


	// Get the change in x and z between the first and second coordinates
	float dx = points[1].x - points[0].x;
	float dz = points[1].z - points[0].z;

	// then using the change, extrapolate backwards to find a control point.
	float x1 = points[0].x - dx;
	float z1 = points[0].z - dz;

	// create start point from extrapolated values.
	vec3 start(x1, 0, z1);

	// repeat for end control point
	int n = points.size() - 1;
	dx = points[n].x - points[n - 1].x;
	dz = points[n].z - points[n - 1].z;

	// extrapolate forwards to find a control point

	float xn = points[n].x + dx;
	float zn = points[n].z + dz;

	// create end point from extrapolated values
	vec3 end(xn, 0, zn);

	//insert the start control point at the start of the vertices list
	points.insert(points.begin(), start);

	//append the end control point to the end of the vertices list
	points.push_back(end);

	
	for (int i = 0; i < points.size() - 3; i++) {

		// Insert other points
		segmentPoints.push_back(points[i]);
		segmentPoints.push_back(points[i+1]);
		segmentPoints.push_back(points[i+2]);
		segmentPoints.push_back(points[i+3]);

		
		/*cout << "1� " << segmentPoints[0].x << " " << segmentPoints[0].z << endl;
		cout << "2� " << segmentPoints[1].x << " " << segmentPoints[1].z << endl;
		cout << "3� " << segmentPoints[2].x << " " << segmentPoints[2].z << endl;
		cout << "4� " << segmentPoints[3].x << " " << segmentPoints[3].z << endl;*/


		// Generate spline segment
		generateSegment(segmentPoints);
		segmentPoints.clear();
	}


	// TooBad Commented this. Be careful if it  fucks everything up.
	//removeInfo();
}

void Path::pushInfo(long long id, vec3 point) {

	points.push_back(point);
	ids.push_back(id);

}

vector<long long> Path::getInfo() {
	return ids;
}

vector<vec3> Path::getPoints() {
	return points;
}

bool Path::isEmpty() {
	
	return points.size() == 0 ? true : false;

}

bool Path::wasPushed(long long id) {

	if (ids.size() == 0) {
		return false;
	}
	else {
		return ids[ids.size()-1] == id ? true : false;
	}

}

void Path::removeInfo() {

	points.clear();
	ids.clear();
}



void Path::calcDistanceBetween(vec3 node1, vec3 node2) {
	
	float totalDistance = sqrt(pow(node2.x - node1.x, 2) + pow(node2.z - node1.z, 2));

	distances.push_back(totalDistance);
}

vector<float> Path::calcDeltaTs(float speed) {

	float delta;
	vector<float> deltaTs;


	for (auto const& dist : distances) {


		delta = dist / speed;

		deltaTs.push_back(delta);
	}

	return deltaTs;

}

vector<float> Path::recalcDeltaTs(float speed, vector<float> oldDeltas, int currentSegment) {

	float delta;
	vector<float> deltaTs;


	for (auto const& dist : distances) {


		delta = dist / speed;

		deltaTs.push_back(delta);
	}

	deltaTs[currentSegment] = oldDeltas[currentSegment];

	return deltaTs;

}


void Path::askInfo() {

	cout << "this IS the SIZE of Segments" << endl;
	cout << segments.size() << endl;
	cout << "this is size of distances" << endl;
	cout << distances.size() << endl;
}

