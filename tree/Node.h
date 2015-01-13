#ifndef _NODE_H
#define _NODE_H

#include <iostream>
#include <algorithm>

#define RED true
#define BLACK false

//By default null links are black 
//color = true means a Red Node
//color = false means a black node

class Node {

	public:
		Node(int val, int N);
		Node(int val, int N, bool color); 
		int data;
		bool color;
		Node *left;
		Node *right;
		int N; 
};

Node::Node(int val, int N) : data(val), color(BLACK) {

	left = NULL; 
	right = NULL; 
	this->N = N;

}

Node::Node(int val, int N, bool color) { 
	this->color = color; 
	this->N = N; 
	this->data = val; 
	left = NULL; 	
	right = NULL;
}

#endif
