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

// Logan Lucas
// Program 6
// Spring 2023
// CS 141
// Professor Maratos

// entry point for the autograder/program
void run(const string& src_path, const string& dst_path) {
	AdjacencyList adjList;
	int numNodes = 0;
	int numEdges = 0;
	int maxDegree = 0;

	adjList.LoadAdjList(src_path);
	
	ofstream fstr{dst_path};
	for (int i = 0; i < adjList.list.size(); i++) {
		if (adjList.list.at(i).size != 0) {
			fstr << i << ": ";
			fstr << adjList.list.at(i).DisplayList();
		}
	}
	fstr.close();

	for (int i = 0; i < adjList.list.size(); i++) {
		// counts number of nodes
		if (adjList.list.at(i).size != 0) 
			numNodes++;
		// counts number of edges
		if (i == 0)
			maxDegree = adjList.list.at(i).size;
		else 
			maxDegree = max(maxDegree, adjList.list.at(i).size);
		numEdges += adjList.list.at(i).size;
	}
	numEdges /= 2;
	
	cout << "Number of nodes: " << numNodes << "\n";
	cout << "Number of edges: " << numEdges << "\n";
	cout << "Maximum degree: " << maxDegree << "\n";
}


int main() {
  	const string inFilename = "other/roadNet-CA.txt";
	const string outFilename = "other/output.txt";

	run(inFilename, outFilename);
	return 0;
}