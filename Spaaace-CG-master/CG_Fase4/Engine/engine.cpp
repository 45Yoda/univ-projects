#include <cmath>
#include <GL/glew.h>
#include <GL/glut.h>
#include <IL/ilut.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "shape.h"
#include "group.h"
#include "parser.h"

using namespace tinyxml2;

Group* scene;


int mode = GL_LINE;
int fullscreen = 0;

float rad = 5.0f;
float cX = -30, cY = 30, cZ = 20;
float angX = 0.0f, angY = 0.0f, angZ = 0.0f;
float ptX = 0, ptY = 0, ptZ = 0;
int stX, stY, track = 0, r=5;
float alpha=0, bota=0;

void resetCam(){
    angX = angY = angZ = 0.0f;
    ptX = ptY = ptZ = 0;
    alpha = 0.0f;
    bota = 0.5f;
}


float angleX = 0.0, angleY = 0.0;

float ex=0.0f , ey=0.0f , ez=0.0f;
float ax=0.0f , ay=0.0f , az=0.0f;

float cRad = 10.0f;
float xp=40, yp=10, zp=100, angle=0.0;

int timebase = 0, frame = 0;

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
    std::cout<<"*         ../Generator/Point.cpp -o engine -lGL -lGLU -lglut    *" << std::endl;
    std::cout<<"*                                                                *" << std::endl;
    std::cout<<"#****************************************************************#" << std::endl;
}

void normal_key (unsigned char key, int x, int y){

    switch(key){
        case 'W':
        case 'w': angX +=5;
                  break;
        case 'S':
        case 's': angX -=5;
                  break;

        case 'A':
        case 'a': angY +=5;
                  break;

        case 'D':
        case 'd': angY -=5;
                  break;
        case 'Q':
        case 'q': angZ +=5;
                  break;

        case 'E':
        case 'e': angZ -=5;
                  break;

        case 'R':
        case 'r': resetCam();
                  break;

        case '+': ptY += 5;
                  break;

        case '-': ptY -= 5;
                  break;
    }

    glutPostRedisplay();
}

void special_key(int key, int x, int y){

    switch(key){
        case GLUT_KEY_UP: ptZ += 5.0f;
                          break;

        case GLUT_KEY_DOWN: ptZ -= 5.0f;
                            break;

        case GLUT_KEY_LEFT: ptX += 5;
                            break;

        case GLUT_KEY_RIGHT: ptX -= 5;
                             break;
    }
}




void key_normal (unsigned char key, int x, int y){

    float xrotrad, yrotrad;


    switch(key){
        case 'W':
        case 'w':
            xrotrad = (angleX / 180 * M_PI);
            yrotrad = (angleY / 180 * M_PI);
            xp += float(sin(yrotrad)) * 3;
            yp -= float(sin(xrotrad)) * 3;
            zp -= float(cos(yrotrad)) * 3;
            break;
        case 'A':
        case 'a':
            yrotrad = (angleY / 180 * M_PI);
            xp -= float(cos(yrotrad)) * 3;
            zp -= float(sin(yrotrad)) * 3;
            break;
        case 'S':
        case 's':
            xrotrad = (angleX / 180 * M_PI);
            yrotrad = (angleY / 180 * M_PI);
            xp -= float(sin(yrotrad)) * 3;
            yp += float(sin(xrotrad)) * 3;
            zp += float(cos(yrotrad)) * 3;
            break;
        case 'D':
        case 'd':
            yrotrad = (angleY / 180 * M_PI);
            xp += float(cos(yrotrad)) * 3;
            zp += float(sin(yrotrad)) * 3;
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
        case 'f':
            fullscreen = !fullscreen;
            if (fullscreen)
            {
                glutFullScreen();                /* Go to full screen */
            }
            else
            {
                glutReshapeWindow(800, 600);        /* Restore us */
                glutPositionWindow(0,0);
            }
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
}

void key_special(int key_code, int x, int y){
    switch(key_code){
        case GLUT_KEY_UP:
            angleX -= 6;
            break;
        case GLUT_KEY_DOWN:
            angleX += 6;
            break;
        case GLUT_KEY_LEFT:
            angleY-=3.0f;
            break;
        case GLUT_KEY_RIGHT:
            angleY+=3.0f;
            break;
    }
}

void displayFPS() {
    int time;
    char title[20];

    frame++;
    time = glutGet(GLUT_ELAPSED_TIME);
    if (time - timebase > 1000) {
        float fps = frame * 1000.0/(time - timebase);
        timebase = time;
        frame = 0;
        sprintf(title,"Engine  |  %.2f FPS",fps);
        glutSetWindowTitle(title);
  }
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
    gluPerspective(45.0f ,ratio, 0.1f ,1000.0f);

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

    glPushMatrix();

    vector<Light*> lights = g->getLights();

    for(vector<Light*>::iterator lit_it = lights.begin(); lit_it != lights.end(); ++lit_it ){
        Light* light = (*lit_it);

        light->draw();
    }


    vector<Action*> actions = g->getActions();

    for(vector<Action*>::iterator act_it = actions.begin(); act_it != actions.end(); ++act_it){
        Action* action = (*act_it);

        action->apply();
    }


    vector<Shape*> shapes = g->getShapes();

    for(vector<Shape*>::iterator shp_it = shapes.begin(); shp_it != shapes.end(); ++shp_it) {
        Shape *shape = (*shp_it);
        shape->draw();
    }



        /*
        vector<Point*> points = shape->getPoints();

        glBegin(GL_TRIANGLES);

        for(vector<Point*>::iterator iter = points.begin(); iter != points.end(); ++iter){

            x = (*iter)->getX();
            y = (*iter)->getY();
            z = (*iter)->getZ();

            glVertex3f(x,y,z);
        }

        glEnd();*/

    vector<Group*> childs = g->getChilds();
    for(vector<Group*>::iterator g_it = childs.begin(); g_it != childs.end(); ++g_it){
        render(*g_it);
    }

    glPopMatrix();
}




void renderScene(void) {


    // clear buffers
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();


    glPolygonMode(GL_FRONT_AND_BACK, mode);
    ilEnable(IL_ORIGIN_SET);
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT);



    gluLookAt(cX,cY,cZ,0.0,0.0,0.0,0.0f,1.0f,0.0f);
    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    glRotatef(angZ,0,0,1);
    glTranslatef(ptX,ptY,ptZ);

    /*glRotatef(angleX,0,1,0);
    glRotatef(angleY,0,0,1);


    glTranslatef(0.0f,0.0f,-cRad);
    glRotatef(angleX,1.0,0.0,0.0);

    glRotatef(angleY,0.0,1.0,0.0);
    glTranslatef(-xp,-yp,-zp);
*/

    glColor3f(255,255,255);


    //axis();

    render(scene);
    displayFPS();
    // End of frame
    glutSwapBuffers();
    angle++;

}



void initGL(){

    // OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    // Textures
    glEnable(GL_TEXTURE_2D);

    glEnable(GL_LIGHT0);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Refresh normals after scale
    glEnable(GL_NORMALIZE);

}

int main(int argc, char **argv) {

    // put GLUT init here
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("CG_Trabalho");
    mode = GL_FILL;


    if(argc < 2){
        cout << "Invalid input. Use -h if you need some help." << endl;
        return 0;
    }
    else if(!strcmp(argv[1],"-h") || !strcmp(argv[1],"-help")){
        print_help();
        return 0;
    }
    else
        scene = parseXML(argv[1]);

    if(scene){

        // put callback registration here
        glutDisplayFunc(renderScene);
        glutIdleFunc(renderScene);
        glutReshapeFunc(changeSize);

        // put here the registration of the keyboard callbacks
        glutKeyboardFunc(normal_key);
        glutSpecialFunc(special_key);

        //glutKeyboardFunc(key_normal);
        //glutSpecialFunc(key_special);

        ilInit();
        ilEnable(IL_ORIGIN_SET);
        ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

        glewInit();

// glewInit();

        initGL();

        // enter GLUT's main loop
        glutMainLoop();
    }

    return 0;

}
