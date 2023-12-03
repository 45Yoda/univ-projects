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

void drawTorus(float radiusSmall, float radiusBig, int sides, int rings, string name){
	ofstream file(name);
	char buffer[1024];
	vector<Vertex*> vertexes = torus(radiusSmall,radiusBig,sides,rings);

	for(Vertex* v: vertexes){
		sprintf(buffer,"%f %f %f\n",v->getX(),v->getY(),v->getZ());
		file << buffer;
	}

	file.close();
}

float* bezierCalc( float tt, float *p1 , float *p2 , float *p3 , float *p4) {

    float ite = 1.0 - tt;
    float* ret = new float[3];

    float x0 , x1 , x2 , x3;
    x0 = pow(ite,3);
    x1 = 3 * tt*pow(ite,2);
    x2 = 3 * tt * tt * ite;
    x3 = tt * tt * tt;

    ret[0] = x0*p1[0] + x1*p2[0] + x2*p3[0] + x3*p4[0];
    ret[1] = x0*p1[1] + x1*p2[1] + x2*p3[1] + x3*p4[1];
    ret[2] = x0*p1[2] + x1*p2[2] + x2*p3[2] + x3*p4[2];


    return ret;
}


float* getBezierPoint( float a , float b , int* index , float** points , int ni , int np) {

    float* point;
    float altp[4][3];
    float res[4][3];
    int i , j = 0 , x = 0;
    float *ret;


    for( i = 0 ; i < 16 ; i++) {
        altp[j][0] = points[index[i]][0];
        altp[j][1] = points[index[i]][1];
        altp[j][2] = points[index[i]][2];

        j++;

        if( j % 4 == 0 ) {
            point = bezierCalc(a,altp[0],altp[1],altp[2],altp[3]);
            res[x][0] = point[0];
            res[x][1] = point[1];
            res[x][2] = point[2];

            x++;

            j = 0;
        }

    }
    ret = bezierCalc(b,res[0],res[1],res[2],res[3]);

    return ret;
}

void renderPatch( string file , int tess , string name) {

    ofstream fileo(name);
    string line , aux;
    ifstream filei(file);
    int i;

    if(filei.is_open()) {
        getline(filei,line);
        int npatch = atoi(line.c_str());
        int** indexes = new int*[npatch];
        cout << npatch << endl;

        for(int r = 0 ; r < npatch ; r++) {
            getline(filei,line);
            indexes[r] = new int[16];

            for(int j = 0 ; j < 16 ; j++) {
                i = line.find(",");
                aux = line.substr(0,i);
                indexes[r][j] = atoi(aux.c_str());
                line.erase(0, i + 1);
            }
        }

        getline(filei,line);
        int npoints = atoi(line.c_str());
        cout << npoints << endl;
        float** points = new float*[npoints];

        //get points
        for( int m = 0 ; m < npoints ; m++){
            getline(filei,line);
            points[m] = new float[3];
            for( int l = 0 ; l < 3 ; l++) {
                i = line.find(",");
                aux = line.substr(0,i);
                points[m][l] = atof(aux.c_str());
                line.erase(0 , i + 1);
            }
        }

        float incre = 1.0 / tess , u , v , u2 , v2;
        float *** res = new float**[npatch];

        for(int count = 0 ; count < npatch ; count++) {
            res[count] = new float*[4];

            for( int count2 = 0 ; count2 < tess ; count2++) {

                for( int mn = 0 ; mn < tess ; mn++) {

                    u = count2*incre;
                    v = mn*incre;
                    u2 = (count2 + 1)* incre;
                    v2 = (mn + 1)* incre;

                    res[count][0] = getBezierPoint(u, v, indexes[count], points, npatch, npoints);
                    res[count][1] = getBezierPoint(u, v2, indexes[count], points, npatch, npoints);
                    res[count][2] = getBezierPoint(u2, v, indexes[count], points, npatch, npoints);
                    res[count][3] = getBezierPoint(u2, v2, indexes[count], points, npatch, npoints);


                    fileo << res[count][0][0] << " " << res[count][0][1] << " " << res[count][0][2] << endl;
                    fileo << res[count][2][0] << " " << res[count][2][1] << " " << res[count][2][2] << endl;
                    fileo << res[count][3][0] << " " << res[count][3][1] << " " << res[count][3][2] << endl;

                    fileo << res[count][0][0] << " " << res[count][0][1] << " " << res[count][0][2] << endl;
                    fileo << res[count][3][0] << " " << res[count][3][1] << " " << res[count][3][2] << endl;
                    fileo << res[count][1][0] << " " << res[count][1][1] << " " << res[count][1][2] << endl;
                }
            }

        }
    }

    filei.close();
    fileo.close();
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
    std::cout<<"*    - torus [SMALLRADIUS] [BIGRADIUS] [SIDES] [RINGS]           *" << std::endl;
    std::cout<<"*      Creates a torus with the inner radius, outer radius,      *" << std::endl;
    std::cout<<"*      number of sides and rings specified.                      *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
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
        std::cout << "help"  << std::endl;
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
    else if(!strcmp(argv[1],"patch") && argc == 5){
        renderPatch(argv[2],atoi(argv[3]),argv[4]);
    }
    else {
        std::cout << "help"  << std::endl;
        print_help();
    }
    return 0;
}


