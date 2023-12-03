#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <string>
#include <vector>
#include "../Generator/vertex.h"

using namespace std;

class Shape{

    string name;
    vector<Vertex*> vertexes;

    public:
        Shape();
        Shape(string,vector<Vertex*>);
        string getName();
        vector<Vertex*> getVertexes();
};

#endif