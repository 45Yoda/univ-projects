//
// Created by yoda45 on 4/3/18.
//

#include "group.h"
#include <iostream>

Group::Group(){
}

Group::Group(int n){
    id = n;
}

Group::Group(vector<Shape*> listShape, vector<Group*> listGroup, vector<Action*> listAction, vector<Light*> listLight){
    shapes = listShape;
    groups = listGroup;
    actions = listAction;
    lights = listLight;
}

vector<Shape*> Group::getShapes(){
    return shapes;
}

vector<Group*> Group::getChilds(){
    return groups;
}

vector<Action*> Group::getActions(){
    return actions;
}

vector<Light*> Group::getLights(){
    return lights;
}

void Group::setShapes(vector<Shape*> listShape){
    shapes = listShape;
}

void Group::setChilds(vector<Group*> listGroup){
    groups = listGroup;
}

void Group::setActions(vector<Action*> listAction){
    actions = listAction;
}

void Group::setLights(vector<Light *> listLights) {
    lights = listLights;
}

void Group::addShape(Shape* shape) {
    shapes.push_back(shape);
}

void Group::addChild(Group* child) {
    groups.push_back(child);
}

void Group::addAction(Action* act){
    actions.push_back(act);
}

void Group::addLight(Light * lit) {
    lights.push_back(lit);
}