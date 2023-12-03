//
// Created by yoda45 on 4/7/18.
//

#ifndef GENERATOR_TORUS_H
#define GENERATOR_TORUS_H

#include <vector>
#include "point.h"

using std::vector;

vector<Point*> torus(float radiusIn, float radiusOut, int sides, int rings,vector<Point*> *normals,vector<Point*> *textures);


#endif //GENERATOR_TORUS_H
