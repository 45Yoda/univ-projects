//
// Created by yoda45 on 4/3/18.
//

#ifndef _GROUP_H
#define _GROUP_H


#include "shape.h"
#include "action.h"
#include "light.h"

class Group {

    int id;
    vector<Shape*> shapes; // Shapes
    vector<Group*> groups; // Childs of parent group
    vector<Action*> actions; //Actions
    vector<Light*> lights; //Lights

    public:
        Group();
        Group(int);
        Group(vector<Shape*>,vector<Group*>,vector<Action*>,vector<Light*>);
        vector<Shape*> getShapes();
        vector<Group*> getChilds();
        vector<Action*> getActions();
        vector<Light*> getLights();
        void setShapes(vector<Shape*>);
        void setChilds(vector<Group*>);
        void setActions(vector<Action*>);
        void setLights(vector<Light*>);
        void addShape(Shape*);
        void addChild(Group*);
        void addAction(Action*);
        void addLight(Light*);

};

#endif //_GROUP_H
