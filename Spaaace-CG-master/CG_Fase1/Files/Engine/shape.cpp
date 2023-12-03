#include "shape.h"


Shape::Shape(int i, vector<Vertex*> list){
    id = i;
    vertexes = list;
}

int Shape::getID(){
    return id;
}

vector<Vertex*> Shape::getVertexes(){
    return vertexes;
}
