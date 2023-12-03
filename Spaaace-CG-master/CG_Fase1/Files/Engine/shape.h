#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <string>
#include <vector>
#include "../Generator/vertex.h"

using namespace std;

class Shape{

    int id;
    vector<Vertex*> vertexes;

public:
    Shape(int,vector<Vertex*>);
    int getID();
    vector<Vertex*> getVertexes();
};

#endif