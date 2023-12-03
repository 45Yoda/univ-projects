//#pragma once
//
//#include "Path1.h"
//#include <GL/freeglut.h>
//#include "glm/glm.hpp"
//#include <vector>
//
//
//#include <iostream>
//
//using namespace std;
//using namespace glm;
//
//class Path {
//
//public:
//	float x, y, z;
//
//	Path() {
//		x = 0;
//		y = 0;
//		z = 0;
//		aux[0] = 0;
//		aux[1] = 1;
//		aux[2] = 0;
//
//		 //TODO remove this parse()
//		parse(); 
//	};
//	
//	void getPoints();
//
//	void apply();
//	void parse();
//	void pushInfo(long long id, vec3 point);
//
//private:
//
//
//	vector<long long> ids;
//	vector<vec3> points;
//	vector<vec3> curvePoints;
//	float time = 60;
//	float aux[3];
//	
//	int flag = 1;
//	float save[3];
//
//	void getCatmullRomPoint(float t, int* indices, float* pos, float* deriv, vector<vec3> points);
//	void getGlobalCatmullRomPoint(float gt, float* pos, float* deriv, vector<vec3> points);
//
//	void cross(float* a, float* b, float* res);
//	void normalize(float* a);
//
//	vector<vec3> generateCurvePoints();
//	void renderCatmullRomCurve(vector<vec3> points);
//	void curveRotation(float* der, float* aux);
//	
//
//};