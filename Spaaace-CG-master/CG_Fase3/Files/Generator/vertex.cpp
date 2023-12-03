//
// Created by yoda45 on 01-03-2018.
//

#include "vertex.h"

//Estrutura de um vertice contem as coordenadas x, y e z;

Vertex::Vertex(float ax, float ay, float az){
    x = ax;
    y = ay;
    z = az;
}

float Vertex::getX(){
    return x;
}

float Vertex::getY(){
    return y;
}

float Vertex::getZ(){
    return z;
}