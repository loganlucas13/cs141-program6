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


using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

deque<vector<int>> GetEdgePairings(const string& path);

#endif