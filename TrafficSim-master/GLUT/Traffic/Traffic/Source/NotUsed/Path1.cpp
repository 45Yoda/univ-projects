//
//#include "Path1.h"
//
//vec3 last_point;
//
//
//void Path::getCatmullRomPoint(float t, int* indices, float* pos, float* deriv, vector<vec3> points) {
//
//	float t2 = t * t;
//	float t3 = t * t * t;
//	float posAux[4];
//	float derivAux[4];
//
//	vec3 p0 = points[indices[0]];
//	vec3 p1 = points[indices[1]];
//	vec3 p2 = points[indices[2]];
//	vec3 p3 = points[indices[3]];
//
//	float m[4][4] = { {-0.5f, 1.5f, -1.5f, 0.5f},
//						{ 1.0f, -2.5f, 2.0f, -0.5f},
//						{-0.5f, 0.0f, 0.5f, 0.0f},
//						{ 0.0f, 1.0f, 0.0f, 0.0f},
//	};
//
//	pos[0] = 0.0;
//	pos[1] = 0.0;
//	pos[2] = 0.0;
//	deriv[0] = 0.0;
//	deriv[1] = 0.0;
//	deriv[2] = 0.0;
//
//
//	 //Compute A = M * P
//	posAux[0] = t3 * m[0][0] + t2 * m[1][0] + t * m[2][0] + m[3][0];
//	posAux[1] = t3 * m[0][1] + t2 * m[1][1] + t * m[2][1] + m[3][1];
//	posAux[2] = t3 * m[0][2] + t2 * m[1][2] + t * m[2][2] + m[3][2];
//	posAux[3] = t3 * m[0][3] + t2 * m[1][3] + t * m[2][3] + m[3][3];
//
//	derivAux[0] = (3 * t2) * m[0][0] + (2 * t) * m[1][0] + m[2][0];
//	derivAux[1] = (3 * t2) * m[0][1] + (2 * t) * m[1][1] + m[2][1];
//	derivAux[2] = (3 * t2) * m[0][2] + (2 * t) * m[1][2] + m[2][2];
//	derivAux[3] = (3 * t2) * m[0][3] + (2 * t) * m[1][3] + m[2][3];
//
//
//	 //Compute pos = T * A
//	pos[0] = posAux[0] * p0.x + posAux[1] * p1.x + posAux[2] * p2.x + posAux[3] * p3.x;
//	pos[1] = posAux[0] * p0.y + posAux[1] * p1.y + posAux[2] * p2.y + posAux[3] * p3.y;
//	pos[2] = posAux[0] * p0.z + posAux[1] * p1.z + posAux[2] * p2.z + posAux[3] * p3.z;
//
//	 //Compute deriv = T' * A
//	deriv[0] = derivAux[0] * p0.x + derivAux[1] * p1.x + derivAux[2] * p2.x + derivAux[3] * p3.x;
//	deriv[1] = derivAux[0] * p0.y + derivAux[1] * p1.y + derivAux[2] * p2.y + derivAux[3] * p3.y;
//	deriv[2] = derivAux[0] * p0.z + derivAux[1] * p1.z + derivAux[2] * p2.z + derivAux[3] * p3.z;
//
//}
//
//
// //Given  global t, returns the point in the curve
//void Path::getGlobalCatmullRomPoint(float gt, float* pos, float* deriv, vector<vec3> points) {
//	int POINT_COUNT = points.size();
//	float t = gt * POINT_COUNT; // this is the real global t
//	int index = floor(t);  // which segment
//	t = t - index; // where within  the segment
//
//	// Indices store the points
//	int indices[4];
//	//cout << indices[0] << endl;
//	indices[0] = (index + POINT_COUNT - 1) % POINT_COUNT;
//	indices[1] = (indices[0] + 1) % POINT_COUNT;
//	indices[2] = (indices[1] + 1) % POINT_COUNT;
//	indices[3] = (indices[2] + 1) % POINT_COUNT;
//
//	getCatmullRomPoint(t, indices, pos, deriv, points);
//}
//
//void Path::cross(float* a, float* b, float* res) {
//
//	res[0] = a[1] * b[2] - a[2] * b[1];
//	res[1] = a[2] * b[0] - a[0] * b[2];
//	res[2] = a[0] * b[1] - a[1] * b[0];
//}
//
//
//void Path::normalize(float* a) {
//
//	float l = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
//	a[0] = a[0] / l;
//	a[1] = a[1] / l;
//	a[2] = a[2] / l;
//}
//
//vector<vec3> Path::generateCurvePoints() {
//	float pos[3];
//	float deriv[3];
//
//	for (float t = 0; t < 1; t += 0.01) {
//		getGlobalCatmullRomPoint(t, pos, deriv, points);
//		vec3 v(pos[0], pos[1], pos[2]);
//		curvePoints.push_back(v);
//	}
//
//	return curvePoints;
//}
//
//void Path::renderCatmullRomCurve(vector<vec3> points) {
//	int size = points.size();
//	float p[3];
//
//	glBegin(GL_LINE_LOOP);
//	for (int i = 0; i < size; i++) {
//		p[0] = points[i].x;
//		p[1] = points[i].y;
//		p[2] = points[i].z;
//		glVertex3fv(p);
//	}
//	glEnd();
//}
//
//void Path::curveRotation(float* der, float* aux) {
//
//	float left[3];
//
//	cross(der, aux, left);
//	cross(left, der, aux);
//
//	normalize(der);
//	normalize(aux);
//	normalize(left);
//
//	float m[4][4] = { {der[0], der[1], der[2], 0},
//					  {aux[0], aux[1], aux[2], 0},
//					  {left[0], left[1], left[2], 0},
//					  {0.0f,0.0f,0.0f, 1}
//	};
//	glMultMatrixf((float*)m);
//}
//
//
//
//
//void Path::getPoints() {
//	for (int i = 0; i < points.size(); i++) { cout << points[i].x << "," << points[i].y << "," << points[i].z << endl; }
//}
//
// //TODO change to actual parsing
//
//
//void Path::parse() {
//
//	/*
//	vec3 v0(30, 0, 0);
//	vec3 v1(22, 0, 22);
//
//
//	vec3 v2(0, 0, 30);
//	vec3 v3(-22, 0, 22);
//
//	last_point = v3;
//
//
//	vec3 v4(-30, 0, 0);
//	vec3 v5(-22, 0, -22);
//	vec3 v6(0, 0, -30);
//	vec3 v7(22, 0, -22);*/
//
//	
//	//vec3 v0(0, 0, 0);
//	//vec3 v1(0, 10, 0);
//	//vec3 v2(0, 20, 0);
//	//vec3 v3(0, 30, 0);
//	//vec3 v4(-30, 0, 0);
//	//vec3 v5(-22, 0, -22);
//	//vec3 v6(0, 0, -30);
//	//vec3 v7(22, 0, -22);
//	
//	
//	vec3 v0(41.084379, 0.0, -7.7356504);
//	vec3 v1(41.3088711, 0.0, -7.7358941);
//	//vec3 v2(41.3092561, 0.0, -7.7360674);
//	//vec3 v3(41.3096007, 0.0, -7.7362099);
//	
//
//	points.push_back(v0);
//	points.push_back(v1);
//	//points.push_back(v2);
//	//points.push_back(v3);
//	/*points.push_back(v4);
//	points.push_back(v5);
//	points.push_back(v6);
//	points.push_back(v7);*/
//
//
//}
//
//// TODO Change to make relevant to deltaTime 
//
//void Path::apply() {
//
//	float te, gt;
//	float res[3];
//	float deriv[3];
//
//
//	//renderCatmullRomCurve(points);
//
//	time = 1;
//
//	if (time != 0) {
//		te = glutGet(GLUT_ELAPSED_TIME) % (int)(1000);
//		gt = te / (1000);
//		vector<vec3> vp2 = generateCurvePoints();
//		renderCatmullRomCurve(vp2);
//
//		getGlobalCatmullRomPoint(gt, res, deriv, points);
//		curvePoints.clear();
//		glTranslatef(res[0], res[1], res[2]);
//
//		
//		/*
//		if (last_point.x == res[0] && last_point.y == res[1] && last_point.z == res[2]) {
//			time = 0.0f;
//			x = res[0];
//			y = res[1];
//			z = res[2];
//		}*/
//
//
//		curveRotation(deriv, aux);
//
//		return;
//	}
//
//	glTranslatef(x, y, z);
//}
//
//
//void Path::pushInfo(long long id, vec3 point) {
//
//	points.push_back(point);
//	ids.push_back(id);
//
//}