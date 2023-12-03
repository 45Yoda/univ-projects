#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include "point.h"
#include "plane.h"
#include "box.h"
#include "cone.h"
#include "sphere.h"
#include "torus.h"

using std::ofstream;
using std::string;
using std::vector;

void printFile(string name, vector<Point*> points, vector<Point*> normals, vector<Point*> textures){
    ofstream file(name);
    char buffer[1024];

    file << points.size() << endl;
    for(Point* v: points){
        sprintf(buffer,"%f %f %f\n",v->getX(),v->getY(),v->getZ());
        file << buffer;
    }

    if(normals.size()){
        file << normals.size() << endl;
        for(Point* n: normals){
            sprintf(buffer,"%f %f %f\n",n->getX(),n->getY(),n->getZ());
            file << buffer;
        }
    }

    if(textures.size()){
        file << textures.size() << endl;
        for(Point* t: textures){
            sprintf(buffer,"%f %f\n",t->getX(),t->getY());
            file << buffer;
        }
    }

    file.close();
}


void drawPlane(float size, string name){
    vector<Point*> normals;
    vector<Point*> textures;
    vector<Point*> points = plane(size,&normals,&textures);

    printFile(name,points,normals,textures);
}

void drawBox(float x, float y, float z, int div, string name){
    vector<Point*> normals;
    vector<Point*> textures;
    vector<Point*> points = box(x,y,z,div,&normals,&textures);

    printFile(name,points,normals,textures);
}

void drawSphere(float radius, int slices, int stacks, string name){
    vector<Point*> normals;
    vector<Point*> textures;
    vector<Point*> points = sphere(radius,slices,stacks,&normals,&textures);

    printFile(name,points,normals,textures);
}

void drawCone(float radius, float height, int slices, int stacks, string name){
    vector<Point*> normals;
    vector<Point*> textures;
    vector<Point*> points = cone(radius,height,slices,stacks);

    printFile(name,points,normals,textures);


}

void drawTorus(float radiusSmall, float radiusBig, int sides, int rings, string name){
	vector<Point*> normals;
	vector<Point*> textures;
	vector<Point*> points = torus(radiusSmall,radiusBig,sides,rings,&normals,&textures);

	printFile(name,points,normals,textures);


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


float* getBezierPoint( float a , float b , int* index , float** points) {

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

float getBezierPointTangent(float u, float v, float m[4][4] , float p[4][4], int derivada) {
    float pointValue = 0;
    float aux[4], aux2[4];

    //derivada de u
    if(derivada == 0){
        //bu*M
        for(int i = 0; i<4; i++){
            aux[i] = (3 * powf(u,2.0)*m[0][i]) + (2*u*m[1][i]) + (1*m[2][i]);
        }
    } else {
        for(int i = 0; i<4; i++){
            aux[i] = (powf(u,3.0)*m[0][i]) + (powf(u,2.0)*m[1][i]) + (u*m[2][i]) + m[3][i];
        }
    }

    //(bu*M)*P
    for(int i = 0; i<4; i++){
        aux2[i] = (aux[0]*p[0][i]) + (aux[1]*p[1][i]) + (aux[2]*p[2][i]) + (aux[3]*p[3][i]);
    }

    //((bu*M)*P)*MT
    for(int i = 0; i<4; i++){
        aux[i] = (aux2[0]*m[0][i]) + (aux2[1]*m[1][i]) + (aux2[2]*m[2][i]) + (aux2[3]*m[3][i]);
    }

    if(derivada == 0) {
        //(((bu*M)*P)*MT)*bv
        pointValue = aux[0] * powf(v,3.0);
        pointValue += aux[1] * powf(v,2.0);
        pointValue += aux[2] * v;
        pointValue += aux[3];
        //derivada de v
    } else {
        //(((bu*M)*P)*MT)*bv
        pointValue = aux[0] * (3 * powf(v,2.0));
        pointValue += aux[1] * (2 * v);
        pointValue += aux[2];
    }

    return pointValue;
}

void cross(float *a, float *b, float *res) {
    res[0] = a[1]*b[2] - a[2]*b[1];
    res[1] = a[2]*b[0] - a[0]*b[2];
    res[2] = a[0]*b[1] - a[1]*b[0];
}

void normalize(float *a) {
    float l = sqrt(a[0]*a[0] + a[1]*a[1] + a[2]*a[2]);
    if(l!=0) {
        a[0] = a[0]/l;
        a[1] = a[1]/l;
        a[2] = a[2]/l;
    } else {
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
    }
}

vector<Point*> bezNorm(int tessellation,vector<Point*> patch_list){
    vector<Point*> derivada;
    int i, j, aux;
    float * ma[16], mT[3][16], px[4][4], py[4][4], pz[4][4], resU[3], resV[3], res[3];
    float u, v, u2, v2, level = (float)1.0/(float)tessellation;

    for(int n_patches = 0; n_patches < patch_list.size(); n_patches++){
        vector<Point*> control_points = patch_list;
        aux = 0;

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++, aux++){
                px[i][j] = control_points[aux]->getX();
                py[i][j] = control_points[aux]->getY();
                pz[i][j] = control_points[aux]->getZ();
            }
        }

        //Matriz M
        float m[4][4] = {{-1, 3, -3, 1},
                         {3, -6, 3, 0 },
                         {-3, 3, 0, 0},
                         {1, 0, 0, 0}};



        for(i = 0; i<=tessellation ; i++){
            u = i * level;
            u2 = (i+1) * level;

            for(j = 0; j<=tessellation ; j++){
                v = j * level;
                v2 = (j+1) * level;

                resU[0] = getBezierPointTangent(u, v, m, px,0);
                resU[1] = getBezierPointTangent(u, v, m, py,0);
                resU[2] = getBezierPointTangent(u, v, m, pz,0);
                normalize(resU);
                resV[0] = getBezierPointTangent(u, v, m, px,1);
                resV[1] = getBezierPointTangent(u, v, m, py,1);
                resV[2] = getBezierPointTangent(u, v, m, pz,1);
                normalize(resV);
                cross(resV,resU,res);
                derivada.push_back(new Point(res[0],res[1],res[2]));

                resU[0] = getBezierPointTangent (u2,v, m, px,0);
                resU[1] = getBezierPointTangent (u2,v, m, py,0);
                resU[2] = getBezierPointTangent (u2,v, m, pz,0);
                normalize(resU);
                resV[0] = getBezierPointTangent (u2,v, m, px,1);
                resV[1] = getBezierPointTangent (u2,v, m, py,1);
                resV[2] = getBezierPointTangent (u2,v, m, pz,1);
                normalize(resV);
                cross(resV,resU,res);
                derivada.push_back(new Point(res[0],res[1],res[2]));

                resU[0] = getBezierPointTangent (u2,v2, m, px,0);
                resU[1] = getBezierPointTangent (u2,v2, m, py,0);
                resU[2] = getBezierPointTangent (u2,v2, m, pz,0);
                normalize(resU);
                resV[0] = getBezierPointTangent (u2,v2, m, px,1);
                resV[1] = getBezierPointTangent (u2,v2, m, py,1);
                resV[2] = getBezierPointTangent (u2,v2, m, pz,1);
                normalize(resV);
                cross(resV,resU,res);
                derivada.push_back(new Point(res[0],res[1],res[2]));

                resU[0] = getBezierPointTangent(u, v, m, px,0);
                resU[1] = getBezierPointTangent(u, v, m, py,0);
                resU[2] = getBezierPointTangent(u, v, m, pz,0);
                normalize(resU);
                resV[0] = getBezierPointTangent(u, v, m, px,1);
                resV[1] = getBezierPointTangent(u, v, m, py,1);
                resV[2] = getBezierPointTangent(u, v, m, pz,1);
                normalize(resV);
                cross(resV,resU,res);
                derivada.push_back(new Point(res[0],res[1],res[2]));

                resU[0] = getBezierPointTangent (u2,v2, m, px,0);
                resU[1] = getBezierPointTangent (u2,v2, m, py,0);
                resU[2] = getBezierPointTangent (u2,v2, m, pz,0);
                normalize(resU);
                resV[0] = getBezierPointTangent (u2,v2, m, px,1);
                resV[1] = getBezierPointTangent (u2,v2, m, py,1);
                resV[2] = getBezierPointTangent (u2,v2, m, pz,1);
                normalize(resV);
                cross(resV,resU,res);
                derivada.push_back(new Point(res[0],res[1],res[2]));

                resU[0] = getBezierPointTangent (u,v2, m, px,0);
                resU[1] = getBezierPointTangent (u,v2, m, py,0);
                resU[2] = getBezierPointTangent (u,v2, m, pz,0);
                normalize(resU);
                resV[0] = getBezierPointTangent (u,v2, m, px,1);
                resV[1] = getBezierPointTangent (u,v2, m, py,1);
                resV[2] = getBezierPointTangent (u,v2, m, pz,1);
                normalize(resV);
                cross(resV,resU,res);
                derivada.push_back(new Point(res[0],res[1],res[2]));
            }
        }
    }
    return derivada;
}



vector<Point*> bezPT(int** indexes,float** points,int npoints,int npatch,int tess){
    vector<Point*> ult;
    Point* point;
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

                res[count][0] = getBezierPoint(u, v, indexes[count], points);
                res[count][1] = getBezierPoint(u, v2, indexes[count], points);
                res[count][2] = getBezierPoint(u2, v, indexes[count], points);
                res[count][3] = getBezierPoint(u2, v2, indexes[count], points);





                point = new Point(res[count][0][0],res[count][0][1],res[count][0][2]);
                ult.push_back(point);
                point = new Point(res[count][2][0],res[count][2][1],res[count][2][2]);
                ult.push_back(point);
                point = new Point(res[count][3][0],res[count][3][1],res[count][3][2]);
                ult.push_back(point);

                point = new Point(res[count][0][0],res[count][0][1],res[count][0][2]);
                ult.push_back(point);
                point = new Point(res[count][3][0],res[count][3][1],res[count][3][2]);
                ult.push_back(point);
                point = new Point(res[count][1][0],res[count][1][1],res[count][1][2]);
                ult.push_back(point);


                //fileo << res[count][0][0] << " " << res[count][0][1] << " " << res[count][0][2] << endl;
                //fileo << res[count][2][0] << " " << res[count][2][1] << " " << res[count][2][2] << endl;
                //fileo << res[count][3][0] << " " << res[count][3][1] << " " << res[count][3][2] << endl;

                //fileo << res[count][0][0] << " " << res[count][0][1] << " " << res[count][0][2] << endl;
                //fileo << res[count][3][0] << " " << res[count][3][1] << " " << res[count][3][2] << endl;
                //fileo << res[count][1][0] << " " << res[count][1][1] << " " << res[count][1][2] << endl;
            }
        }

    }

    return ult;
}


void renderPatch( string file , int tess , string name) {

    ofstream fileo(name);
    string line , aux;
    ifstream filei(file);
    int i;

    if(filei.is_open()) {

        //Get number of patches
        getline(filei,line);
        int npatch = atoi(line.c_str());
        int** indexes = new int*[npatch];
        cout << npatch << endl;

        //Parsing indexes
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

        //point done
        vector<Point*> pt = bezPT(indexes,points,npoints,npatch,tess);

        vector<Point*> norm = bezNorm(indexes,points,npoints,npatch,tess);





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
    std::cout<<"*      contain the points generated with the previous commands.*" << std::endl;
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


