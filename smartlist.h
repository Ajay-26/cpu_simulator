#pragma once
#include <unordered_map>

<typename T>
struct node{
	T value;
	node* next;
	node* prev;
};

<typename T>
struct SmartList{
	node<T>* head;
	node<T>* tail;

	std::unordered_map<T,node<T>*> locations;
	int num_elements;
};