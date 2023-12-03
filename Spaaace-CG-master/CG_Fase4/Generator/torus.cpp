//
// Created by yoda45 on 4/7/18.
//

#include "torus.h"
#include <math.h>

vector<Point*> torus(float radiusSmall, float radiusBig, int sides, int rings,vector<Point*> *normals,vector<Point*> *textures){

    vector<Point*> points;

    float sideSize = (2*M_PI)/sides;
    float ringSize = (2*M_PI)/rings;

    float sideText = 1.0f/sides;
    float ringText = 1.0f/rings;

    for(int i=0; i < rings; i++){
        double alpha = i*ringSize;
        double nextalpha = alpha + ringSize;

        float x0 = cos(alpha);
        float y0 = sin(alpha);
        float x1 = cos(nextalpha);
        float y1 = sin(nextalpha);

        for(int j=0; j < sides+1; j++){

            //current points
            float s = cos(j*sideSize);
            float r = radiusSmall * s + radiusBig;
            float z = radiusSmall * sin(j*sideSize);

            //next points
            float nexts = cos((j+1)*sideSize);
            float nextr = radiusSmall * nexts + radiusBig;
            float nextz = radiusSmall * sin((j+1)*sideSize);

            points.push_back(new Point(x0*r,y0*r,z));
            points.push_back(new Point(x1*r,y1*r,z));
            points.push_back(new Point(x0*nextr,y0*nextr,nextz));
            normals->push_back(new Point(x0*cos(j*sideSize),y0*cos(j*sideSize),sin(j*sideSize)));
            normals->push_back(new Point(x1*cos(j*sideSize),y1*cos(j*sideSize),sin(j*sideSize)));
            normals->push_back(new Point(x0*cos((j+1)*sideSize),y0*cos((j+1)*sideSize),sin((j+1)*sideSize)));
            textures->push_back(new Point(i*ringText,j*sideText,0));
            textures->push_back(new Point((i+1)*ringText,j*sideText,0));
            textures->push_back(new Point(i*ringText,(j+1)*sideText,0));



            points.push_back(new Point(x0*nextr,y0*nextr,nextz));
            points.push_back(new Point(x1*r,y1*r,z));
            points.push_back(new Point(x1*nextr,y1*nextr,nextz));
            normals->push_back(new Point(x0*cos((j+1)*sideSize),y0*cos((j+1)*sideSize),sin((j+1)*sideSize)));
            normals->push_back(new Point(x1*cos(j*sideSize),y1*cos(j*sideSize),sin(j*sideSize)));
            normals->push_back(new Point(x1*cos((j+1)*sideSize),y1*cos((j+1)*sideSize),sin((j+1)*sideSize)));
            textures->push_back(new Point(i*ringText,(j+1)*sideText,0));
            textures->push_back(new Point((i+1)*ringText,j*sideText,0));
            textures->push_back(new Point((i+1)*ringText,(j+1)*sideText,0));
        }
    }

    return points;
}