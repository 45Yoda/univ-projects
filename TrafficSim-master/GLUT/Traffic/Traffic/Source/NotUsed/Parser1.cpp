/*
#include "Parser.h"


void Parser::loadFile(const string fileName) {


	vector<vec3> positions;

	cout << "Loading objects from " << fileName << "....";

	ifstream file;
	file.open(fileName.c_str());


	if (file.good()) {

		while (!file.eof()) {

			try {

				string data;
				getline(file, data);
				stringstream ss;
				ss << data;

				if (ss.fail()) throw ExceptionClass("failed to read line of text");


				if (data == "") { // maybe works 
					continue;
				}
				string type;
				int id;

				ss >> type;

				if (ss.fail()) throw EmptyLineException();
				transform(type.begin(), type.end(), type.begin(), [](unsigned char c) -> unsigned char { return toupper(c); });

				ss >> id;
				if (ss.fail()) throw ExceptionClass("failed to read object ID");

				cout << endl;
				cout << "Type: " << type << endl;
				cout << "ID-> " << id << endl;

				// if(findObjectByName(id) != nullptr) add Exception here 

				if (type.compare("IN") == 0 || type.compare("INTERSECTION") == 0) {

					float x1, y1, z1;

					ss >> x1 >> y1 >> z1;
					if (ss.fail()) throw ExceptionClass("failed to load position of intersection " + id);

					vec3 v1(x1, y1, z1);

					cout << "Position: " << "x: " << x1 << " y: " << y1 << " z: " << z1;

					//TODO create INTERSECTION OBJECT HERE
					// Increment number of intersections
					city.numberIntersections++;

					positions.push_back(v1);

				}
				else if (type.compare("ST") == 0 || type.compare("STREET") == 0) {

					int begStreetId;
					int endStreetId;

					ss >> begStreetId >> endStreetId;
					if (ss.fail()) throw ExceptionClass("failed to load info about street " + id);

					// TODO Check if Both Intersections exist 
					cout << "HERE WE GOOOO: " << begStreetId << "WHERE TO: " << endStreetId << endl;

					//allocate space
					city.street.resize(city.numberIntersections);

					city.street[begStreetId].push_back(endStreetId);
					city.street[endStreetId].push_back(begStreetId);

				}

				for (int i = 0; i < positions.size(); i++) {

					vec3 tmp = positions[i];

					Graph::Intersection inter;

					inter.position = tmp;

					//inter.next_Intersections = city.street[i];

					city.intersections.push_back(inter);

					//int nrRoads = city.street[i].size();
				
				}

			}
			catch (ExceptionClass e) {
				cout << endl << "ERROR while loading" << e.what() << endl;
			}
		}





	}
	else {

		cout << "Something went wrong" << endl;
	}



}
*/