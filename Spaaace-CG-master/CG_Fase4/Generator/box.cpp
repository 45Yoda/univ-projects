#include "box.h"

using std::vector;

vector<Point*> box(float x, float y, float z, int div,vector<Point*> *normals,vector<Point*> *textures){

    vector<Point*> points;
    float shiftX = x/div;
    float shiftY = y/div;
    float shiftZ = z/div;

    float textX1 = z/((z*2) + (x*2));
    float textX2 = (z+x)/((z*2)+(x*2));
    float textX3 = ((z*2)+x)/((z*2)+(x*2));

    float textY1 = z/((z*2)+y);
    float textY2 = (z+y)/((z*2)+y);

    float textShiftX = (x/((z*2)+(x*2)))/float(div);
    float textShiftY = (y/((z*2)+y))/float(div);
    float textShiftZ = (z/((z*2)+(x*2)))/float(div);

    x = x/2;
    y = y/2;
    z = z/2;



    for(int i=0;i<div;i++){
        for(int j=0;j<div;j++){
            //Front
            points.push_back(new Point(-x + (j*shiftX),-y + (i*shiftY),z));
            points.push_back(new Point((-x+shiftX) + (j*shiftX),-y + (i*shiftY),z));
            points.push_back(new Point(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),z));

            normals->push_back(new Point(0,0,1));
            normals->push_back(new Point(0,0,1));
            normals->push_back(new Point(0,0,1));

            textures->push_back(new Point(textX1+(j*textShiftX),textY1+(i*textShiftY),0));
            textures->push_back(new Point((textX1+textShiftX)+(j*textShiftX),textY1+(i*textShiftY),0));
            textures->push_back(new Point(textX1+(j*textShiftX),(textY1+textShiftY)+(i*textShiftY),0));



            points.push_back(new Point(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),z));
            points.push_back(new Point((-x+shiftX) + (j*shiftX),-y + (i*shiftY),z));
            points.push_back(new Point((-x+shiftX) + (j*shiftX),(-y+shiftY) + (i*shiftY),z));

            normals->push_back(new Point(0,0,1));
            normals->push_back(new Point(0,0,1));
            normals->push_back(new Point(0,0,1));

            textures->push_back(new Point(textX1+(j*textShiftX),(textY1+textShiftY)+(i*textShiftY),0));
            textures->push_back(new Point((textX1+textShiftX)+(j*textShiftX),textY1+(i*textShiftY),0));
            textures->push_back(new Point((textX1+textShiftX)+(j*textShiftX),(textY1+textShiftY)+(i*textShiftY),0));


            //Back
            points.push_back(new Point(-x + (j*shiftX),-y + (i*shiftY),-z));
            points.push_back(new Point(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
            points.push_back(new Point((-x+shiftX) + (j*shiftX),-y + (i*shiftY),-z));

            normals->push_back(new Point(0,0,-1));
            normals->push_back(new Point(0,0,-1));
            normals->push_back(new Point(0,0,-1));

            textures->push_back(new Point(1-(j*textShiftX),textY1+(i*textShiftY),0));
            textures->push_back(new Point(1-(j*textShiftX),(textY1+textShiftY)+(i*textShiftY),0));
            textures->push_back(new Point((1-textShiftX)-(j*textShiftX),textY1+(i*textShiftY),0));



            points.push_back(new Point(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
            points.push_back(new Point((-x+shiftX) + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
            points.push_back(new Point((-x+shiftX) + (j*shiftX),-y + (i*shiftY),-z));

            normals->push_back(new Point(0,0,-1));
            normals->push_back(new Point(0,0,-1));
            normals->push_back(new Point(0,0,-1));

            textures->push_back(new Point(1-(j*textShiftX),(textY1+textShiftY)+(i*textShiftY),0));
            textures->push_back(new Point((1-textShiftX)-(j*textShiftX),(textY1+textShiftY)+(i*textShiftY),0));
            textures->push_back(new Point((1-textShiftX)-(j*textShiftX),textY1+(i*textShiftY),0));




            //Right
            points.push_back(new Point(x,-y + (i*shiftY),-z + (j*shiftZ)));
            points.push_back(new Point(x,(-y+shiftY) + (i*shiftY),-z +(j*shiftZ)));
            points.push_back(new Point(x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));

            normals->push_back(new Point(1,0,0));
            normals->push_back(new Point(1,0,0));
            normals->push_back(new Point(1,0,0));

            textures->push_back(new Point(textX3-(j*textShiftZ),textY1+(i*textShiftY),0));
            textures->push_back(new Point(textX3-(j*textShiftX),(textY1+textShiftY)+(i*textShiftY),0));
            textures->push_back(new Point((textX3-textShiftZ)-(j*textShiftZ),textY1+(i*textShiftY),0));


            points.push_back(new Point(x,(-y+shiftY) + (i*shiftY),-z + (j*shiftZ)));
            points.push_back(new Point(x,(-y+shiftY) + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
            points.push_back(new Point(x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));

            normals->push_back(new Point(1,0,0));
            normals->push_back(new Point(1,0,0));
            normals->push_back(new Point(1,0,0));

            textures->push_back(new Point(textX3-(j*textShiftZ),(textY1+textShiftY)+(i*textShiftY),0));
            textures->push_back(new Point((textX3-textShiftZ)-(j*textShiftX),(textY1+textShiftY)+(i*textShiftY),0));
            textures->push_back(new Point((textX3-textShiftZ)-(j*textShiftX),textY1+(i*textShiftY),0));


            //Left
            points.push_back(new Point(-x,-y + (i*shiftY),-z + (j*shiftZ)));
            points.push_back(new Point(-x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
            points.push_back(new Point(-x,(-y+shiftY) + (i*shiftY),-z +(j*shiftZ)));

            normals->push_back(new Point(-1,0,0));
            normals->push_back(new Point(-1,0,0));
            normals->push_back(new Point(-1,0,0));

            textures->push_back(new Point((j*textShiftZ),textY1+(i*textShiftY),0));
            textures->push_back(new Point(textShiftZ+(j*textShiftZ),textY1+(i*textShiftY),0));
            textures->push_back(new Point((j*textShiftX),(textY1+textShiftY)+(i*textShiftY),0));



            points.push_back(new Point(-x,(-y+shiftY) + (i*shiftY),-z + (j*shiftZ)));
            points.push_back(new Point(-x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
            points.push_back(new Point(-x,(-y+shiftY) + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));

            normals->push_back(new Point(-1,0,0));
            normals->push_back(new Point(-1,0,0));
            normals->push_back(new Point(-1,0,0));

            textures->push_back(new Point((j*textShiftZ),(textY1+textShiftY)+(i*textShiftY),0));
            textures->push_back(new Point(textShiftZ+(j*textShiftZ),textY1+(i*textShiftY),0));
            textures->push_back(new Point(textShiftZ+(j*textShiftX),(textY1+textShiftY)+(i*textShiftY),0));

            

            //Top
            points.push_back(new Point(-x + (j*shiftX),y,-z + (i*shiftZ)));
            points.push_back(new Point(-x + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
            points.push_back(new Point((-x+shiftX) + (j*shiftX),y,-z + (i*shiftZ)));

            normals->push_back(new Point(0,1,0));
            normals->push_back(new Point(0,1,0));
            normals->push_back(new Point(0,1,0));

            textures->push_back(new Point(textX1+(j*textShiftX),(1-textShiftZ)-(i*textShiftZ),0));
            textures->push_back(new Point((textX1+textShiftX)+(j*textShiftX),(1-textShiftZ)-(i*textShiftZ),0));
            textures->push_back(new Point((textX1+textShiftX)+(j*textShiftX),1-(i*textShiftZ),0));

            points.push_back(new Point(-x + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
            points.push_back(new Point((-x+shiftX) + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
            points.push_back(new Point((-x+shiftX) + (j*shiftX),y,-z + (i*shiftZ)));

            normals->push_back(new Point(0,1,0));
            normals->push_back(new Point(0,1,0));
            normals->push_back(new Point(0,1,0));

            textures->push_back(new Point(textX1+(j*textShiftX),(1-textShiftZ)-(i*textShiftZ),0));
            textures->push_back(new Point((textX1+textShiftX)+(j*textShiftX),(1-textShiftZ)-(i*textShiftZ),0));
            textures->push_back(new Point((textX1+textShiftX)+(j*textShiftX),1-(i*textShiftZ),0));


            //Bottom
            points.push_back(new Point(-x + (j*shiftX),-y,-z + (i*shiftZ)));
            points.push_back(new Point((-x+shiftX) + (j*shiftX),-y,-z + (i*shiftZ)));
            points.push_back(new Point(-x + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));

            normals->push_back(new Point(0,-1,0));
            normals->push_back(new Point(0,-1,0));
            normals->push_back(new Point(0,-1,0));

            textures->push_back(new Point(textX1+(j*textShiftX),(i*textShiftZ),0));
            textures->push_back(new Point((textX1+textShiftX)+(j*textShiftX),(i*textShiftZ),0));
            textures->push_back(new Point(textX1+(j*textShiftX),textShiftZ+(i*textShiftZ),0));


            points.push_back(new Point(-x + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));
            points.push_back(new Point((-x+shiftX) + (j*shiftX),-y,-z + (i*shiftZ)));
            points.push_back(new Point((-x+shiftX) + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));

            normals->push_back(new Point(0,-1,0));
            normals->push_back(new Point(0,-1,0));
            normals->push_back(new Point(0,-1,0));

            textures->push_back(new Point(textX1+(j*textShiftX),textShiftZ+(i*textShiftZ),0));
            textures->push_back(new Point((textX1+textShiftX)+(j*textShiftX),(i*textShiftZ),0));
            textures->push_back(new Point((textX1+textShiftX)+(j*textShiftX),textShiftZ+(i*textShiftZ),0));

        }
    }
    return points;
}