//
// Created by yoda45 on 5/17/18.
//

#ifndef GENERATOR_LIGHT_H
#define GENERATOR_LIGHT_H


#include "../Generator/point.h"

class Light {

    bool pointType;
    Point* point;

    public:
        Light();
        Light(bool,Point*);
        bool getType();
        Point* getPoint();
        void setType(bool);
        void setPoint(Point*);
        void draw();
};


#endif //GENERATOR_LIGHT_H
