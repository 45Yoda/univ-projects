
#include "shape.h"


Shape::Shape(){

}

/*Shape::Shape(string i, vector<Point*> list){
    name = i;
    points = list;
}*/

Shape::Shape(vector<Point*> pList, vector<Point*> nList, vector<Point*> tList){

    pointsSize = pList.size();
    normalsSize = nList.size();
    texturesSize = tList.size();
    readyUp(pList,nList,tList);

}

/*string Shape::getName(){
    return name;
}*/


Material* Shape::getColorComponent(){
    return colorComponent;
}

void Shape::setColorComponent(Material* c){
    colorComponent = c;
}

void Shape::readyUp(vector<Point*> points, vector<Point*> normals, vector<Point*> textures){
    int index = 0;
    float* vertex_array = (float*) malloc(sizeof(float) * points.size() * 3);
    float* normal_array = (float*) malloc(sizeof(float) * normals.size() * 3);
    float* texture_array = (float*) malloc(sizeof(float) * textures.size() * 2);

    for(vector<Point*>::const_iterator vertex_it = points.begin(); vertex_it != points.end(); ++vertex_it){
        vertex_array[index] = (*vertex_it)->getX();
        vertex_array[index+1] = (*vertex_it)->getY();
        vertex_array[index+2] = (*vertex_it)->getZ();
        index+=3;
    }

    index = 0;
    for(vector<Point*>::const_iterator normal_it = normals.begin(); normal_it != normals.end(); ++normal_it){
        normal_array[index] = (*normal_it)->getX();
        normal_array[index+1] = (*normal_it)->getY();
        normal_array[index+2] = (*normal_it)->getZ();
        index+=3;
    }

    index = 0;
    for(vector<Point*>::const_iterator texture_it = textures.begin(); texture_it != textures.end(); ++texture_it){
        texture_array[index] = (*texture_it)->getX();
        texture_array[index+1] = (*texture_it)->getY();
        index+=2;
    }

    glGenBuffers(3, buffers);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * pointsSize * 3, vertex_array, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * normalsSize * 3, normal_array, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * texturesSize * 2, texture_array, GL_STATIC_DRAW);

    free(vertex_array);
    free(normal_array);
    free(texture_array);
}

void Shape::loadTexture(string texture_file) {

    string path = "../Textures/" + texture_file;
    unsigned int tw,th;
    unsigned char *texData;

    unsigned int ima[1];

    ilInit();
    ilGenImages(1, ima);
    ilBindImage(ima[0]);
    ilLoadImage((ILstring)path.c_str());
    tw = ilGetInteger(IL_IMAGE_WIDTH);
    th = ilGetInteger(IL_IMAGE_HEIGHT);
    ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    texData = ilGetData();

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
}



void Shape::draw(){

    colorComponent->draw();

    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    if(normalsSize){
        glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
        glNormalPointer(GL_FLOAT, 0, 0);
    }

    if(texturesSize){
        glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
        glTexCoordPointer(2, GL_FLOAT, 0, 0);
        glBindTexture(GL_TEXTURE_2D, texture);
    }

    glEnable(GL_LIGHTING);
    glDrawArrays(GL_TRIANGLES, 0, pointsSize * 3);
    glDisable(GL_LIGHTING);
    glBindTexture(GL_TEXTURE_2D, 0);

}
