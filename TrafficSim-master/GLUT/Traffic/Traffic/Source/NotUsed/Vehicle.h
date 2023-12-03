#pragma once

#include "SimObject.h"
#include "Colors.h"

#include "Vec.h"

#include "glm/glm.hpp"

using namespace glm;

class Driveable;
class Cross;


class Vehicle : public SimObject {

public:

	Vehicle(Driveable *spawnRoad);

	float getXPos() const;
	float getDstToCross() const;

	virtual void initRandValues();
	struct Adjustable {
		float maxV; // max velocity
		float minV; // min velocity
		float cornerVelocity;
		float stopTime;
		float acceleration;
		float vehicleLength;
		float remainDst;
	}specs;


protected:

	virtual ~Vehicle() {};

	float velocity;
	float xPos;
	float isBraking;

	void update(const float delta);

	float getDst() const;
	bool isEnoughSpace() const;


	struct {
		
		bool isChanging;
		bool didReachCross;
		bool isLeavingRoad;

		float begRot;
		float endRot;
		float crossProgress;

	} crossState;

	vec3 color;

private:

	void initPointers(Driveable* spawnRoad);
	
	void setVelocity(float velocity);
	void checkVelocity(const float delta, float prevVelocity);
	void setNewPos();
	void registerToCross();


	void tryBeAllowedToEnterCross();
	void leaveRoad();
	void setCornerPosition();
	void enterNewRoad();

	float dstToCross;

	bool direction;

	int desiredTurn;
	Driveable* nextROad;
	bool allowedToCross;

	vec3 nextRoadJoint;

	Driveable* curRoad;
	Cross* curCross;

	Vehicle* front;
	Vehicle* back;
	bool isFirstVeh;

	friend Cross;
};

class Car : public Vehicle {

public:
	Car(Driveable* spawnRoad);

private:
	void update(const float delta);
	void draw();
	void drawRoof();

};