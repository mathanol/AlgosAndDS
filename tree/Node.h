#ifndef _NODE_H
#define _NODE_H

#include <iostream>
#include <algorithm>



class Node {

	public:
		Node(int val, int N);
		int data;
		int color;
		Node *left;
		Node *right;
		int N; 
};

Node::Node(int val, int N) : data(val), color(0) {

	left = NULL; 
	right = NULL; 
	this->N = N;

}

#endif
