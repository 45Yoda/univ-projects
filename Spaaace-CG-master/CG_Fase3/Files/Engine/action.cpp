//
// Created by yoda45 on 4/3/18.
//
#include <GL/glut.h>
#include "action.h"
#include "../Generator/vertex.h"
#include <iostream>
#include <string>
//#include <opencl-c.h>

using tinyxml2::XMLElement;

Translation::Translation(){
    x = 0;
    y = 0;
    z = 0;
    time = 0.0f;
    aux[0] = 0;
    aux[1] = 1;
    aux[2] = 0;
}

Rotation::Rotation(){
    angle = 0;
    time = 0.0f;
    axisX = 0;
    axisY = 0;
    axisZ = 0;
}

Scale::Scale(){
    x = 1;
    y = 1;
    z = 1;
}

Color::Color(){
    r = 0;
    g = 0;
    b = 0;
}

void Translation::parse(XMLElement * tr){
    tr->QueryFloatAttribute("time", &time);
    tr->QueryFloatAttribute("X", &x);
    tr->QueryFloatAttribute("Y", &y);
    tr->QueryFloatAttribute("Z", &z);

    XMLElement* point_element = tr->FirstChildElement();

    for(;point_element;point_element=point_element->NextSiblingElement()){
        float xs=0, ys=0, zs=0;

        point_element->QueryFloatAttribute("X",&xs);
        point_element->QueryFloatAttribute("Y",&ys);
        point_element->QueryFloatAttribute("Z",&zs);
        Vertex* vertex = new Vertex(xs,ys,zs);
        addPoint(vertex);
    }

}

void Rotation::parse(XMLElement *rt){
    rt->QueryFloatAttribute("angle", &angle);
    rt->QueryFloatAttribute("time", &time);
    rt->QueryFloatAttribute("X", &axisX);
    rt->QueryFloatAttribute("Y", &axisY);
    rt->QueryFloatAttribute("Z", &axisZ);
}

void Scale::parse(XMLElement *sc){
    sc->QueryFloatAttribute("X", &x);
    sc->QueryFloatAttribute("Y", &y);
    sc->QueryFloatAttribute("Z", &z);
}

void Color::parse(XMLElement *cl){
    cl->QueryFloatAttribute("R", &r);
    cl->QueryFloatAttribute("G", &g);
    cl->QueryFloatAttribute("B", &b);
}


vector<Vertex*> Translation::getPoints(){
    return points;
}

void Translation::addPoint(Vertex* v){
    points.push_back(v);
}

vector<Vertex*> Translation::getCurvePoints(){
    return curvePoints;
}

void getCatmullRomPoint(float t, int *indices, float *pos, float *deriv, vector<Vertex*> points) {

    float  t2 = t*t , t3 = t*t*t;
    float posAux[4];
    float derivAux[4];

    Vertex* p0 = points[indices[0]];
    Vertex* p1 = points[indices[1]];
    Vertex* p2 = points[indices[2]];
    Vertex* p3 = points[indices[3]];

    // catmull-rom matrix
    float m[4][4] = {	 {-0.5f,  1.5f, -1.5f,  0.5f},
                         { 1.0f, -2.5f,  2.0f, -0.5f},
                         {-0.5f,  0.0f,  0.5f,  0.0f},
                         { 0.0f,  1.0f,  0.0f,  0.0f}
                    };

    pos[0] = 0.0;
    pos[1] = 0.0;
    pos[2] = 0.0;
    deriv[0] = 0.0;
    deriv[1] = 0.0;
    deriv[2] = 0.0;

    
    // Compute A = M * P
    posAux[0] = t3*m[0][0] + t2*m[1][0] + t*m[2][0] + m[3][0];
    posAux[1] = t3*m[0][1] + t2*m[1][1] + t*m[2][1] + m[3][1];
    posAux[2] = t3*m[0][2] + t2*m[1][2] + t*m[2][2] + m[3][2];
    posAux[3] = t3*m[0][3] + t2*m[1][3] + t*m[2][3] + m[3][3];

    derivAux[0] = (3*t2)*m[0][0] + (2*t)*m[1][0] + m[2][0];
    derivAux[1] = (3*t2)*m[0][1] + (2*t)*m[1][1] + m[2][1];
    derivAux[2] = (3*t2)*m[0][2] + (2*t)*m[1][2] + m[2][2];
    derivAux[3] = (3*t2)*m[0][3] + (2*t)*m[1][3] + m[2][3];


    // Compute pos = T * A
    pos[0] = posAux[0] * p0->getX() + posAux[1] * p1->getX() + posAux[2] * p2->getX() + posAux[3] * p3->getX();
    pos[1] = posAux[0] * p0->getY() + posAux[1] * p1->getY() + posAux[2] * p2->getY() + posAux[3] * p3->getY();
    pos[2] = posAux[0] * p0->getZ() + posAux[1] * p1->getZ() + posAux[2] * p2->getZ() + posAux[3] * p3->getZ();

      // compute deriv = T' * A
    deriv[0] = derivAux[0] * p0->getX() + derivAux[1] * p1->getX() + derivAux[2] * p2->getX() + derivAux[3] * p3->getX();
    deriv[1] = derivAux[0] * p0->getY() + derivAux[1] * p1->getY() + derivAux[2] * p2->getY() + derivAux[3] * p3->getY();
    deriv[2] = derivAux[0] * p0->getZ() + derivAux[1] * p1->getZ() + derivAux[2] * p2->getZ() + derivAux[3] * p3->getZ();

// ...
}


// given  global t, returns the point in the curve
void Translation::getGlobalCatmullRomPoint(float gt, float *pos, float *deriv, vector<Vertex*> points) {
    int POINT_COUNT = points.size();
    float t = gt * POINT_COUNT; // this is the real global t
    int index = floor(t);  // which segment
    t = t - index; // where within  the segment

    // indices store the points
    int indices[4];
    indices[0] = (index + POINT_COUNT-1)%POINT_COUNT;
    indices[1] = (indices[0]+1)%POINT_COUNT;
    indices[2] = (indices[1]+1)%POINT_COUNT;
    indices[3] = (indices[2]+1)%POINT_COUNT;

    getCatmullRomPoint(t, indices, pos, deriv, points);
}

void cross(float *a, float *b, float *res) {

    res[0] = a[1]*b[2] - a[2]*b[1];
    res[1] = a[2]*b[0] - a[0]*b[2];
    res[2] = a[0]*b[1] - a[1]*b[0];
}


void normalize(float *a) {

    float l = sqrt(a[0]*a[0] + a[1] * a[1] + a[2] * a[2]);
    a[0] = a[0]/l;
    a[1] = a[1]/l;
    a[2] = a[2]/l;
}

vector<Vertex*> Translation::generateCurvePoints() {
    float pos[3];
    float deriv[3];

    for(float t = 0;t<1;t+=0.01) {
        getGlobalCatmullRomPoint(t,pos,deriv,points);
        Vertex* v = new Vertex(pos[0],pos[1],pos[2]);
        curvePoints.push_back(v);
    }

    return curvePoints;
}

void renderCatmullRomCurve(vector<Vertex*> points) {
    int size = points.size();
    float p[3];
// desenhar a curva usando segmentos de reta - GL_LINE_LOOP
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < size; i++){
        p[0] = points[i]->getX(); 
        p[1] = points[i]->getY(); 
        p[2] = points[i]->getZ();
        glVertex3fv(p);
    }
    glEnd();
}
    
void curveRotation(float *der, float *aux){

    float left[3];

    cross(der,aux,left);
    cross(left, der, aux);
    
    normalize(der);
    normalize(aux);
    normalize(left);
    
    float m[4][4] = { {der[0], der[1], der[2], 0}, 
                      {aux[0], aux[1], aux[2], 0}, 
                      {left[0], left[1], left[2], 0},
                      {0.0f,0.0f,0.0f, 1}
                    };
    glMultMatrixf((float*)m);
}

void Translation::apply(){
    float te, gt;
    float res[3];
    float deriv[3];

    if(time!=0){
        te = glutGet(GLUT_ELAPSED_TIME) % (int)(time * 1000);
        gt = te / (time * 1000);
        vector<Vertex*> vp2 = generateCurvePoints();
        renderCatmullRomCurve(vp2);
        getGlobalCatmullRomPoint(gt,res,deriv,points);
        curvePoints.clear();
        glTranslatef(res[0], res[1], res[2]);
        curveRotation(deriv,aux);
        return;
    }

    glTranslatef(x,y,z);
}

void Rotation::apply() {
    float tmp, r;

    if(time!=0){
        tmp = glutGet(GLUT_ELAPSED_TIME) % (int)(time * 1000);
        r = (tmp*360) / (time * 1000);
        glRotatef(r,axisX,axisY,axisZ);
        return ;
    }
    glRotatef(angle,axisX,axisY,axisZ);
}

void Scale::apply() {
    glScalef(x,y,z);
}

void Color::apply() {
    float rt = r/255;
    float gt = g/255;
    float bt = b/255;
    glColor3f(rt,gt,bt);
}
