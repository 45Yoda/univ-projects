//
// Created by yoda45 on 4/3/18.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.h"

int total = 0;

Group* myChild(Group* parent){

    Group* child = new Group(total++);
    parent->addChild(child);

    return child;
}

void foundTranslation(XMLElement* element, Group* g){

    Translation* transl = new Translation();

    transl->parse(element);

    g->addAction(transl);
}

void foundRotation(XMLElement* element, Group* g){

    Rotation* rot = new Rotation();

    rot->parse(element);

    g->addAction(rot);
}

void foundScale(XMLElement* element, Group* g){

    Scale* scale = new Scale();

    scale->parse(element);

    g->addAction(scale);
}


void foundColor(XMLElement* element, Group* g){

    Color* color = new Color();

    color->parse(element);

    g->addAction(color);
}

vector<Vertex*> readFile(string file_name){

    vector<Vertex*> vertexes;
    vector<string> tokens;
    string buffer;
    string line;
    int index = 0, i=0;
    string file_path = "../" + file_name;
    ifstream file (file_path);

    if(file.is_open()){
        while(getline(file,line)){ // iterate over the lines of the file
            stringstream ss(line);
            while(ss >> buffer)
                tokens.push_back(buffer); // it
            // erate over the coordinates of the vertexes in each line
            cout << tokens[index] << endl;
            //add vertexes to the vector
            vertexes.push_back(new Vertex(stof(tokens[index]),stof(tokens[index+1]),stof(tokens[index+2])));
            std::cout << i++;
            index+=3;
        }
        file.close();
    }
    else cout << "Unable to open file." << endl;
    return vertexes;
}


//<models>
vector<Shape*> findModels(XMLElement* element){

    vector<Shape*> listModels;

    element = element->FirstChildElement();//<model file=--->
    for(;element;element=element->NextSiblingElement()){
        if(!strcmp(element->Name(),"model")){
            vector<Vertex*> aux = readFile(element->Attribute("file"));
            if(!aux.empty()){
                Shape* shape = new Shape(element->Attribute("file"),aux);
                listModels.push_back(shape);
            }
            else return listModels;
        }
    }

    return listModels;
}


void findElement(XMLElement* element, Group* g){

    XMLElement* current = element; //1st group
    //Find the Translation
    if(!strcmp(element->Name(),"translate"))
        foundTranslation(element,g);

    //Find the Rotation
    else if(!strcmp(element->Name(),"rotate"))
        foundRotation(element,g);

    //Find the Scale
    else if(!strcmp(element->Name(),"scale"))
        foundScale(element,g);

    //Find the Color
    else if(!strcmp(element->Name(),"colour")) {
        foundColor(element, g);

    }
    //Gather all Models
    else if(!strcmp(element->Name(),"models")){
        vector<Shape*> listShape = findModels(element);
        if(!listShape.empty()){
            g->setShapes(listShape);
        }
    }

    //Iterate over childs recursively
    else if(!strcmp(element->Name(),"group")) {
        Group *childGroup = myChild(g);
        element = element->FirstChildElement();
        if (element) {
            findElement(element, childGroup);
        }
    }

    //Iterate over brothers recursively
    current = current->NextSiblingElement();
    if(current)
        findElement(current,g);
}


Group* parseXML(char* file_name) {

    XMLDocument doc;
    XMLElement *element;
    XMLError error;

    Group *group = new Group();

    error = doc.LoadFile(file_name);
    if(error == 0){
        element = doc.FirstChildElement("scene")->FirstChildElement("group");
        findElement(element,group);

    }
    else
        cout << "Could not load XML file: " << file_name << "." << endl;


    return group;
}
