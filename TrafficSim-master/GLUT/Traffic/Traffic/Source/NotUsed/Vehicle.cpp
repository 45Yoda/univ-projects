#include "Vehicle.h"

class Driveable;

Vehicle::Vehicle(Driveable *spawnRoad){

	initRandValues();

	velocity = 0;
	specs.vehicleLength = 0.2;
	xPos = 0;
	
	isBraking = false;


	dstToCross = 1000;
	direction = true;
	desiredTurn = 0;

	initPointers(spawnRoad);

	rot = vec3(0, curRoad->getDirection.angleXZ(), 0);

	color = Colors::getRandomColor();
	color *= 0.70f;

}

void Vehicle::initRandValues() {
	specs.maxV = randFloat(1, 1.5);
	specs.minV = randFloat(0.02, 0.08);
	specs.cornerVelocity = 1;
	specs.stopTime = randFloat(0.5, 0.8);
	specs.acceleration = randFloat(0.1, 0.2);
	specs.remainDst = randFloat(0.06, 0.08);
}

void Vehicle::initPointers(Driveable* spawnRoad) {

	curRoad = spawnRoad;
	curCross = nullptr;
	nextRoad = nullptr;

	back = nullptr;

	allowedToCross = false;
	crossState.isChanging = false;
	crossState.didReachCross = false;
	crossState.isLeavingRoad = false;

	front = NULL;
	isFirstVeh = true;

	if (curROad->vehiclesBeg.size() > 0) {
		
		isFirstVeh = false;
		front = curRoad->vehiclesBeg.back();
		front->back = this;
	}

}

void Vehicle::update(const float delta) {

	if (!crossState.isChanging && !crossState.didReachCross) {

		float prevVelocity = velocity;

		xPos += velocity * delta;

		setVelocity();
		checkVelocity(delta, prevVelocity);
		setNewPos();

		if (curRoad->getLength() - xPos < 2.4 && curCross == nullptr) {

			registerToCross();
		}
	}
	
	if (!crossState.isLeavingRoad && curCross != nullptr && nextRoad != nullptr && allowedToCross) {

		tryBeAllowedToEnterCross();
	}

	if (crossState.isChanging) {
		
		xPos += specs.cornerVelocity * delta;

		float s = xPos / curRoad->getLength();


		if (direction)
		{
			pos = Vec::lerp(curRoad->getBegJointWidth(direction), curRoad->getEndJointWidth(direction), s);
		}
		else
		{
			pos = Vec::lerp(curRoad->getEndJointWidth(direction), curRoad->getBegJointWidth(direction), s);
		}

		if (s > 1)
		{
			leaveRoad();
		}
	}

	if (crossState.didReachCross) {

		xPos += specs.cornerVelocity * delta;

		setCornerPosition();

		if (crossState.crossProgress >= 1) {

			enterNewRoad();
		}
	}
}

void Vehicle::setVelocity(float velocity) {

	velocity = 10.0f;

	/*
	float posDiff = getDst() - specs.vehicleLength / 2.0 - specs.remainDst;
	float newDst = velocity * specs.stopTime - specs.acceleration * specs.stopTime * specs.stopTime / 2.0;

	
	velocity = posDiff - specs.acceleration * specs.stopTime * specs.stopTime / 2.0;
	velocity /= specs.stopTime;
	*/
}

void Vehicle::checkVelocity(const float delta, float prevVelocity) {

	float braking = (velocity - prevVelocity) / delta;

	if (braking < -0.3) {
		
		isBraking = true;
	}
	else {

		isBraking = false;
	}

	if (velocity < specs.minV) {

		velocity = 0;
		isBraking = true;
	}

	if (velocity > specs.maxV) {

		velocity = specs.maxV;
	}
}

float Vehicle::getXPos() const{

	return xPos;
}

float Vehicle::getDstToCross() const
{
	return dstToCross;
}

void Vehicle::setNewPos() {

	if (xPos > curRoad->getLength())
	{
		xPos = curRoad->getLength();
	}

	float s = xPos / curRoad->getLength();

	if (s > 1)
	{
		s = 1;
	}

	if (direction)
	{
		pos = Vec3::lerp(curRoad->getBegJointWidth(direction), curRoad->getEndJointWidth(direction), s);
	}
	else
	{
		pos = Vec3::lerp(curRoad->getEndJointWidth(direction), curRoad->getBegJointWidth(direction), s);
	}

	dstToCross = curRoad->getLength() - xPos;
}


void Vehicle::registerToCross()
{
	allowedToCross = false;

	if (direction)
	{
		curCross = curRoad->crossEnd;
	}
	else
	{
		curCross = curRoad->crossBeg;
	}

	blinker.which = 0;

	if (curCross != nullptr)
	{
		for (unsigned int i = 0; i < curCross->streets.size(); i++)
		{
			if (curCross->streets[i].street == curRoad)
			{
				desiredTurn = randInt(0, curCross->streets.size() - 1);
				if (desiredTurn == (int)i) desiredTurn = (desiredTurn + 1) % curCross->streets.size();

				if (curCross->streets.size() == 2) desiredTurn = (i + 1) % 2;

				nextRoad = curCross->streets[desiredTurn].street;

				crossState.begRot = curRoad->direction.angleXZ();
				crossState.endRot = nextRoad->direction.angleXZ();

				if (!direction) crossState.begRot += 180;
				if (!curCross->streets[desiredTurn].direction) crossState.endRot += 180;

				blinker.which = rotateDirection(crossState.begRot, crossState.endRot);
				if (curCross->streets.size() == 2) blinker.which = 0;

				blinker.time = 0;
				blinker.isLighting = true;

				curCross->streets[i].vehicles.push_back(this);

				break;
			}
		}
	}
}

void Vehicle::tryBeAllowedToEnterCross()
{
	for (auto& street : curCross->streets)
	{
		if (street.street == nextRoad)
		{
			if (nextRoad->freeSpace(street.direction) > specs.vehicleLength + specs.remainDst)
			{
				crossState.isLeavingRoad = true;

				if (street.direction)
				{
					nextRoad->reservedSpaceBeg += specs.vehicleLength + specs.remainDst;
				}
				else
				{
					nextRoad->reservedSpaceEnd += specs.vehicleLength + specs.remainDst;
				}

				crossState.isChanging = true;
				crossState.didReachCross = false;
			}

			break;
		}
	}
}

void Vehicle::leaveRoad()
{
	xPos = 0;
	crossState.didReachCross = true;
	crossState.isChanging = false;

	if (curCross->streets[desiredTurn].direction)
	{
		nextRoadJoint = nextRoad->getBegJointWidth(curCross->streets[desiredTurn].direction);
	}
	else
	{
		nextRoadJoint = nextRoad->getEndJointWidth(curCross->streets[desiredTurn].direction);
	}

	if (backVeh != nullptr)
	{
		backVeh->isFirstVeh = true;
		backVeh->frontVeh = nullptr;
	}

	crossState.begRot = curRoad->direction.angleXZ();
	crossState.endRot = nextRoad->direction.angleXZ();

	if (!direction) crossState.begRot += 180;
	if (!curCross->streets[desiredTurn].direction) crossState.endRot += 180;
}

void Vehicle::setCornerPosition()
{
	float tempLength;
	float s;

	if (direction)
	{
		tempLength = Vec::length(curRoad->getEndJointWidth(direction) - nextRoadJoint);
		s = xPos / tempLength;

		if (s > 1)s = 1;

		pos = Vec::lerp(curRoad->getEndJointWidth(direction), nextRoadJoint, s);
	}
	else
	{
		tempLength = Vec::length(curRoad->getBegJointWidth(direction) - nextRoadJoint);
		s = xPos / tempLength;

		if (s > 1)s = 1;

		pos = Vec::lerp(curRoad->getBegJointWidth(direction), nextRoadJoint, s);
	}

	rot = Vec(0, lerpAngle(crossState.begRot, crossState.endRot, s), 0);
	crossState.crossProgress = s;
}

void Vehicle::enterNewRoad()
{
	if (backVeh != nullptr)
	{
		backVeh->isFirstVeh = true;
		backVeh->frontVeh = nullptr;
	}

	if (direction)
	{
		curRoad->vehiclesBeg.pop();
	}
	else
	{
		curRoad->vehiclesEnd.pop();
	}

	xPos = 0;
	isBraking = false;

	allowedToCross = false;

	crossState.isChanging = false;
	crossState.didReachCross = false;
	crossState.isLeavingRoad = false;

	velocity = specs.cornerVelocity;

	curRoad = curCross->streets[desiredTurn].street;

	direction = curCross->streets[desiredTurn].direction;

	//dstToCross = curCross->getLength();

	if (direction)
	{
		nextRoad->reservedSpaceBeg -= specs.vehicleLength + specs.remainDst;
	}
	else
	{
		nextRoad->reservedSpaceEnd -= specs.vehicleLength + specs.remainDst;
	}

	curCross->allowedVeh--;
	desiredTurn = 0;

	back = nullptr;

	front = nullptr;
	isFirstVeh = true;

	if (direction)
	{
		if (curRoad->vehiclesBeg.size() > 0)
		{
			isFirstVeh = false;
			front = curRoad->vehiclesBeg.back();
			front->back = this;
		}
	}
	else
	{
		if (curRoad->vehiclesEnd.size() > 0)
		{
			isFirstVeh = false;
			front = curRoad->vehiclesEnd.back();
			front->backVeh = this;
		}
	}

	if (direction)
	{
		curRoad->vehiclesBeg.push(this);
	}
	else
	{
		curRoad->vehiclesEnd.push(this);
	}

	nextRoad = nullptr;
	curCross = nullptr;
}
