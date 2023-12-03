
#include "Road.h"
#include <iostream>
#include "Vec.h"



Cross::Cross(vec3 position){
    pos = position;
    //allowedVeh = 0;

    //cout<<(streets[0]==NULL)<<endl<<(streets[1]==NULL)<<endl;
    //cout<<streets[0].street<<endl;

}

void Cross::update(float delta) {

    
}

void Cross::draw() {
    setColor(1, 0, 0);
    drawCube(0.6, 0.1, 0.6);
}

Road::Road(Cross* begCross, Cross* endCross) {

    crossBeg = begCross;
    crossEnd = endCross;

    length = Vec::dst(crossBeg->getPos(), crossEnd->getPos());
    direction = normalize(crossEnd->getPos() - crossBeg->getPos());
    
    Cross::OneStreet tmp;
    tmp.street = this;
    tmp.enabled = true;
    tmp.direction = true;
    tmp.jointPos = crossBeg->getPos() + direction * 0.3f;

    crossBeg->streets.push_back(tmp);

    tmp.direction = false;
    tmp.jointPos = crossEnd->getPos() - direction * 0.3f;
    crossEnd->streets.push_back(tmp);

    begPos = crossBeg->getPos();
    endPos = crossEnd->getPos();

    normal = normalize(Vec::cross(vec3(0, 1, 0), direction));

}

void Road::draw() {

    setColor(0.3, 0.3, 0.3);
    drawLine(crossBeg->getPos(), crossEnd->getPos());

    vec3 sizer = normalize(Vec::cross(vec3(0, 1, 0), direction));
    sizer *= 0.3;

    vec3 a = endPos + sizer;
    vec3 b = endPos - sizer;
    vec3 c = begPos + sizer;
    vec3 d = begPos - sizer;

    glBegin(GL_POLYGON);
    glVertex3f(a.x, a.y, a.z);
    glVertex3f(b.x, b.y, b.z);
    glVertex3f(d.x, d.y, d.z);
    glVertex3f(c.x, c.y, c.z);
    glEnd();
}

Garage::Garage(vec3 p, Cross* c)
{
    pos = p;
    crossEnd = c;
    crossBeg = NULL;

    begPos = pos;
    endPos = crossEnd->getPos();

    length = Vec::dst(begPos, endPos);

    Cross::OneStreet temp;
    temp.street = this;
    temp.enabled = false;

    crossEnd->streets.push_back(temp);

    direction = normalize(endPos - begPos);

    normal = normalize(Vec::cross(vec3(0, 1, 0), direction));

    curTime = 0;
    frec = 3;
}

void Garage::draw()
{
    setColor(0, 0, 1);
    drawCube(1);
}

void Garage::update(float delta)
{

    /*
    if (vehiclesBeg.size() == 0 || (vehiclesBeg.size() > 0 && vehiclesBeg.back()->xPos > 1))
        curTime += delta;
    if (curTime > frec)
    {
        curTime = 0;
        spotCar();
    }
    */
}

/*
void Garage::spotCar() {
    //number ++;
//if (number > 3) return;
    Car* temp;
    temp = new Car(this);
    temp->curRoad = this;
    temp->direction = true;
    temp->id = "CAR_" + itos(Vehicle::numVeh) + id;
    temp->isFirstVeh = vehiclesBeg.size() == 0;
    vehiclesBeg.push(temp);
    //    gameEngine->registerObject(temp);
    registerNewObject(gameEngine, temp);

    cout << "spotted " << temp->id << " by " << id << endl;
}
}*/