#ifndef _NODE_H
#define _NODE_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node {

        public:
                Node(int val);
                int value;
                vector<Node*> *adj;

};

Node::Node(int val) : value(val) {

        adj = new vector<Node*>();
}

#endif
