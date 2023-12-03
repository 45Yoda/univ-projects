#include "Parser.h"

// will be useful using the relations with the tag "restriction" to know what road rule 
// is enforced

// TODO add tag to the way!

map<long long, Parser::WayData> Parser::allWays;

map<long long, Parser::DrawData> Parser::waysToDraw;

map<long long, Parser::Junction> Parser::allJunctions;

vector<Parser::Junction> Parser::juncsToDraw;

vector<int> Parser::numbers;


void Parser::loadFile(char* fileName) {

	int flag = 0;

	XMLDocument doc;
	XMLPrinter printer;


	XMLError eResult = doc.LoadFile(fileName);
	if (eResult != XML_SUCCESS) cout << "File not Found" << endl;

	XMLNode* root = doc.FirstChildElement("osm");
	if (root == nullptr) cout << "Failed on FirstChildElement \"osm\"" << endl;

	XMLElement* bounds = root->FirstChildElement("bounds");
	if (bounds == nullptr) cout << "Failed on FirstChildElement \"bounds\"" << endl;

	// Constant that should be subtracted to the latitude to get values between 0 and 1

	/*
	string minlat = bounds->Attribute("minlat");
	string trunc_lat = minlat.substr(0, 6);
	float subtr_lat = stof(trunc_lat);
	*/
	double minlat = stod(bounds->Attribute("minlat"));
	double maxlat = stod(bounds->Attribute("maxlat"));


	// Constant that should be subtracted to the longitude to get values between 0 and 1
	/*
	string minlon = bounds->Attribute("minlon");
	string trunc_lon = minlon.substr(0, 6);
	float subtr_lon = stof(trunc_lon);
	*/

	double minlon = stod(bounds->Attribute("minlon"));
	double maxlon = stod(bounds->Attribute("maxlon"));

	// Constant to multiply both lat and lon

	//float mult = (400000 / 360) * sin(subtr_lat);

	//cout << mult << endl;

	// Equator Perimeter
	long long ep = 6378137;

	int width = 800;
	int height = 600;


	XMLElement* element = root->FirstChildElement("node");
	if (element == nullptr) cout << "Failed on FirstChildElement \"node\"" << endl;


	for (; element; element = element->NextSiblingElement()) {


		if (!strcmp(element->Name(), "node")) {

			//string ids = element->Attribute("id");


			long long id = stoll(element->Attribute("id"));
			// * 100 to see the paths easier 
			/*
			double lat = -(stod(element->Attribute("lat")) - subtr_lat) * mult * 100;
			double lon = (stod(element->Attribute("lon")) - subtr_lon) * mult * 100;
			*/

			double longitude = stod(element->Attribute("lon"));
			double latitude = stod(element->Attribute("lat"));



			double pixelY = ((latitude - minlat) / (maxlat - minlat)) * (height - 1);
			double pixelX = ((longitude - minlon) / (maxlon - minlon)) * (width - 1);


			double latRad = latitude * M_PI / 180;
			long long mercN = log(tan((M_PI / 4) + (latRad / 2)));
			long long meterY = (height / 2) - (width * mercN / (2 * M_PI));


			long long lon = -pixelX;
			long long lat = pixelY;


			// if node has a child element and it isn't a tag then continue
			if (element->FirstChild() != nullptr && strcmp(element->FirstChildElement()->Name(), "tag")) {

				//continue to next element don't push into nodes
				continue;
			}

			Node new_node;

			new_node.id = id;
			new_node.lat = lat;
			new_node.lon = lon;

			nodes.push_back(new_node);

		}
		if (!strcmp(element->Name(), "way")) {

			long long way_id = stoll(element->Attribute("id"));

			Way new_way;

			new_way.way_id = way_id;

			XMLElement* element_way = element->FirstChildElement("nd");
			if (element == nullptr) cout << "Failed on FirstChildElement \"nd of way\"" << endl;

			for (; element_way; element_way = element_way->NextSiblingElement()) {
				if (!strcmp(element_way->Name(), "nd")) {


					long long ref = stoll(element_way->Attribute("ref"));



					auto pred = [ref](const Node& node) {
						return node.id == ref;
					};

					// Finding the node
					vector<Node>::iterator it = find_if(nodes.begin(), nodes.end(), pred);

					if (it == nodes.end()) {
						continue;
					}


					int index = std::distance(nodes.begin(), it);

					//Count node ocurrences here 
					nodes[index].ocur++;


					//TODO Almost certain it works but check it 
					if (nodes[index].ocur > 1 && (find(nodesToAdd.begin(), nodesToAdd.end(), ref) == nodesToAdd.end())) {
						//Add to the map or add to an index vector
						nodesToAdd.push_back(ref);


					}


					new_way.node_refs.push_back(ref);

				}
				// HACK Found first tag need to check all other tags before knowing what type of road we are seeing
				if (!strcmp(element_way->Name(), "tag")) {

					int  i = 0;


					if (!strcmp(element_way->Attribute("k"), "oneway") && !strcmp(element_way->Attribute("v"), "yes") && flag != 3) {

						flag = 1;
						new_way.type = 1;

						//TooBad What the fuck is this?
						i += 1;
					}

					if (!strcmp(element_way->Attribute("k"), "junction") && !strcmp(element_way->Attribute("v"), "roundabout")) {

						flag = 4;
					}



					if (!strcmp(element_way->Attribute("k"), "lanes")) {
						string lanes;
						lanes = element_way->Attribute("v");

						pair<string, string> par("lanes", lanes);



						if (wayTags.find(new_way.way_id) == wayTags.end()) {

							vector<pair<string, string>> newPairVec;
							newPairVec.push_back(par);

							wayTags.emplace(new_way.way_id, newPairVec);
						}
						else {
							wayTags[new_way.way_id].push_back(par);
						}

					}

					if (!strcmp(element_way->Attribute("k"), "maxspeed")) {
						string maxspeed;
						maxspeed = element_way->Attribute("v");



						pair<string, string> par("maxspeed", maxspeed);

						cout << "NEW WAY" << new_way.way_id << endl;

						if (wayTags.find(new_way.way_id) == wayTags.end()) {
							vector<pair<string, string>> newPairVec;
							newPairVec.push_back(par);

							wayTags.emplace(new_way.way_id, newPairVec);
						}
						else {
							wayTags[new_way.way_id].push_back(par);
						}
					}


					if (!strcmp(element_way->Attribute("k"), "highway")) {

						if (!strcmp(element_way->Attribute("v"), "steps") || !strcmp(element_way->Attribute("v"), "footway") || !strcmp(element_way->Attribute("v"), "pedestrian")) {
							flag = 3;
						}
						else {

							// change flag if a road was found
							flag = 1;

							// if oneway is first in the file this if doesn't allow the type to change
							if (new_way.type == 0) {
								new_way.type = 2;
							}
						}
					}
					else {

						if (!strcmp(element_way->Attribute("k"), "building")) {
							flag = 2;
						}
						else {
							continue;
						}

					}
				}
			}


			switch (flag) {
			case 1: flag = 0;
				ways.push_back(new_way);
				break;
			case 2: flag = 0;
				buildings.push_back(new_way);
				break;
			case 3: flag = 0;
				pedestrians.push_back(new_way);
				break;
				//HACK need to see how to do this
			case 4: flag = 0;
				junctions.push_back(new_way);
				break;
			default: flag = 0;
				nodesToDelete.push_back(new_way);
				break;
				//add default that adds the way that wasn't added to any vector 
			}

		}
	}

	removeFromVec(buildings);
	removeFromVec(pedestrians);
	removeFromVec(nodesToDelete);


	// S
	setupTVals();

	// STUFFFFF
	createGraph();
	createJunctions();

	// NEW Entrances and exits gathering
	discoverEntranceAndExit();


}

void Parser::setupTVals() {
	for (double l = 0; l <= 1.01; l += 0.01) {
		tvals.push_back(l);
	}
}


void Parser::removeFromVec(vector<Way> someVec) {
	// Iterator to store the position of element found
	vector<Node>::iterator it;

	// TODO Added this
	vector<long long>::iterator it2;

	for (int i = 0; i < someVec.size(); i++) {

		Way someWay = someVec[i];

		for (int j = 0; j < someWay.node_refs.size(); j++) {

			long long id = someWay.node_refs[j];

			// Predicate to capture node with the same id as the reference
			auto pred = [id](const Node& node) {
				return node.id == id;
			};

			// Finding the node
			it = find_if(begin(nodes), end(nodes), pred);

			// TODO Added this
			it2 = find(begin(nodesToAdd), end(nodesToAdd), id);


			if (it == end(nodes)) {
				continue;
			}

			//TODO Added this shit
			if (it2 != end(nodesToAdd)) {
				int index2 = std::distance(begin(nodesToAdd), it2);
				nodesToAdd.erase(begin(nodesToAdd) + index2);
			}
			// ---------------------------------------------------

			// Get index of element from iterator
			int index = std::distance(begin(nodes), it);

			nodes.erase(begin(nodes) + index);

		}

	}
}
//
//void Parser::removeBuildings() {
//
//	// Iterator to store the position of element found
//	vector<Node>::iterator it;
//
//	// TODO Added this
//	vector<long long>::iterator it2;
//
//	for (int i = 0; i < buildings.size(); i++) {
//
//		Way building = buildings[i];
//
//		for (int j = 0; j < building.node_refs.size(); j++) {
//
//			long long id = building.node_refs[j];
//
//			//cout << "BUILDING ID: " << id << endl;
//
//			// Predicate to capture node with the same id as the reference
//			auto pred = [id](const Node& node) {
//				return node.id == id;
//			};
//
//			// Finding the node
//			it = find_if(begin(nodes), end(nodes), pred);
//
//			// TODO Added this
//			it2 = find(begin(nodesToAdd), end(nodesToAdd), id);
//
//
//			if (it == end(nodes)) {
//				continue;
//			}
//
//			//TODO Added this shit
//			if (it2 != end(nodesToAdd)) {
//				int index2 = std::distance(begin(nodesToAdd), it2);
//				nodesToAdd.erase(begin(nodesToAdd) + index2);
//			}
//			// ---------------------------------------------------
//
//			// Get index of element from iterator
//			int index = std::distance(begin(nodes), it);
//
//			nodes.erase(begin(nodes) + index);
//
//		}
//
//	}
//
//}


vector<vector<double>> Parser::calcDistances(vector<Parser::Node*> wayToAdd, double* totalD, vector<double>* distSegments) {
	vector<vector<double>> allDistTables;
	float totalDistance = 0;

	if (wayToAdd.size() != 0) {

		for (int i = 0; i < wayToAdd.size() - 1; i++) {

			vector<double> distTable;

			vec3 node1 = vec3(wayToAdd[i]->lon, 0, wayToAdd[i]->lat);
			vec3 node2 = vec3(wayToAdd[i + 1]->lon, 0, wayToAdd[i + 1]->lat);


			double segmentDist = sqrt(pow(node2.x - node1.x, 2) + pow(node2.z - node1.z, 2));

			//cout << "Segment Distance-> " << segmentDist << endl;

			for (double j = 0; j <= 1.01; j += 0.01) {

				distTable.push_back(segmentDist * j);
			}



			allDistTables.push_back(distTable);

			distSegments->push_back(segmentDist);


			totalDistance += segmentDist;

		}


		*totalD = totalDistance;

	}

	return allDistTables;
}

// Function to create graph after parsing
void Parser::createGraph() {

	// Iterator to store the position of element found
	vector<Node>::iterator it;


	map<long long, WayData>::iterator mapIt;

	vector<vector<Node*>> waysToCheck;

	// Adds all the nodes with more than 1 ocurrence here
	// TODO Remove possibly not needed anymore.
	// Can be useful to know the intersections where the car should slow down
	for (int a = 0; a < nodesToAdd.size(); a++) {

		long long ref = nodesToAdd[a];
		WayData newStruct;
		vector<vector<Node*>> newVec;
		newStruct.choices = newVec;
		allWays.emplace(ref, newStruct);

		// Structure for drawing only MEW
		DrawData drawStruct;
		drawStruct.draw_choices = newVec;
		waysToDraw.emplace(ref, drawStruct);


		// Intersection creation
		Intersection newIntersect;
		vector<vector<Node*>> conRoads;
		newIntersect.connectedRoads = conRoads;
		allIntersections.emplace(ref, newIntersect);


	}

	// can probably be removed soon REMOVE
	intersections = nodesToAdd;

	// Adds the first and last node (if it's a 2 way street) ids  to the ways map and creates empty vectors
	for (int l = 0; l < ways.size(); l++) {

		Way way = ways[l];



		// FIXME added this part //////// NEW Can also try to add these two ids when changing the flag back to 0
		long long id_first = way.node_refs[0];
		long long id_last = way.node_refs[way.node_refs.size() - 1];

		if ((find(nodesToAdd.begin(), nodesToAdd.end(), id_first)) == nodesToAdd.end()) {
			nodesToAdd.push_back(id_first);

			WayData newData;
			vector<vector<Node*>> vec;
			newData.choices = vec;
			vector<vector<vector<double>>> dist;
			newData.distanceTables = dist;
			vector<double> tval;
			newData.tvalue = tval;
			vector<vector<double>> distSegment;
			newData.distanceSegments = distSegment;
			allWays.emplace(id_first, newData);


			// Structure for drawing only MEW
			DrawData newDraw;
			newDraw.draw_choices = vec;
			waysToDraw.emplace(id_first, newDraw);


		}

		if ((find(nodesToAdd.begin(), nodesToAdd.end(), id_last)) == nodesToAdd.end() && way.type == 2) {

			nodesToAdd.push_back(id_last);

			WayData newData2;
			vector<vector<Node*>> vec2;
			newData2.choices = vec2;
			vector<vector<vector<double>>> dist2;
			newData2.distanceTables = dist2;
			vector<double> tval2;
			newData2.tvalue = tval2;
			vector<vector<double>> distSeg;
			newData2.distanceSegments = distSeg;
			allWays.emplace(id_last, newData2);

		}

	}


	// Loop through all saved ways and adds them to the appropriate vector on the allWays map.
	for (int i = 0; i < ways.size(); i++) {

		Way way = ways[i];

		vector<Node*> wayToAdd;


		// TooBad this is new not sure if needed
		long long wayId = way.way_id;

		allWayIDS.push_back(wayId);

		vector<pair<string, string>> tags = wayTags[wayId];

		/* TESTING
		interFound = 0;
		interPoints.clear();
		*/

		// Loop through the node refs of the current way and add to a vector (wayToAdd)
		// when the vector has more than 1 node if the current node reference is a key on the allWays map
		// push the vector to the map (using the first node's id as the key). 
		// After that clear the vector(wayToAdd) and push the current node to it to start a new way.
		for (int j = 0; j < way.node_refs.size(); j++) {

			long long id = way.node_refs[j];




			// Predicate to capture node with the same id as the reference
			auto pred = [id](const Node& node) {
				return node.id == id;
			};

			// Finding the node
			it = find_if(begin(nodes), end(nodes), pred);


			if (it == end(nodes)) {
				continue;
			}

			// Get index of element from iterator
			int index = std::distance(begin(nodes), it);


			//TooBad adicionado isto tenho de ver se está a correr bem ou nao

			//REMOVE cout << "Quantas tags tenho?" << tags.size() << endl;
			/* REMOVED, will be added to the full way
			if (nodes[index].tags.size() == 0 && tags.size() != 0) {

				//REMOVE cout << "Olha para mim a adicionar umas tags: " << endl;
				//REMOVEcout << "TAG: " << tags[0].first << ", " << tags[0].second << endl;

				nodes[index].tags = tags;

				//REMOVE cout << "Vamos ver se dei add ou não palhaço: " << nodes[index].tags[0].first << ", " << nodes[index].tags[0].second << endl;
				//REMOVE cout << "Vamos ver se dei add ou não palhaço: " << nodes[index].tags[1].first << ", " << nodes[index].tags[1].second << endl;

			}
			*/


			/*TESTING
			if (allIntersections.find(nodes[index].id) != allIntersections.end()) {
				cout << "What is up " << nodes[index].id << endl;
				interFound = 1;
				//interPoint = &nodes[index];
				interPoints.push_back(&nodes[index]);
			}
			*/


			//TODO should probably work with pointers here
			//add the current Node reference to the vector
			wayToAdd.push_back(&nodes[index]);


			//TooBad this is not the correct way to do this
			if (wayToAdd.size() > 1) {


				mapIt = allWays.find(id);

				/*
				cout << "HERE" << endl;
				cout << "WAY ADD" << endl;
				for (auto const& wat : wayToAdd) {
					cout << wat->id << endl;
				}
				cout << "end" << endl;
				*/


				// If the current node reference is in the allWays map
				if (mapIt != allWays.end()) {
					long long first = wayToAdd[0]->id;
					double tD = 0;
					vector<double> distSeg;
					vector<vector<double>> distns = calcDistances(wayToAdd, &tD, &distSeg);
					allWays[first].distanceTables.push_back(distns);
					allWays[first].tvalue = tvals;
					allWays[first].choices.push_back(wayToAdd);
					allWays[first].totalDistance.push_back(tD);
					allWays[first].distanceSegments.push_back(distSeg);
					allWays[first].tags = tags;


					// Structure to draw only MEW
					waysToDraw[first].draw_choices.push_back(wayToAdd);
					waysToDraw[first].tags = tags;

					

					/* TESTING
					if (interFound) {
						cout << "WAY TO ADD" << endl;
						for (auto const& wat : wayToAdd) {

							cout << wat->id << endl;
						}


						
						cout << "INTER POINTS" << endl;
						
						for(int i=0; i<interPoints.size(); i++){
							cout << "interPoint " << i << " " << interPoints[i]->id << endl;
							allIntersections[interPoints[i]->id].intersectionPoint = interPoints[i];
							allIntersections[interPoints[i]->id].connectedRoads.push_back(wayToAdd);

						}

						
						cout << "-------------------------" << endl;
						

						//allIntersections[interPoint->id].intersectionPoint = interPoint;
						//allIntersections[interPoint->id].connectedRoads.push_back(wayToAdd);
					
					}
					*/
					waysToCheck.push_back(wayToAdd);

					
					// If the current way is a two way street add the reverse to the correct map position
					if (way.type == 2) {
						reverse(wayToAdd.begin(), wayToAdd.end());
						long long last = wayToAdd[0]->id;
						double tD2 = 0;
						vector<double> distSeg2;

						// Reversed the calculations for the opposite lane segment distances
						vector<vector<double>> distns2 = calcDistances(wayToAdd, &tD2, &distSeg2);
						allWays[last].distanceTables.push_back(distns2);
						allWays[last].tvalue = tvals;
						allWays[last].choices.push_back(wayToAdd);
						allWays[last].totalDistance.push_back(tD2);
						allWays[last].distanceSegments.push_back(distSeg2);
						allWays[last].tags = tags;

						/*
						* TooBad REMOVED THIS PART BEACAUSE I DON?T NEED TO HAVE THE ROAD REVERSED FOR DRAWING
						if (interFound) {
							allIntersections[interPoint->id].intersectionPoint = interPoint;
							allIntersections[interPoint->id].connectedRoads.push_back(wayToAdd);
						}
						*/
					}

					/*
					cout << "WAY ADD" << endl;
					for (auto const& wat : wayToAdd) {
						cout << wat->id << endl;
					}
					cout << "end" << endl;
					*/



					wayToAdd.clear();



					wayToAdd.push_back(&nodes[index]);
				}
			}

		}

		// If wayToAdd wasn't cleared and it has more than 1 Node it is pushed to the correct map position.
		if (wayToAdd.size() > 1) {

			double tD = 0;
			vector<double> distSeg;
			long long id = wayToAdd[0]->id;
			vector<vector<double>> distns = calcDistances(wayToAdd, &tD, &distSeg);
			allWays[id].distanceTables.push_back(distns);
			allWays[id].tvalue = tvals;
			allWays[id].choices.push_back(wayToAdd);
			allWays[id].totalDistance.push_back(tD);
			allWays[id].distanceSegments.push_back(distSeg);
			allWays[id].tags = tags;

			/* TESTING
			if (interFound) {

				cout << "WAY TO ADD LOWER LOOP" << endl;
				for (auto const& wat : wayToAdd) {

					cout << wat->id << endl;
				}



				cout << "INTER POINTS LOWER LOOP" << endl;

				for (int i = 0; i < interPoints.size(); i++) {
					cout << "interPoint " << i << " " << interPoints[i]->id << endl;
					allIntersections[interPoints[i]->id].intersectionPoint = interPoints[i];
					allIntersections[interPoints[i]->id].connectedRoads.push_back(wayToAdd);

				}


				cout << "-------------------------" << endl;
				
				//allIntersections[interPoint->id].intersectionPoint = interPoint;
				//allIntersections[interPoint->id].connectedRoads.push_back(wayToAdd);
				
			}
			*/

			// Structure to draw only MEW
			waysToDraw[id].draw_choices.push_back(wayToAdd);
			waysToDraw[id].tags = tags;
			
			waysToCheck.push_back(wayToAdd);

			// If the current way is a two way street add the reverse to the correct map position
			if (way.type == 2) {

				reverse(wayToAdd.begin(), wayToAdd.end());
				double tD2 = 0;
				vector<double> distSeg2;
				vector<vector<double>> distns2 = calcDistances(wayToAdd, &tD2, &distSeg2);
				long long id2 = wayToAdd[0]->id;
				allWays[id2].distanceTables.push_back(distns2);
				allWays[id2].tvalue = tvals;
				allWays[id2].choices.push_back(wayToAdd);
				allWays[id2].totalDistance.push_back(tD2);
				allWays[id2].distanceSegments.push_back(distSeg2);
				allWays[id2].tags = tags;

				/*
				* TooBad REMOVED THIS PART BEACAUSE I DON?T NEED TO HAVE THE ROAD REVERSED FOR DRAWING
				if (interFound) {
					allIntersections[interPoint->id].intersectionPoint = interPoint;
					allIntersections[interPoint->id].connectedRoads.push_back(wayToAdd);
				}
				*/

			}

			/*
			cout << "WAY ADD LOWER LOOP" << endl;
			for (auto const& wat : wayToAdd) {
				cout << wat->id << endl;
			}
			cout << "end LOWER LOOP" << endl;
			*/

		}
		
	}

	addConnectedRoads(waysToCheck);
}

void Parser::addConnectedRoads(vector<vector<Node*>> waysToCheck) {

	for (auto const& way : waysToCheck) {
		/*
		cout << "WAY ADD add function" << endl;
		for (auto const& wat : way) {
			cout << wat->id << endl;
		}
		*/
		//cout << "end add function" << endl;
	
		Node* first = way[0];
		Node* last = way[way.size() - 1];

		if (allIntersections.find(first->id) != allIntersections.end()) {
			//cout << "What is up intersection point " << first->id << endl;

			allIntersections[first->id].intersectionPoint = first;
			allIntersections[first->id].connectedRoads.push_back(way);
		}
		if (allIntersections.find(last->id) != allIntersections.end()) {
			//cout << " What is up intersection point (last)" << last->id << endl;

			allIntersections[last->id].intersectionPoint = last;
			allIntersections[last->id].connectedRoads.push_back(way);

		}
	
	}


}

void Parser::createJunctions() {

	// Iterator to store the position of element found
	vector<Node>::iterator it;
	map<long long, WayData>::iterator it2;
	int a = 0;



	for (int y = 0; y < junctions.size(); y++) {

		Way junct = junctions[y];

		long long juncID = junct.way_id;
		allJuncIDS.push_back(juncID);

		vector<Node*> wayToAdd;

		vector<long long> exit;

		vector<long long> oneway;

		vector<long long> entranceJunc;

		long long startId = junct.node_refs[0];

		for (int j = 0; j < junct.node_refs.size(); j++) {

			long long id = junct.node_refs[j];

			// Predicate to capture node with the same id as the reference
			auto pred = [id](const Node& node) {
				return node.id == id;
			};

			// Finding the node
			it = find_if(begin(nodes), end(nodes), pred);


			if (it == end(nodes)) {
				continue;
			}

			// Get index of element from iterator
			int index = std::distance(begin(nodes), it);

			nodes[index].isJunc = 1;

			wayToAdd.push_back(&nodes[index]);


			it2 = allWays.find(id);

			if (it2 == end(allWays)) {
				continue;
			}

			// TooBad So what happens here is that I needed a way to add ids to a vector so I could push it later to the allJunctions map
			// but unfortunately if I pushed one-ways to the exit vector they would be considered an exit from the junction 
			// the solution (though not great) was to create another vector with only one-ways

			// TooBad I really don't think this is working but i'm not sure and I don't care enough

			entranceJunc.push_back(id);


			if (allWays[id].choices.size() != 0) {

				if (find(exit.begin(), exit.end(), id) == exit.end()) {

					exit.push_back(id);
				}
			}
			else {
				if (find(oneway.begin(), oneway.end(), id) == oneway.end()) {
					oneway.push_back(id);
				}
			}


		}

		// TooBad this is new
		vector<pair<string, string>> tags = wayTags[juncID];

		Junction junc;
		junc.fullWay = wayToAdd;
		junc.exits = exit;
		junc.tvalue = tvals;
		// TODO REMOVE This is just to give the junctions an id. It is not needed at the moment 
		junc.junc_id = a;
		a++;

		junc.tags = tags;

		juncsToDraw.push_back(junc);



		// Add all the possible exits to the allJunctions map with the Junction structure created before
		for (int i = 0; i < exit.size(); i++) {
			//cout << "COMO TU TA? " << exit[i] << endl;
			Junction j = orderVectorByNode(exit[i], junc);
			Junction complete_junc = calcDistForJunction(exit[i], j);
			allJunctions.emplace(exit[i], complete_junc);
		}



		//Too Bad this is not a good way to do this maybe
		// Add all the one-ways to the allJuncions map with the Junction structure created before (needed because of the path algorithm) 
		for (int i = 0; i < oneway.size(); i++) {
			/*	cout << "TA TUDO MANO? " << oneway[i] << endl;
				for (int i = 0; i < junc.fullWay.size(); i++) {
					cout << "Yoo " << junc.fullWay[i]->id << endl;
				}
				for (int s = 0; s < junc.exits.size(); s++) {
					cout << "sssss" << junc.exits[s] << endl;
				}*/
			Junction j = orderVectorByNode(oneway[i], junc);
			Junction complete_junc = calcDistForJunction(oneway[i], j);
			allJunctions.emplace(oneway[i], complete_junc);
		}


	}



}

// Order the vector by a specific node. TODO Verify
Parser::Junction Parser::orderVectorByNode(long long startNode, Junction junc) {
	vector<Parser::Node*> newVec;
	vector<Parser::Node*> currVec = junc.fullWay;
	int flag = 0;
	int loopBreak = 0;
	Junction j = junc;


	long long currNode = currVec[0]->id;

	if (startNode == currNode) {
		cout << "Already have correct vector - orderVectorByNode" << endl;
		flag = 1;
	}
	else {


		vector<Parser::Node*>::iterator it;

		//// Predicate to capture node with the same id as the reference
		auto pred = [startNode](const Parser::Node* node) {
			return node->id == startNode;
		};


		//// Finding the node
		it = find_if(begin(currVec), end(currVec), pred);


		if (it == end(currVec)) {
			cout << "EXIT NOT FOUND - orderVectorByNode" << endl;
		}

		int index = std::distance(begin(currVec), it);

		while (newVec.size() != currVec.size()) {

			if (index < currVec.size() - 1) {

				newVec.push_back(currVec[index]);

				currNode = currVec[index]->id;

				index++;
			}
			else {
				index = 0;
			}
		}
	}

	if (flag == 1) {
		return j;
	}
	else {
		j.fullWay = newVec;
		return j;
	}

}


Parser::Junction Parser::calcDistForJunction(long long startNode, Junction junc) {
	vector<vector<double>> allDistTables;
	vector<double> distSegments;
	double totalDistance = 0;
	vector<long long> exits = junc.exits;
	vector<Parser::Node*> way = junc.fullWay;


	for (int i = 0; i < exits.size(); i++) {

		// Calculate total distance
		// if exits[i] is equal to startNode it means the car will be doing the full roundabout.	
		if (exits[i] == startNode) {
			for (int j = 0; j < way.size() - 1; j++) {

				vector<double> distTable;

				vec3 node1 = vec3(way[j]->lon, 0, way[j]->lat);
				vec3 node2 = vec3(way[j + 1]->lon, 0, way[j + 1]->lat);

				double segmentDist = sqrt(pow(node2.x - node1.x, 2) + pow(node2.z - node1.z, 2));

				for (double j = 0; j <= 1.01; j += 0.01) {
					distTable.push_back(segmentDist * j);
				}

				allDistTables.push_back(distTable);
				distSegments.push_back(segmentDist);

				totalDistance += segmentDist;

			}

		}
		// Calculate only the needed distance
		else {
			for (int j = 0; j < way.size() - 1; j++) {

				if (way[j]->id == exits[i]) {
					break;
				}
				else {


					vector<double> distTable;

					vec3 node1 = vec3(way[j]->lon, 0, way[j]->lat);
					vec3 node2 = vec3(way[j + 1]->lon, 0, way[j + 1]->lat);

					double segmentDist = sqrt(pow(node2.x - node1.x, 2) + pow(node2.z - node1.z, 2));

					for (double j = 0; j <= 1.01; j += 0.01) {
						distTable.push_back(segmentDist * j);
					}

					allDistTables.push_back(distTable);
					distSegments.push_back(segmentDist);

					totalDistance += segmentDist;
				}
			}
		}

		junc.distanceTables.push_back(allDistTables);
		junc.distanceSegments.push_back(distSegments);
	}

	return junc;
}




void Parser::discoverEntranceAndExit() {
	for (auto const& way : ways) {

		// One way
		if (way.type == 1) {

			WayData w = allWays[way.node_refs[0]];
			vector<vector<Node*>> wayVec = w.choices;


			// If first node only has one vector in the allWays map and is not a junction node, it means it is an entrance
			if (wayVec.size() == 1) {
				Node* firstNode = wayVec[0][0];

				if (firstNode->isJunc != 1) {
					mapEntrances.push_back(way.node_refs[0]);
				}
			}

			int cnt = allWays.count(way.node_refs[way.node_refs.size() - 1]);

			// If last node doesn't appear in the allWays map, it means it is an exit 
			if (cnt == 0) {
				mapExits.push_back(way.node_refs[way.node_refs.size() - 1]);
			}

		}

		// Two way
		if (way.type == 2) {

			WayData w = allWays[way.node_refs[0]];
			vector<vector<Node*>> wayVec = w.choices;

			// If the first node has only one way vector and is not a junction node, it means it is an entrance and an exit
			if (wayVec.size() == 1) {
				Node* firstNode = wayVec[0][0];

				if (firstNode->isJunc != 1) {
					mapEntrances.push_back(way.node_refs[0]);
					mapExits.push_back(way.node_refs[0]);
				}
			}


		}
	}


	/*
	for (int i = 0; i < mapEntrances.size(); i++) {
		cout << "ENTRANCE HERE" << endl;
		cout << mapEntrances[i] << endl;
	}

	for (int i = 0; i < mapExits.size(); i++) {
		cout << "EXIT HERE" << endl;
		cout << mapExits[i] << endl;
	}
	*/


}


vector<Parser::Node> Parser::getNodes() {
	return nodes;
}

vector<Parser::Way> Parser::getWays() {
	return ways;
}

map<long long, Parser::Junction> Parser::getJunctions() {
	return allJunctions;
}

map<long long, Parser::WayData> Parser::getMap() {
	return allWays;
}

map<long long, Parser::DrawData> Parser::getMapToDraw() {
	return waysToDraw;
}


map<long long, Parser::Intersection>* Parser::getAllIntersections() {
	return &allIntersections;
}

vector<long long> Parser::getIntersections() {
	return intersections;
}

vector<Parser::Junction> Parser::getJuncsToDraw() {
	return juncsToDraw;
}

vector<long long> Parser::getEntrances() {
	return mapEntrances;
}

vector<long long> Parser::getExits() {
	return mapExits;
}

vector<long long> Parser::getWayIDS() {
	return allWayIDS;
}

vector<long long> Parser::getJuncIDS() {
	return allJuncIDS;
}