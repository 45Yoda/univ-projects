//
// Created by yoda45 on 01-03-2018.
//

#include "point.h"

//Estrutura de um ponto contem as coordenadas x, y e z;

Point::Point(){

}

Point::Point(float ax, float ay, float az){
    x = ax;
    y = ay;
    z = az;
}

float Point::getX(){
    return x;
}

float Point::getY(){
    return y;
}

float Point::getZ(){
    return z;
}

void Point::setX(float x) {
    Point::x = x;
}

void Point::setY(float y) {
    Point::y = y;
}

void Point::setZ(float z) {
    Point::z = z;
}
