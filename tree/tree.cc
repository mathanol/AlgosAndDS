#include "BST.h" 

int main(void) {

	BST *t = new BST(); 
	t->put(20); 
	t->put(5); 
	t->put(3); 
	t->put(30); 
	t->put(11); 
	t->del(5);
	cout << t->ceil(12) << endl; 
	t->inorder(t->root()); 
	return 0;
}

	
