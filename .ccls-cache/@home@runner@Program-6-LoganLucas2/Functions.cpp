#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Node.h"
#include "List.h"
#include "AdjacencyList.h"
#include "Functions.h"

using namespace std;

// reads file and creates a 2d vector<int>
// returns all possible edge pairs
deque<vector<int>> GetEdgePairings(const string& path) {
	deque<vector<int>> allEdgePairs;
	vector<int> edgePair;
	vector<int> inverseEdgePair;

	int num1;
	int num2;
	
	ifstream src{path};
	
	if (!src.is_open()) {
		cout << "File not found\n";
		exit(0);
	}

	for (string line; getline(src, line);) {
		stringstream ss(line);

		ss >> num1 >> num2;

		edgePair.clear();
		inverseEdgePair.clear();

		// makes an edgePair in form (small, large)
		edgePair.push_back(min(num1, num2));
		edgePair.push_back(max(num1, num2));

		inverseEdgePair.push_back(max(num1, num2));
		inverseEdgePair.push_back(min(num1, num2));
		
		// gets rid of duplicate nodes
		if (find(allEdgePairs.begin(), allEdgePairs.end(), edgePair) == allEdgePairs.end()) {
			allEdgePairs.push_back(edgePair);
			allEdgePairs.push_back(inverseEdgePair);
		}
	}
	// sorts the 2d vector based on:
	// 1. lesser first value
	// 2. lesser second value
	sort(allEdgePairs.begin(), allEdgePairs.end(), less<vector<int>>());
	return allEdgePairs;
}