#include "RBTree.h" 

int main(void) {

	RBTree *t = new RBTree(); 
	t->put(20); 
	t->put(5); 
	t->put(3); 
	t->put(30); 
	t->put(11); 
	t->inorder(t->root()); 
	return 0;
}

	
