#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Node.h"

using namespace std;

#ifndef LIST_H
#define LIST_H

class List {
	private:
		Node* head;
		Node* tail;
	public:
		int size;
		// constructor 
		List();
		// void NewNode(int data);
		void InsertInOrder(int data);
		void Sort();
		void RemoveDupes();
		string DisplayList();
		Node* GetHead();
};

#endif