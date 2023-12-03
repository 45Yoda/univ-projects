#include "sphere.h"
#include "point.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using std::vector;

void xyz_uv(float x, float y, float z, float* u, float* v);

vector<Point*> sphere(float radius, int slices, int stacks,vector<Point*> *normals, vector<Point*> *textures) {

    vector<Point*> points;
    int i, j;
    float angleH = 0, angleV = 0;
    float shiftV = M_PI / stacks;
    float shiftH = (2 * M_PI) / slices;
    float x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4,u,v;

    for (i = 0; i < stacks; i++) {
        angleV = shiftV * i;

        for (j = 0; j < slices; j++) {

            angleH = shiftH * j;

            x1 = radius * sin(angleH) * sin(angleV);
            y1 = radius * cos(angleV);
            z1 = radius * sin(angleV) * cos(angleH);

            x2 = radius * sin(angleV) * sin(angleH + shiftH);
            y2 = radius * cos(angleV);
            z2 = radius * sin(angleV) * cos(angleH + shiftH);

            x3 = radius * sin(angleV + shiftV) * sin(angleH + shiftH);
            y3 = radius * cos(angleV + shiftV);
            z3 = radius * sin(angleV + shiftV) * cos(angleH + shiftH);

            x4 = radius * sin(angleV + shiftV) * sin(angleH);
            y4 = radius * cos(angleV + shiftV);
            z4 = radius * sin(angleV + shiftV) * cos(angleH);


            points.push_back(new Point(x1, y1, z1));
            normals->push_back(new Point(x1,y1,z1));
            xyz_uv(x1,y1,z1,&u,&v);
            textures->push_back(new Point(u,v,0));


            points.push_back(new Point(x3, y3, z3));
            normals->push_back(new Point(x3,y3,z3));
            xyz_uv(x3,y3,z3,&u,&v);
            textures->push_back(new Point(u,v,0));


            points.push_back(new Point(x2, y2, z2));
            normals->push_back(new Point(x2,y2,z2));
            xyz_uv(x2,y2,z2,&u,&v);
            textures->push_back(new Point(u,v,0));


            points.push_back(new Point(x1,y1,z1));
            normals->push_back(new Point(x1,y1,z1));
            xyz_uv(x1,y1,z1,&u,&v);
            textures->push_back(new Point(u,v,0));

            points.push_back(new Point(x4,y4,z4));
            normals->push_back(new Point(x3,y3,z3));
            xyz_uv(x4,y4,z4,&u,&v);
            textures->push_back(new Point(u,v,0));

            points.push_back(new Point(x3,y3,z3));
            normals->push_back(new Point(x4,y4,z4));
            xyz_uv(x3,y3,z3,&u,&v);
            textures->push_back(new Point(u,v,0));


        }
    }

    return points;
}

void xyz_uv(float x, float y, float z, float* u, float* v){

    *u= 0.5 + atan2(z,x)/(2*M_PI);
    *v= 0.5 - asin(y) / M_PI;

}
