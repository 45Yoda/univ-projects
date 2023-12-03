//
// Created by yoda45 on 4/3/18.
//

#ifndef _GROUP_H
#define _GROUP_H


#include "shape.h"
#include "action.h"

class Group {

    int id;
    vector<Shape*> shapes; // Shapes
    vector<Group*> groups; // Childs of parent group
    vector<Action*> actions; //Actions

    public:
        Group();
        Group(int);
        Group(vector<Shape*>,vector<Group*>,vector<Action*>);
        vector<Shape*> getShapes();
        vector<Group*> getChilds();
        vector<Action*> getActions();
        void setShapes(vector<Shape*>);
        void setChilds(vector<Group*>);
        void setActions(vector<Action*>);
        void addShape(Shape*);
        void addChild(Group*);
        void addAction(Action*);

};

#endif //_GROUP_H
