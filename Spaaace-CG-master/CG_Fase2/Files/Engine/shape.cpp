#include "shape.h"


Shape::Shape(){

}

Shape::Shape(string i, vector<Vertex*> list){
    name = i;
    vertexes = list;
}

string Shape::getName(){
    return name;
}

vector<Vertex*> Shape::getVertexes(){
    return vertexes;
}
