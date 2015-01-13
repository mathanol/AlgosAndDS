#ifndef _UF_H 
#define _UF_H 

#include <iostream>

class UF {


	public:
		UF( int N );
		int find( int node ); 
		void Union( int node_a, int node_b ); 
		int count(); 
		bool connected( int node_a, int node_b ); 			
		void debug();

	private:
		int _count; 
		int _capacity; 
		int *map;
		int *size; 

};

#endif


