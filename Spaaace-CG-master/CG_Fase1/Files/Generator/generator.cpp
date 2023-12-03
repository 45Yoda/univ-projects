#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include "vertex.h"
#include "plane.h"
#include "box.h"
#include "cone.h"
#include "sphere.h"
#include "torus.h"


using std::ofstream;
using std::string;
using std::vector;

void drawPlane(float size, string name){
    ofstream file(name);
    char buffer[1024];
    vector<Vertex*> vertexes = plane(size);

    for(Vertex* v: vertexes){
        sprintf(buffer,"%f %f %f\n",v->getX(),v->getY(),v->getZ());
        file << buffer;
    }
    file.close();
}

void drawBox(float x, float y, float z, int div, string name){
    ofstream file(name);
    char buffer[1024];
    vector<Vertex*> vertexes = box(x,y,z,div);

    for(Vertex* v: vertexes){
        sprintf(buffer,"%f %f %f\n",v->getX(),v->getY(),v->getZ());
        file << buffer;
    }

    file.close();
}

void drawSphere(float radius, int slices, int stacks, string name){
    ofstream file(name);
    char buffer[1024];
    vector<Vertex*> vertexes = sphere(radius,slices,stacks);

    for(Vertex* v: vertexes){
        sprintf(buffer,"%f %f %f\n",v->getX(),v->getY(),v->getZ());
        file << buffer;
    }

    file.close();
}

void drawCone(float radius, float height, int slices, int stacks, string name){
    ofstream file(name);
    char buffer[1024];
    vector<Vertex*> vertexes = cone(radius,height,slices,stacks);

    for(Vertex* v: vertexes){
        sprintf(buffer,"%f %f %f\n",v->getX(),v->getY(),v->getZ());
        file << buffer;
    }

    file.close();
}

void drawTorus(float radiusSmall, float radiusBig, int sides, int rings,string name) {
    ofstream file(name);
    char buffer[1024];
    vector<Vertex*> vertexes = torus(radiusSmall,radiusBig,sides,rings);

    for(Vertex* v: vertexes){
        sprintf(buffer,"%f %f %f\n",v->getX(),v->getY(),v->getZ());
        file << buffer;
    }

    file.close();
}

void print_help(){
    std::cout<<"#****************************************************************#" << std::endl;
    std::cout<<"*                              HELP                              *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    Usage: ./generator {SHAPE} [OPTIONS] {FILE}                 *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    {SHAPE} & [OPTIONS]:                                        *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    - plane [SIZE]                                              *" << std::endl;
    std::cout<<"*      Creates a square in the XZ plane, centered in the origin. *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    - box [X SIZE] [Y SIZE] [Z SIZE] opt:[DIVISIONS]            *" << std::endl;
    std::cout<<"*      Creates a box with x,y and z dimensions specified and     *" << std::endl;
    std::cout<<"*      optionally the number of divisions.                       *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    - sphere [RADIUS] [SLICES] [STACKS]                         *" << std::endl;
    std::cout<<"*      Creates a sphere with the radius, number of slices and    *" << std::endl;
    std::cout<<"*      number of stacks specified.                               *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    - cone [RADIUS] [HEIGHT] [SLICES] [STACKS]                  *" << std::endl;
    std::cout<<"*      Creates a cone with the bottom radius, height, number of  *" << std::endl;
    std::cout<<"*      slices and stacks specified.                              *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    {FILE}:                                                     *" << std::endl;
    std::cout<<"*      In this section you give the name of the file which will  *" << std::endl;
    std::cout<<"*      contain the vertexes generated with the previous commands.*" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    COMPILING:                                                  *" << std::endl;
    std::cout<<"*       g++ -o generator *.*                                     *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"#****************************************************************#" << std::endl;
}

int main(int argc, char** argv) {

    if(argc < 2) {
        std::cout << "halp meh"  << std::endl;
        print_help();
    }
    else if(!strcmp(argv[1],"plane") && argc == 4) {
        std::cout << "plane";
        drawPlane(atof(argv[2]), argv[3]);
    }
    else if(!strcmp(argv[1],"box") && (argc == 6 || argc == 7 )) {
        std::cout << "box";

        if (argc == 6) {  //No divisions
            drawBox(atof(argv[2]),
                    atof(argv[3]),
                    atof(argv[4]),
                    1,
                    argv[5]);
        }

        else{  //Divisions
            drawBox(atof(argv[2]),
                    atof(argv[3]),
                    atof(argv[4]),
                    atof(argv[5]),
                    argv[6]);

        }
    }
    else if(!strcmp(argv[1],"sphere") && argc == 6) {
        std::cout << "sphere";
        drawSphere(atof(argv[2]),
                   atoi(argv[3]),
                   atoi(argv[4]),
                   argv[5]);
    }
    else if(!strcmp(argv[1],"cone") && argc == 7){
        std::cout << "cone";
        drawCone(atof(argv[2]),
                 atof(argv[3]),
                 atoi(argv[4]),
                 atoi(argv[5]),
                 argv[6]);
        }
    else if(!strcmp(argv[1],"torus") && argc == 7){
        std::cout << "torus";
        drawTorus(atof(argv[2]),
                  atof(argv[3]),
                  atoi(argv[4]),
                  atoi(argv[5]),
                  argv[6]);
        }
    else {
        std::cout << "halp meh"  << std::endl;
        print_help();
    }
    return 0;
}


