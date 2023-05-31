#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Node.h"
#include "List.h"
#include "AdjacencyList.h"

using namespace std;

// reads from file and adds new nodes to indices of adjacency list
void AdjacencyList::LoadAdjList(const string& path) {
	List emptyList;
	int num1;
	int num2;
	
	ifstream src{path};
	
	if (!src.is_open()) {
		cout << "File not found\n";
		exit(0);
	}

	// every line in the .txt file
	for (string line; getline(src, line);) {
		stringstream ss(line);
		ss >> num1 >> num2;

		// allocates space in the adjacency list vector
		while (list.size() <= max(num1, num2)) {
			list.push_back(emptyList);
		}

		// inserts new nodes
		list.at(num1).InsertInOrder(num2);
		list.at(num2).InsertInOrder(num1);
	}
	
	for (int i = 0; i < list.size(); i++) {
		list.at(i).Sort();
		list.at(i).RemoveDupes();
	}
}