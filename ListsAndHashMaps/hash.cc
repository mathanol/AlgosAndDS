#include "HashMapSepChain.h"

int main(void) {

	HashMapSepChain<int,int> *l = new HashMapSepChain<int, int>(); 	
	for(int i = 0; i < 100; i++) {
		l->put(rand(), rand()); 
		cout << i << endl ;
	}
	return 0;
}

