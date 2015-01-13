#include "Node.h"

using namespace std; 

class RBTree {


	public:
		RBTree();
		void put(int data); 
		void inorder(Node *n); 
		Node* root(); 
		int size(Node *n); 
		int rank(int data); 
		void delMin(); 
		void del(int data); 
		int floor(int data); 
		int ceil(int data); 

	private:
		Node* _put(Node *n, int data); 
		int _rank(Node *n, int data); 
		Node *_root; 
		Node *del_min(Node *n); 
		Node *_del(Node *n, int data); 
		Node *_min(Node *n); 
		Node *_floor(Node *n, int data); 
		Node *_ceil(Node *n, int data); 
		bool isRed(Node *n); 
		Node *rotateLeft(Node *n); 
		Node *rotateRight(Node *n); 
		void flipColors(Node *n);
};

Node*  RBTree::_min(Node *n) { 
	if(n->left == NULL)
		return n; 
	else
		return _min(n->left); 
}

bool RBTree::isRed(Node *n) { 

	if (n == NULL) return false; 
	return (n->color == RED); 
}

/*
	n
      l    x
	b    g

      x
  n      g
l   b

n->right = x->left;
x->left = n; 
*/

Node* RBTree::rotateLeft(Node *n) { 
	//n != NULL && isRed(n->right); 
	Node *x = n->right;
	n->right = x->left; 
	x->left = n; 
	x->color = n->color; 
	x->N = n->N; 
	n->color = RED; 
	n->N = 1 + size(n->left) + size(n->right); 
	return x; 
}
/*
    n
  x   g
l  b

n->left = x->right; 
x->right = n;  
 
   x 
 l   n   
    b  g 

*/
Node* RBTree::rotateRight(Node *n) {
	//n != NULL && isRed(n->left) 
	Node *x = n->left;
	n->left = x->right; 
	x->right = n;
	x->color = n->color; 
	n->color = RED; 
	x->N = n->N; 
	n->N = 1 + size(n->left) + size(n->right); 
	return x; 
}

void RBTree::flipColors(Node *n) {
	n->color = !n->color; 
	n->left->color = !n->left->color; 
	n->right->color = !n->right->color;
}

void RBTree::del(int data) {
	_root = _del(_root, data); 
}

Node *RBTree::_del(Node *n, int data) { 
	
	if(n == NULL) return NULL; 
	
	if(data < n->data) n->left = _del(n->left, data); 
	else if(data > n->data) n->right = _del(n->right, data); 
	else {
		//This the key to be deleted
		Node *x;
		if (n->right == NULL) { 
			x = n->left; 
			delete n; 
			return x; 
		}
		if (n->left == NULL) {
			x = n->right; 
			delete n;
			return x;
		}
		//Neither are null
		//Store current node in a temporary variable
		//replace with the inorder successor of the node n
		x = _min(n->right); 
		n->data = x->data; 
		n->right = del_min(n->right); 
	}
	
	n->N = 1 + size(n->right) + size(n->left); 
	return n; 
}

void RBTree::delMin() {

	_root = del_min(_root); 
}


Node *RBTree::del_min(Node *n) {

	if(n->left == NULL) {
		Node *i = n->right; 
		delete n;
		return i; 
	}
	else {
		n->left = del_min(n->left);
		n->N = size(n->left) + size(n->right) + 1;
		return n;
	}
}



int RBTree::rank(int data) {
	
	return _rank(_root, data); 
}

int RBTree::floor(int data) { 

	Node *x =  _floor(_root, data); 
	if(x)
		return x->data; 
	else
		return 0; 
} 
int RBTree::ceil(int data) { 

	Node *x =  _ceil(_root, data); 
	if(x)
		return x->data; 
	else
		return 0; 
}

Node* RBTree::_floor(Node *n, int data) { 

	if (n == NULL) return NULL; 
	
	if (data < n->data) return _floor(n->left, data); 
	if (data == n->data) return n; 
	
	Node *x = _floor(n->right, data); 
	if(x != NULL)
		return x;
	else 
		return n; 
}

Node* RBTree::_ceil(Node *n, int data) {
		
	if (n == NULL) return NULL; 
	
	if (data > n->data) return _ceil(n->right, data); 
	if (data == n->data) return n; 

	//Now we check if there is a ceil in the left subtree and if not we return the 
	//the top of the left subtree 
	Node *x = _ceil(n->left, data); 

	if(x != NULL)
		return x;
	else 
		return n; 
}


int RBTree::_rank(Node *n, int data) {

	if (n == NULL)
		return 0; 
	
	if (data < n->data) 
		return _rank(n->left, data); 
	else if (data > n->data)
		return size(n->left) + 1 + _rank(n->right, data); 
	else
		return size(n->left); 
}

int RBTree::size(Node *n) {
	if (n == NULL) 
		return 0; 
	else {
		return n->N; 
	}
}

RBTree::RBTree() {
	_root = NULL; 
}

Node* RBTree::root() {
	return _root; 
}

Node* RBTree::_put(Node *n, int data) {

	if(n == NULL) { 
		Node *n = new Node(data, 1, RED); 
		return n; 
	}
	
	if (data < n->data) 
		n->left =  _put(n->left, data); 
	else if (data > n->data) 
		n->right = _put(n->right, data); 

	//Update the node (if using key value semantics)
	if ( isRed(n->right) && !isRed(n->left) ) n = rotateLeft(n); 
	if ( isRed(n->left) && isRed(n->left->left) ) n = rotateRight(n); 
	if ( isRed(n->left) && isRed(n->right) ) flipColors(n); 

	n->N = 1 + size(n->right) + size(n->left); 
	return n; 
}

void RBTree::inorder(Node *n) { 

	if (n == NULL) 
		return; 
	
	inorder(n->left); 
	cout << n->data << endl; 
	inorder(n->right); 

}

void RBTree::put(int data) {
	_root = _put(_root, data);
	_root->color = BLACK; 
}

		
