//
// Created by yoda45 on 01-03-2018.
//

#include "plane.h"

using std::vector;


vector<Point*> plane(float size, vector<Point*> *normals,vector<Point*> *textures){
    vector<Point*> points;
    float side;

    //calculate side of square
    side = size/2;



    //Push points into vector

    //First triangle
    points.push_back(new Point(side,0.0f,side));
    normals->push_back(new Point(0,1,0));
    textures->push_back(new Point(1,1,0));

    points.push_back(new Point(side,0.0f,-side));
    normals->push_back(new Point(0,1,0));
    textures->push_back(new Point(1,0,0));


    points.push_back(new Point(-side,0.0f,side));
    normals->push_back(new Point(0,1,0));
    textures->push_back(new Point(0,1,0));


    //Second triangle
    points.push_back(new Point(-side,0.0f,-side));
    normals->push_back(new Point(0,1,0));
    textures->push_back(new Point(0,0,0));

    points.push_back(new Point(-side,0.0f,side));
    normals->push_back(new Point(0,1,0));
    textures->push_back(new Point(0,1,0));

    points.push_back(new Point(side,0.0f,-side));
    normals->push_back(new Point(0,1,0));
    textures->push_back(new Point(1,0,0));

    return points;

}