
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

GLuint Shape::getVertexBuffer(){
    return buffer;
}

void Shape::readyUp(){

    int index = 0;
    float* vertex = (float*) malloc(sizeof(float) * vertexes.size() * 3);

    //Set the Data
    for(vector<Vertex*>::const_iterator v_it = vertexes.begin(); v_it != vertexes.end(); ++v_it){
        vertex[index] = (*v_it)->getX();
        vertex[index+1] = (*v_it)->getY();
        vertex[index+2] = (*v_it)->getZ();
        index+=3;
    }


    //Generate and Bind the Vertex Buffer
    //Get a valid name
    glGenBuffers(1, &buffer);
    //Bind the Buffer
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    //Load the Data
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * index, vertex, GL_STATIC_DRAW);

    //The Data is in the Graphics Card, it isn't needed anymore
    free(vertex);
}

void Shape::draw(){
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    //Set the Vertex Pointer to the vertex buffer
    glVertexPointer(3, GL_FLOAT, 0, nullptr);
    //Draw all Triangles at once
    glDrawArrays(GL_TRIANGLES, 0, vertexes.size()*3);
}