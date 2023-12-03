//
// Created by yoda45 on 01-03-2018.
//

#ifndef SPAAACE_CG_PLANE_H
#define SPAAACE_CG_PLANE_H


#include "point.h"
#include <vector>

/**
 * Generates a square in the XZ plane, centered in the origin
 * made with 2 triangles
 * @param size of square
 * @return vector with generated vertexes for plane
 */

using namespace std;

vector<Point*> plane(float size,vector<Point*> *normals,vector<Point*> *textures);


#endif //SPAAACE_CG_PLANE_H
