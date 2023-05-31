#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Node.h"
#include "List.h"
#include "AdjacencyList.h"

using namespace std;

// constructor
Node::Node(int id) {
	this->id = id;
	this->next = nullptr;
}