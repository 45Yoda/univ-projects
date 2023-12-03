//
// Created by yoda45 on 4/3/18.
//

#ifndef _ACTION_H
#define _ACTION_H

#include "../tinyxml2.h"
#include "../Generator/vertex.h"
#include <vector>
#include <math.h>

using namespace std;

//pure virtual function (abstract class)
class Action {
    public:
        virtual void apply() = 0;
};

class Translation : public Action{
    public:
        Translation();
        void parse(tinyxml2::XMLElement *tr);
        vector<Vertex*> getPoints();
        void addPoint(Vertex*);
        vector<Vertex*> getCurvePoints();
        vector<Vertex*> generateCurvePoints();
        void getGlobalCatmullRomPoint(float, float*,float*, vector<Vertex*>);
        void apply();
    private:
        float x;
        float y;
        float z;
        float time;
        float aux[3];
        vector<Vertex*> points;
        vector<Vertex*> curvePoints;
};

class Rotation : public Action{
    public:
        Rotation();
        void parse(tinyxml2::XMLElement *rt);
        void apply();
    private:
        float angle;
        float time;
        float axisX;
        float axisY;
        float axisZ;
};

class Scale : public Action{
    public:
        Scale();
        void parse(tinyxml2::XMLElement *sc);
        void apply();
    private:
        float x;
        float y;
        float z;
};

class Color : public Action{
    public:
        Color();
        void parse(tinyxml2::XMLElement *cl);
        void apply();
    private:
        float r;
        float g;
        float b;
};


#endif //_ACTION_H
