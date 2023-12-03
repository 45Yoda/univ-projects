#define _USE_MATH_DEFINES
#include <cmath>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "shape.h"
#include "../tinyxml2.h"
#include "../Generator/vertex.h"
#include "group.h"
#include "parser.h"

using namespace tinyxml2;

Group* scene;

int mode = GL_LINE;
float angleX = 1.0, angleY = 1.0;

float ex=0.0f , ey=0.0f , ez=0.0f;
float ax=0.0f , ay=0.0f , az=0.0f;

void print_help(){
    std::cout<<"#****************************************************************#" << std::endl;
    std::cout<<"*                              HELP                              *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    Usage: ./engine {XML FILE}                                  *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    {XML FILE}:                                                 *" << std::endl;
    std::cout<<"*       Specify the path of the XML FILE you wish to use.        *" << std::endl;
    std::cout<<"*       This file must contain information about the models      *" << std::endl;
    std::cout<<"*       you want to create                                       *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    MOVEMENT:                                                   *" << std::endl;
    std::cout<<"*       - w: Rotate Up   (positive Y direction)                  *" << std::endl;
    std::cout<<"*       - s: Rotate Down (negative Y direction)                  *" << std::endl;
    std::cout<<"*       - a: Rotate Left (negative X direction)                  *" << std::endl;
    std::cout<<"*       - d: Rotate Right (positive X direction)                 *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    FORMAT:                                                     *" << std::endl;
    std::cout<<"*       - j: Change PolygonMode to GL_FILL                       *" << std::endl;
    std::cout<<"*       - k: Change PolygonMode to GL_LINE                       *" << std::endl;
    std::cout<<"*       - l: Change PolygonMode to GL_POINT                      *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"*    COMPILING:                                                  *" << std::endl;
    std::cout<<"*       - g++ engine.cpp shape.cpp ../tinyxml2.cpp               *" << std::endl;
    std::cout<<"*         ../Generator/vertex.cpp -o engine -lGL -lGLU -lglut    *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"#****************************************************************#" << std::endl;
}

void key_normal (unsigned char key, int x, int y){

    switch(key){
        case 'q':
        case 'Q': angleY+=5.0f;
                  if(angleY>360) angleY = -360;
                  break;
        case 'Z':
        case 'z': angleY-=5.0f;
                  if(angleY<-360) angleY = 360;
                  break;
        case 'A':
        case 'a': angleX-=5.0f;
                  if(angleX<-360) angleX = 360;
                  break;
        case 'D':
        case 'd': angleX+=5.0f;
                  if(angleX>360) angleX = -360;
                  break;
        case 'W':
        case 'w': float xrotrad, yrotrad;
                  xrotrad = (angleX / 180 * 3.141592654f);
                  yrotrad = (angleY / 180 * 3.141592654f);
                  ex += float(sin(xrotrad));
                  ez -= float(cos(xrotrad)) ;
                  ey -= float(sin(yrotrad));
                  break;
        case 'S':
        case 's': float xrotrad1, yrotrad1;
                  xrotrad1 = (angleX / 180 * 3.141592654f);
                  yrotrad1 = (angleY / 180 * 3.141592654f);
                  ex -= float(sin(xrotrad));
                  ez += float(cos(xrotrad)) ;
                  ey += float(sin(yrotrad));
                  break;         
        case 'J':
        case 'j': mode = GL_FILL;
                  break;
        case 'K':
        case 'k': mode = GL_LINE;
                  break;
        case 'L':
        case 'l': mode = GL_POINT;
                  break;
        case 'F':
        case 'f': glutFullScreen();
                  break;
        case '+': ex -= 2.0f; ey -= 2.0f; ez -= 2.0f;
                  break;
        case '-': ex += 2.0f; ey += 2.0f; ez += 2.0f;
                  break;
        case 'm': ax += 2.0f; ay += 2.0f; az += 2.0f;
                  break;
        case 'n': ax -= 2.0f; ay -= 2.0f; az -= 2.0f;
                  break;
    }
    glutPostRedisplay();
}


void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if(h == 0)
        h = 1;

    // compute window's aspect ratio
    float ratio = w * 1.0 / h;

    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load Identity Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set perspective
    gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void axis(){
    glBegin(GL_LINES);
// draw line for x axis
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(5.0+ax, 0.0, 0.0);
// draw line for y axis
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 5.0+ay, 0.0);
// draw line for Z axis
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 5.0+az);
    glEnd();

}


void render(Group* g){

    float x,y,z;

    glPushMatrix();

    vector<Action*> actions = g->getActions();


    for(vector<Action*>::iterator act_it = actions.begin(); act_it != actions.end(); ++act_it){
        Action* action = (*act_it);

        action->apply();
    }

    vector<Shape*> shapes = g->getShapes();

    for(vector<Shape*>::iterator shp_it = shapes.begin(); shp_it != shapes.end(); ++shp_it){

        Shape* shape = (*shp_it);
        vector<Vertex*> vertexes = shape->getVertexes();

        glBegin(GL_TRIANGLES);

        for(vector<Vertex*>::iterator iter = vertexes.begin(); iter != vertexes.end(); ++iter){

            x = (*iter)->getX();
            y = (*iter)->getY();
            z = (*iter)->getZ();

            glVertex3f(x,y,z);
        }

        glEnd();
    }

    vector<Group*> childs = g->getChilds();
    for(vector<Group*>::iterator g_it = childs.begin(); g_it != childs.end(); ++g_it){
        render(*g_it);
    }


    glPopMatrix();
}




void renderScene(void) {


    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(40.0+ex,40.0+ey,40.0+ez,
              0.0,0.0,0.0,
              0.0f,1.0f,0.0f);

    //put the geometric transformations here
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT_AND_BACK, mode);

    glRotatef(angleX,0,1,0);
    glRotatef(angleY,0,0,1);

    axis();

    render(scene);

    // End of frame
    glutSwapBuffers();
}


int main(int argc, char **argv) {

    vector<string> files;
    string line;

    if(argc != 2){
        std::cout << "Error" << std::endl;
        print_help();
    }
    else {
        scene = parseXML(argv[1]);
    }


// init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1200,750);
    glutCreateWindow("CGTP");

// Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);


// put here the registration of the keyboard callbacks
    glutKeyboardFunc(key_normal);


//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
    glutMainLoop();

    return 0;
}
