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

using namespace tinyxml2;

vector<Shape*> shapes;
int total_shapes = 0;
int mode = GL_LINE;
float angleX = 1.0, angleY = 1.0;

float R1=1.0f , G1=0.5f , B1=0.0f;
float R2=0.0f , G2=0.5f , B2=1.0f;

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
        case 'w': angleY+=5.0f;
                  break;
        case 's': angleY-=5.0f;
                  break;
        case 'a': angleX-=5.0f;
                  break;
        case 'd': angleX+=5.0f;
                  break;
        case 'j': mode = GL_FILL;
                  break;
        case 'k': mode = GL_LINE;
                  break;
        case 'l': mode = GL_POINT;
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



void renderScene(void) {

    int i= 0;
    int flag =0;
    float x,y,z;
    float R=R1,G=G1,B=B1;

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(5.0+ex,5.0+ey,5.0+ez,
              0.0,0.0,0.0,
              0.0f,1.0f,0.0f);

    //put the geometric transformations here
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT_AND_BACK, mode);

    glRotatef(angleX,0,1,0);
    glRotatef(angleY,0,0,1);


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

    // put drawing instructions here
    glColor3f(0.0f,1.0f,1.0f);

    for (vector<Shape*>::iterator shape_it = shapes.begin(); shape_it != shapes.end(); ++shape_it){
        vector<Vertex*> vertexes = (*shape_it)->getVertexes();
        glBegin(GL_TRIANGLES);
        for(vector<Vertex*>::iterator iter = vertexes.begin(); iter != vertexes.end(); ++iter){
            x = (*iter)->getX();
            y = (*iter)->getY();
            z = (*iter)->getZ();

            if(i%3 == 0 && i!= 0){
               if(flag ==0){
                  R=R2;G=G2;B=B2;
                  flag = 1;
                  i = 0;
               }
               else{
                   R=R1;G=G1;B=B1;
                   flag = 0;
                   i = 0;
               }
            }

            glColor3f(R,G,B);

            glVertex3f(x,y,z);

            i++;

        }
        glEnd();
    }

    // End of frame
    glutSwapBuffers();
}

vector<string> find_files(char* file_name){
    string model_name;
    vector<string> files;
    XMLDocument doc;
    XMLElement* element,*root;
    XMLError error;

    //Confirm that the file loaded successfully
    error = doc.LoadFile(file_name);

    if(error == 0){
        root = doc.FirstChildElement("scene");
        element = root->FirstChildElement("model");
        for(;element;element = element->NextSiblingElement()){
            if(!strcmp(element->Name(),"model")){
                model_name = element->Attribute("file");
                files.push_back(model_name);
                std::cout << model_name << std::endl;
            }
        }
    }
    else{
        std::cout << "XML file not found:" << file_name << "." << endl;
    }
    return files;
}

vector<Vertex*> read_file(string file_name){

    vector<Vertex*> vertexes;
    vector<string> tokens;
    string buffer;
    string line;
    int index = 0;
    string file_path = "../" + file_name;

    ifstream file (file_path);
    if(file.is_open()){
        while(getline(file,line)){ // iterate over the lines of the file
            stringstream ss(line);
            while(ss >> buffer)
                tokens.push_back(buffer); // iterate over the coordinates of the vertexes in each line
            //add vertexes to the vector
            vertexes.push_back(new Vertex(stof(tokens[index]),stof(tokens[index+1]),stof(tokens[index+2])));
            index+=3;
        }
        file.close();
    }
    else cout << "Unable to open file." << endl;
    return vertexes;
}

int main(int argc, char **argv) {

    vector<string> files;
    string line;

    if(argc != 2){
        std::cout << "Error" << std::endl;
        print_help();
    }
    else {
        files = find_files(argv[1]);
        if(files.size()){
            for(vector<string>::const_iterator i = files.begin(); i != files.end(); ++i){
                vector<Vertex*> aux = read_file(*i);
                shapes.push_back(new Shape(total_shapes,aux));
                total_shapes++;
            }
        }
        else return 0;
    }

// init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("");

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
