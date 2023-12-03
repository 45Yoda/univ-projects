//
// Created by yoda45 on 4/3/18.
//

#ifndef _ACTION_H
#define _ACTION_H

#include "../tinyxml2.h"
#include "../Generator/point.h"
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
        vector<Point*> getPoints();
        void addPoint(Point*);
        vector<Point*> getCurvePoints();
        vector<Point*> generateCurvePoints();
        void getGlobalCatmullRomPoint(float, float*,float*, vector<Point*>);
        void apply();
    private:
        float x;
        float y;
        float z;
        float time;
        float aux[3];
        vector<Point*> points;
        vector<Point*> curvePoints;
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
        Color(float,float,float);
        void parse(tinyxml2::XMLElement *cl);
        void apply();
        float getR();
        float getG();
        float getB();
    private:
        float r;
        float g;
        float b;
};


#endif //_ACTION_H
