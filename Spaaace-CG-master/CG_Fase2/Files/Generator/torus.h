//
// Created by yoda45 on 4/7/18.
//

#ifndef GENERATOR_TORUS_H
#define GENERATOR_TORUS_H

#include <vector>
#include "vertex.h"

using namespace std;

std::vector<Vertex*> torus(float radiusIn, float radiusOut, int sides, int rings);


#endif //GENERATOR_TORUS_H
