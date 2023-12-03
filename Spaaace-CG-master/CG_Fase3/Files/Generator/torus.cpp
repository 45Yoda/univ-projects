//
// Created by yoda45 on 4/7/18.
//

#include "torus.h"
#include <math.h>

vector<Vertex*> torus(float radiusSmall, float radiusBig, int sides, int rings){

    vector<Vertex*> vertexes;

    float sideSize = (2*M_PI)/sides;
    float ringSize = (2*M_PI)/rings;

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

            vertexes.push_back(new Vertex(x0*r,y0*r,z));
            vertexes.push_back(new Vertex(x1*r,y1*r,z));
            vertexes.push_back(new Vertex(x0*nextr,y0*nextr,nextz));

            vertexes.push_back(new Vertex(x0*nextr,y0*nextr,nextz));
            vertexes.push_back(new Vertex(x1*r,y1*r,z));
            vertexes.push_back(new Vertex(x1*nextr,y1*nextr,nextz));
        }
    }

    return vertexes;
}