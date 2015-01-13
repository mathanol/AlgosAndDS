#include "UF.h"


UF::UF( int N ) : _count(N), _capacity(N) {  
	map = new int[N];
	size = new int[N];
	for ( int i = 0; i < N; i++ ) {
		//Each Component is connected to iteself by default
		map[i] = i;
		size[i] = 1; 
	}
}



// A root node is node s.t map[node] = node
int UF::find( int node ) { 

	int parent = map[node];
	while ( parent != map[parent] ) parent = map[parent];
	return parent;
}


bool UF::connected( int node_a, int node_b ) {

	return find( node_a ) == find( node_b ); 
}

void UF::Union( int node_a, int node_b ) {

	int root_a = find( node_a );
	int root_b = find( node_b ); 

	//They are already connected
	if ( root_a == root_b )
		return; 


	//Connect to the smaller tree
	int size_root_a = size[root_a];
	int size_root_b = size[root_b];

	if ( size_root_a < size_root_b ) {
		map[root_a] = root_b;
		size[ root_b ] += 1;

	} else {
		map[root_b] = root_a;
		size[ root_a ] += 1;
	}

	_count -= 1;

}

void UF::debug() {

	for( int i = 0; i < _capacity; ++i )
		std::cout << i << " " ;
	std::cout << std::endl;
	std::cout << "MAP" <<  std::endl;
	for( int i = 0; i < _capacity; ++i )
		std::cout << map[i] << " " ;
	std::cout << std::endl;


	std::cout << "SIZE" <<  std::endl;
	for( int i = 0; i < _capacity; ++i )
		std::cout << size[i] << " " ;
	std::cout << std::endl;

}


int main(void) {

	UF *uf = new UF(10); 
	uf->Union(4,3);
	uf->Union(3,8);
	uf->Union(6,5);
	uf->Union(9,4);
	uf->Union(2,1);
	uf->Union(5,0);
	uf->Union(7,2);
	uf->Union(6,1);
	uf->debug();
	return 0;
}
