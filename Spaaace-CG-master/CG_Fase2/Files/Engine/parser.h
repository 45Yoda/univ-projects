//
// Created by yoda45 on 4/3/18.
//

#ifndef _PARSER_H
#define _PARSER_H

#include "group.h"
#include "../tinyxml2.h"

using namespace tinyxml2;

Group* myChild(Group*);
void foundTranslation(XMLElement*, Group*);
void foundRotation(XMLElement*, Group*);
void foundScale(XMLElement*, Group*);
void foundColor(XMLElement*, Group*);
vector<Shape*> findModels(XMLElement*);
void findElement(XMLElement*, Group*);
vector<Vertex*> readFile(string);
Group* parseXML(char*);




#endif //GENERATOR_PARSER_H
