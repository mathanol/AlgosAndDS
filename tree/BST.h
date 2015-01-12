#include "Node.h"

using namespace std; 

class BST {


	public:
		BST();
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
};

Node*  BST::_min(Node *n) { 
	if(n->left == NULL)
		return n; 
	else
		return _min(n->left); 
}


void BST::del(int data) {
	_root = _del(_root, data); 
}

Node *BST::_del(Node *n, int data) { 
	
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

void BST::delMin() {

	_root = del_min(_root); 
}


Node *BST::del_min(Node *n) {

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



int BST::rank(int data) {
	
	return _rank(_root, data); 
}

int BST::floor(int data) { 

	Node *x =  _floor(_root, data); 
	if(x)
		return x->data; 
	else
		return 0; 
} 
int BST::ceil(int data) { 

	Node *x =  _ceil(_root, data); 
	if(x)
		return x->data; 
	else
		return 0; 
}

Node* BST::_floor(Node *n, int data) { 

	if (n == NULL) return NULL; 
	
	if (data < n->data) return _floor(n->left, data); 
	if (data == n->data) return n; 
	
	Node *x = _floor(n->right, data); 
	if(x != NULL)
		return x;
	else 
		return n; 
}

Node* BST::_ceil(Node *n, int data) {
		
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


int BST::_rank(Node *n, int data) {

	if (n == NULL)
		return 0; 
	
	if (data < n->data) 
		return _rank(n->left, data); 
	else if (data > n->data)
		return size(n->left) + 1 + _rank(n->right, data); 
	else
		return size(n->left); 
}

int BST::size(Node *n) {
	if (n == NULL) 
		return 0; 
	else {
		return n->N; 
	}
}

BST::BST() {
	_root = NULL; 
}

Node* BST::root() {
	return _root; 
}

Node* BST::_put(Node *n, int data) {

	if(n == NULL) { 
		Node *n = new Node(data, 1); 
		return n; 
	}
	
	if (data < n->data) 
		n->left =  _put(n->left, data); 
	else if (data > n->data) 
		n->right = _put(n->right, data); 
	
	n->N = 1 + size(n->right) + size(n->left); 
	return n; 
}

void BST::inorder(Node *n) { 

	if (n == NULL) 
		return; 
	
	inorder(n->left); 
	cout << n->data << endl; 
	inorder(n->right); 

}

void BST::put(int data) {
	_root = _put(_root, data); 
}

		
