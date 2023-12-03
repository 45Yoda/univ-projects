#include "sphere.h"
#include "vertex.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using std::vector;



std::vector<Vertex*> sphere(float radius, int slices, int stacks) {

    std::vector<Vertex*> vertexes;
    int i, j;
    float angleH = 0, angleV = 0;
    float shiftV = M_PI / stacks;
    float shiftH = (2 * M_PI) / slices;
    float x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;

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


            vertexes.push_back(new Vertex(x1, y1, z1));
            vertexes.push_back(new Vertex(x3, y3, z3));
            vertexes.push_back(new Vertex(x2, y2, z2));

            vertexes.push_back(new Vertex(x1,y1,z1));
            vertexes.push_back(new Vertex(x4,y4,z4));
            vertexes.push_back(new Vertex(x3,y3,z3));

        }
    }

    return vertexes;
}
