#ifndef __SPHERE_H__
#define __SPHERE_H__

#include <vector>

#include "point.h"

using std::vector;

vector<Point*> sphere(float radius, int slices, int stacks,vector<Point*> *normals, vector<Point*> *textures);

#endif
