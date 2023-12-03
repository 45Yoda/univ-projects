#ifndef __SHAPE_H__
#define __SHAPE_H__

#define GL_GLEXT_PROTOTYPES


#include <string>
#include <vector>
#include <IL/il.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "../Generator/point.h"
#include "material.h"


using namespace std;

class Shape{

    Material* colorComponent;
    int pointsSize=0,normalsSize=0,texturesSize=0;
    GLuint buffers[3];
    GLuint texture;
    unsigned int t, width, height;
    unsigned int texID;
    unsigned char *data;
    public:
        Shape();
        Shape(vector<Point*>, vector<Point*>, vector<Point*>);
        vector<Point*> getPoints();
        vector<Point*> getNormals();
        vector<Point*> getTextures();
        Material* getColorComponent();
        void setColorComponent(Material*);
        void readyUp(vector<Point*>, vector<Point*>, vector<Point*>);
        void loadTexture(string);
        void draw();
};

#endif