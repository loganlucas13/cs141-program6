#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
	public:
		int id;
		Node* next;

		// constructor
		Node(int id);
		Node();
};

#endif