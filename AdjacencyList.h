#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Node.h"
#include "List.h"

using namespace std;

#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

class AdjacencyList {
	public:
		vector<List> list;

		// sets up the adjacency list
		void LoadAdjList(const string& path);
};

#endif