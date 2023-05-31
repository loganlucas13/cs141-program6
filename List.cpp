#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Node.h"
#include "List.h"

using namespace std;

// constructor
List::List() {
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

// returns head of the linked list
Node* List::GetHead() {
	return head;
}

// inserts the nodes in ascending order
void List::InsertInOrder(int data) {
	Node* toAdd = new Node(data);

	if (head == nullptr) {
		head = toAdd;
		tail = toAdd;
		size++;
		return;
	}
	
	if (toAdd == nullptr)
		return;
	Node* current = head;
	while (current->next) {
		if (current->next->id == toAdd->id) {
			delete toAdd;
			return;
		}
		if (current->next->id > toAdd->id) {
			break;
		}
		current = current->next;
	}
	toAdd->next = current->next;
	current->next = toAdd;
	size++;
}

// sorts the linked list in ascending order
// fixes edge case with first node in list
void List::Sort() {
	Node* current = head;
	Node* index = nullptr;
	int temp;

	if (head == nullptr)
		return;
		
	else {
		while (current != nullptr) {
			index = current->next;
			while (index != nullptr) {
				if (current->id > index->id) {
					temp = current->id;
					current->id = index->id;
					index->id = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

// removes all duplicates from the linked list
// fixes edge case with first node in list
void List::RemoveDupes() {

	if (head == nullptr) {
		return;
	}
	
	Node* current = head;
	Node* afterNext;
	
	while (current->next != nullptr) {
		if (current->id == current->next->id) {
			afterNext = current->next->next;
			delete current->next;
			current->next = afterNext;
			size--;
		}
		else {
			current = current->next;
		}
	}
}

// outputs all elements in the linked list
string List::DisplayList() {
	string output = "";
	Node* current = head;

	stringstream ss(output);

	for (int i = 0; i < size; i++) {
		ss << current->id;
		if (i + 1 != size)
			ss << " ";
		current = current->next;
	}
	ss << "\n";
	
	return ss.str();
}