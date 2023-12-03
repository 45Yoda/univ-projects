//
// Created by yoda45 on 5/18/18.
//

#ifndef GENERATOR_MATERIAL_H
#define GENERATOR_MATERIAL_H


#include "action.h"

class Material {

    float diffuse[4]; //default: {0.8, 0.8, 0.8, 1};
    float ambient[4]; //default: {0.2, 0.2, 0.2, 1};
    float specular[4]; //default: {0, 0, 0, 1};
    float emission[4]; //default: {0, 0, 0, 1};
    float shininess; //default: 0;

    public:
        Material();
        Material(Color*, Color*, Color*, Color*, float);
        void draw();
};


#endif //GENERATOR_MATERIAL_H
