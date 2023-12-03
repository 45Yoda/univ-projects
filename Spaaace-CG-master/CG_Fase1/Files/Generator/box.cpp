#include "box.h"

vector<Vertex*> box(float x, float y, float z, int div){

    vector<Vertex*> vertexes;
    float shiftX = x/div;
    float shiftY = y/div;
    float shiftZ = z/div;
    x = x/2;
    y = y/2;
    z = z/2;


    for(int i=0;i<div;i++){
        for(int j=0;j<div;j++){
            //Front
            vertexes.push_back(new Vertex(-x + (j*shiftX),-y + (i*shiftY),z));
            vertexes.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y + (i*shiftY),z));
            vertexes.push_back(new Vertex(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),z));

            vertexes.push_back(new Vertex(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),z));
            vertexes.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y + (i*shiftY),z));
            vertexes.push_back(new Vertex((-x+shiftX) + (j*shiftX),(-y+shiftY) + (i*shiftY),z));


            //Back
            vertexes.push_back(new Vertex(-x + (j*shiftX),-y + (i*shiftY),-z));
            vertexes.push_back(new Vertex(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
            vertexes.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y + (i*shiftY),-z));

            vertexes.push_back(new Vertex(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
            vertexes.push_back(new Vertex((-x+shiftX) + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
            vertexes.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y + (i*shiftY),-z));

            //Right
            vertexes.push_back(new Vertex(x,-y + (i*shiftY),-z + (j*shiftZ)));
            vertexes.push_back(new Vertex(x,(-y+shiftY) + (i*shiftY),-z +(j*shiftZ)));
            vertexes.push_back(new Vertex(x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
            vertexes.push_back(new Vertex(x,(-y+shiftY) + (i*shiftY),-z + (j*shiftZ)));
            vertexes.push_back(new Vertex(x,(-y+shiftY) + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
            vertexes.push_back(new Vertex(x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));

            //Left
            vertexes.push_back(new Vertex(-x,-y + (i*shiftY),-z + (j*shiftZ)));
            vertexes.push_back(new Vertex(-x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
            vertexes.push_back(new Vertex(-x,(-y+shiftY) + (i*shiftY),-z +(j*shiftZ)));

            vertexes.push_back(new Vertex(-x,(-y+shiftY) + (i*shiftY),-z + (j*shiftZ)));
            vertexes.push_back(new Vertex(-x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
            vertexes.push_back(new Vertex(-x,(-y+shiftY) + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));

            //Top
            vertexes.push_back(new Vertex(-x + (j*shiftX),y,-z + (i*shiftZ)));
            vertexes.push_back(new Vertex(-x + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
            vertexes.push_back(new Vertex((-x+shiftX) + (j*shiftX),y,-z + (i*shiftZ)));

            vertexes.push_back(new Vertex(-x + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
            vertexes.push_back(new Vertex((-x+shiftX) + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
            vertexes.push_back(new Vertex((-x+shiftX) + (j*shiftX),y,-z + (i*shiftZ)));

            //Bottom
            vertexes.push_back(new Vertex(-x + (j*shiftX),-y,-z + (i*shiftZ)));
            vertexes.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y,-z + (i*shiftZ)));
            vertexes.push_back(new Vertex(-x + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));

            vertexes.push_back(new Vertex(-x + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));
            vertexes.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y,-z + (i*shiftZ)));
            vertexes.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));
        }
    }
    return vertexes;
}