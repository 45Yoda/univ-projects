#include "Car.h"
#include "Manager.h"


using namespace std;




Car::Car(Parser::WayData wdata, int id) {
	color = Colors::getRandomColor();

	currentSegment = 0;

	segmentDistances = wdata.distanceSegments[0];

	// TODO ADDED
	currentDistances = wdata.distanceTables[0];

	/*	cout << "THIS IS THE NUMBER OF SEGMENTS" << currentDistances.size() << endl;
	for (auto const& curr : currentDistances) {
		for (int i = 0; i < curr.size(); i++) {
			cout << "THIS IS THE STUFF" << curr[i] << endl;
		}
	}*/

	//for (auto const& seg : wdata.distanceSegments) {
	//	for (int i = 0; i < seg.size(); i++) {
	//		cout << "SEG SIZE-> " << seg[i] << endl;
	//	}
	//}

	currentTValues = wdata.tvalue;


	// TODO REMOVE NOT DEBUG
	carID = id;

	firstVector = wdata.choices[0];

	currentVector = wdata.choices[0];

	totalDists = wdata.totalDistance;

	// This is the last vector's starting node
	firstPosLastVec = NULL;

	createPath(wdata.choices[0]);

	firstPosLastVec = wdata.choices[0][0];


	// BOTH SHOULD BE REPLACED
	//First position
	position = currentPath->getPoint(currentSegment, 0.0);

	//TODO do i really need 2?
	derivStore = currentPath->getDerivative(currentSegment, 0.0);

	deriv = glm::value_ptr(derivStore);

	vec3 res = glm::cross(derivStore, vec3(0, 1, 0));

	res = glm::normalize(res);

	newPos = position + res;

	up[0] = 0;
	up[1] = 1;
	up[2] = 0;

	//Manager::getInstance()->shout();
}

void Car::normalize(float* a) {


	float l = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	a[0] = a[0] / l;
	a[1] = a[1] / l;
	a[2] = a[2] / l;

}



void Car::cross(float* a, float* b, float* res) {


	res[0] = a[1] * b[2] - a[2] * b[1];
	res[1] = a[2] * b[0] - a[0] * b[2];
	res[2] = a[0] * b[1] - a[1] * b[2];

}



void Car::curveRotation(float* der, float* up) {

	float left[3];
	cross(der, up, left);

	// cross made to change up vector if the car is going up a ramp for example.
	cross(left, der, up);

	normalize(der);
	normalize(up);
	normalize(left);

	float m[4][4] = { { der[0], der[1], der[2], 0 },
					  { up[0], up[1], up[2], 0 },
					  { left[0], left[1], left[2], 0 },
					  { 0.0f, 0.0f, 0.0f, 1 },
	};

	glMultMatrixf((float*)m);

}

float Car::lerp(float a, float b, float f) {
	return (a * (1.0 - f)) + (b * f);
}


// Updates the position of the car using the deltaTime.
// If the currentPath hasn't ended (stop = 0) then we update the position
// if it has ended then we give it another vector using the giveVector function.
// If there is another vector available then the path is generated 
// if no vector is available (finalStop =1) then the car is stopped. (or removed need to think about that) TooBad
void Car::update() {

	if (!timeFlag) {
		cout << "Over Here!" << endl;
		start = chrono::steady_clock::now();
		timeFlag = 1;
	}

	check = chrono::steady_clock::now();

	chrono::duration<double> elapsed_seconds = check - start;

	// Check if the currentPath has more segments. If it doesn't we need to give it a new path/vector and reset the clock
	// Not applicable anymore please change this comment
	
	
	if (exited) {
		cout << "Ready to reset part 2" << endl;
		cout << "DID I FALL HERE?" << endl;
	}
	else {


		if (currentSegment < currentPath->getSegmentNumber()) {

			distandTval(elapsed_seconds.count());

			vec3 res = glm::cross(derivStore, vec3(0, 1, 0));
			res = glm::normalize(res);
			newPos = position + res;
		}
		else {
			giveVector(currentVector[currentVector.size() - 1]);

			createPath(currentVector);

			currentSegment = 0;

		}
	}
	glTranslatef(newPos.x, newPos.y, newPos.z);

	deriv = glm::value_ptr(derivStore);
	curveRotation(deriv, up);
}

// Changes the currentVector variable by searching the Map for a key equal to the given Node (lastNode)
// if lastNode can't be found then the car stops (finalStop = 1)
// else a vector is randomly choosen 
void Car::giveVector(Parser::Node* lastNode) {
	countExits = 0;
	//cout << "Inside giveVector Function" << endl;

	// TooBad Testing if I can capture the exit and change the exit flag to true
	vector<long long>::iterator it;
	long long last_id = lastNode->id;

	// Finding the node
	it = find(begin(mapExits), end(mapExits), last_id);

	if (it != end(mapExits)) {
		exited = 1;
	}

	// end

	if (lastNode->isJunc && !shouldExit) {
		// This part takes care of the junctions

		map<long long, Parser::Junction> currentJuncsMap = Parser::getJunctions();

		

		if (currentJuncsMap.count(lastNode->id) > 0) {

			Parser::Junction currentJunc = currentJuncsMap[lastNode->id];

			//Will be used to obtain a seed for the random number engine
			random_device rd;
			//Standard mersenne_twister_engine seeded with rd()
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(0, currentJunc.exits.size() - 1);

			int exit = distrib(gen);


			long long finalNode = currentJunc.exits[exit];
			long long currNode = lastNode->id;

			vector<Parser::Node*>::iterator it;
			long long id = currNode;

			// Predicate to capture node with the same id as the reference
			auto pred = [id](const Parser::Node* node) {
				return node->id == id;
			};

			// Finding the node
			it = find_if(begin(currentJunc.fullWay), end(currentJunc.fullWay), pred);

			if (it == end(currentJunc.fullWay)) {
				cout << "EXIT NOT FOUND" << endl;
			}

			// Get index of element from iterator
			int index = std::distance(begin(currentJunc.fullWay), it);

			vector<Parser::Node*> vecToGo;

			// Get a subvector with the way to give to the path algorithm
			// THIS IS PROBABLY WRONG.
			// Place the if outside. If the finalNode == currNode make the car do the full roundabout and use it as an exit
			// else use the while to find the subvector.

			if (finalNode == currNode) {
				vecToGo = currentJunc.fullWay;
			}
			else {

				while (finalNode != currNode) {


					// If the index is still under the size of the fullWay vector then add to the vecToGo vector, update the current node and the index.
					if (index < currentJunc.fullWay.size() - 1) {

						vecToGo.push_back(currentJunc.fullWay[index]);

						currNode = currentJunc.fullWay[index]->id;

						index++;
					}
					// If the index is over the size of the fullWay vector, start from the beginning of the vector (since we are in a junction)
					else {

						index = 0;
					}

				}
			}

			currentDistances = currentJunc.distanceTables[exit];
			segmentDistances = currentJunc.distanceSegments[exit];
			currentTValues = currentJunc.tvalue;


			// TooBad Possibly fucked here
			firstPosLastVec = lastNode;
			currentVector = vecToGo;
			shouldExit = 1;


		}

		else {
			exited = 1;
		}

		cout << "Hi" << endl;
	}
	else {
		// This part takes care of the normal paths
		shouldExit = 0;

		//currentPath->askInfo();
		map < long long, Parser::WayData> currentMap = Parser::getMap();
		
		// if the node is a key in the map
		if (currentMap.count(lastNode->id) != 0) {

			//cout << "NORMAL ROADS" << endl;
			Parser::WayData wdata = currentMap[lastNode->id];

			vector<vector<Parser::Node*>> vectorSet = wdata.choices;

			//Will be used to obtain a seed for the random number engine
			random_device rd;
			//Standard mersenne_twister_engine seeded with rd()
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(0, vectorSet.size() - 1);

			int index = distrib(gen);


			//I think this doesn't do shit.. TooBad
			// Hypothetically we compare the id of the firstPosLastVec (aka the first node of the last used vector)
			// with the id of the last node of the current vector (this is to not go back in the middle of the street i guess)
			// if it is the same we choose a new one.

			while (vectorSet[index].back()->id == firstPosLastVec->id && vectorSet.size() > 1) {
				index = distrib(gen);
			}

			currentDistances = wdata.distanceTables[index];
			segmentDistances = wdata.distanceSegments[index];
			currentTValues = wdata.tvalue;


			firstPosLastVec = vectorSet[index][0];
			currentVector = vectorSet[index];
		}
		else {
			cout << "Ready to reset" << endl;
			exited = 1;
		}

	}

}

void Car::distandTval(double time) {

	double newDistance = oldDistance + speed * time;
	oldDistance = newDistance;

	double t = 0.0;
	int ind = 0;
	int give = 0;

	double compDist = newDistance - totalDistTraveled;
	//cout << "COMPARABLE DISTANCE " << compDist << endl;
	//cout << "OLD DISTANCE" << oldDistance << endl;

	if (compDist >= segmentDistances[currentSegment]) {
		give = 1;
		t = 1.0;
	}
	else {

		for (int i = 0; i < currentDistances[currentSegment].size(); i++) {


			if (currentDistances[currentSegment][i] > compDist) {
				ind = i;
				break;
			}
		}

		if (ind == 0) {
			t = 0.0;
		}
		else {


			if (ind == currentDistances[currentSegment].size() - 1) {
				t = 1;
				double dis = segmentDistances[currentSegment];



				//oldDistance = 0;


				//if this happens I need to increment the segment because I am at the end
				give = 1;


			}
			else {
				// RECHECK THIS 
				t = currentTValues[ind - 1] + ((compDist - currentDistances[currentSegment][ind - 1]) / (currentDistances[currentSegment][ind] - currentDistances[currentSegment][ind - 1])) * (currentTValues[ind] - currentTValues[ind - 1]);
				if (t > 1) {
					cout << "DOES THIS HAPPEN? " << endl;
					give = 1;
					// SHOULD I ACCOUNT FOR THE EXCESS HERE? TooBad
				}
				else
					give = 0;
			}
		}

	}

	position = currentPath->getPoint(currentSegment, t);
	derivStore = currentPath->getDerivative(currentSegment, t);

	if (give) {
		// UpdatedNow changed this to use the segmentDistances
		totalDistTraveled += segmentDistances[currentSegment];
		currentSegment++;
	}
}


// Creates Paths from the vectors of nodes by looping through the vector, pushing the coords to the Path variable and generating the Path
// in the end set the currentPath to path
void Car::createPath(vector<Parser::Node*> wayVec) {

	Path* path = new Path();

	int j = 0;

	// TODO REMOVE
	//cout << "START" << endl;
	for (int i = 0; i < wayVec.size(); i++) {

		//cout << wayVec[i]->id << endl;


		path->pushInfo(wayVec[i]->id, vec3(wayVec[i]->lon, 0, wayVec[i]->lat));

	}


	path->generatePath();

	currentPath = path;

	//REMOVE
	//path->askInfo();


}

void Car::draw() {

	setColor(color);
	glTranslatef(0, 0.2, 0);
	drawCube(2.5, 0.5, 1.25);

	// upper car part
	glPushMatrix();
	glTranslatef(-0.1, 0.35, -0.1);
	drawCube(1.25, 0.75, 1.25);
	glPopMatrix();

	//Direction check
	/*glBegin(GL_TRIANGLES);
	glVertex3f(20, 0, 10);
	glVertex3f(30, 0, 0);
	glVertex3f(20, 0, -10);
	glEnd();*/

}


void Car::setCars(Car* c) {
	testCar = c;
}

void Car::drawCube(float x, float y, float z) const {


	x /= 2;
	y /= 2;
	z /= 2;

	glBegin(GL_TRIANGLES);

	// Front
	glVertex3f(x, y, z);
	glVertex3f(-x, y, z);
	glVertex3f(-x, -y, z);

	glVertex3f(-x, -y, z);
	glVertex3f(x, -y, z);
	glVertex3f(x, y, z);

	// Right
	glVertex3f(x, y, -z);
	glVertex3f(x, y, z);
	glVertex3f(x, -y, z);

	glVertex3f(x, -y, z);
	glVertex3f(x, -y, -z);
	glVertex3f(x, y, -z);

	// Top
	glVertex3f(x, y, -z);
	glVertex3f(-x, y, -z);
	glVertex3f(-x, y, z);

	glVertex3f(-x, y, z);
	glVertex3f(x, y, z);
	glVertex3f(x, y, -z);

	// Left
	glVertex3f(-x, y, z);
	glVertex3f(-x, y, -z);
	glVertex3f(-x, -y, -z);

	glVertex3f(-x, -y, -z);
	glVertex3f(-x, -y, z);
	glVertex3f(-x, y, z);

	// Bottom
	glVertex3f(-x, -y, -z);
	glVertex3f(x, -y, -z);
	glVertex3f(x, -y, z);

	glVertex3f(x, -y, z);
	glVertex3f(-x, -y, z);
	glVertex3f(-x, -y, -z);

	// Back
	glVertex3f(x, -y, -z);
	glVertex3f(-x, -y, -z);
	glVertex3f(-x, y, -z);

	glVertex3f(-x, y, -z);
	glVertex3f(x, y, -z);
	glVertex3f(x, -y, -z);

	glEnd();

}


void Car::setColor(const float r, const float g, const float b) {

	glColor3f(r, g, b);

}

void Car::setColor(const vec3 color) {

	glColor3f(color.x, color.y, color.z);

}

// NEEDS TO BE UPDATED TODO HEY

void Car::reset() {

	exited = 0;

	timeFlag = 0;

	color = Colors::getRandomColor();

	currentSegment = 0;

	oldDistance = 0;


	// This is the last vector's starting node
	firstPosLastVec = NULL;

	createPath(currentVector);

	firstPosLastVec = currentVector[0];

	//First position
	position = currentPath->getPoint(currentSegment, 0.0);

	//TODO do i really need 2?
	derivStore = currentPath->getDerivative(currentSegment, 0);

	deriv = glm::value_ptr(derivStore);


	vec3 res = glm::cross(derivStore, vec3(0, 1, 0));

	res = glm::normalize(res);

	newPos = position + res;


}