#ifndef _HASH_MAP_SEP_CHAIN 
#define _HASH_MAP_SEP_CHAIN

#include "List.h"
#include <functional>
#include <vector>


#define INIT_CAPACITY 4

template <class Key, class Data>
class HashMapSepChain { 

	private:
		int M;
		int N;
		ListST<Key, Data> *_map; 
		size_t hash(Key key); 
		void resize(int new_size);
	public:

		HashMapSepChain(); 
		void put(Key key, Data data); 
		Data get(Key key); 
}; 


template <class Key, class Data>
HashMapSepChain<Key, Data>::HashMapSepChain() { 
	M = INIT_CAPACITY; 
	_map = new ListST<Key, Data>[M]; 
	N = 0; 
} 

template <class Key, class Data>
size_t HashMapSepChain<Key, Data>::hash(Key key) {

	std::hash<Key> key_hash; 
	return (key_hash(key) % M); 
}

template <class Key, class Data>
void HashMapSepChain<Key, Data>::put(Key key, Data data) { 

	if ( N >= 10 * M ) resize(2 * M); 

	size_t h = hash(key); 
	if (!_map[h].contains(key)) N++; 
	_map[h].put(key, data);

}
template <class Key, class Data>
void HashMapSepChain<Key, Data>::resize(int new_size) { 
	cout << "Resize" << endl; 
	ListST<Key, Data> *new_map = new ListST<Key, Data>[new_size]; 
	int old_M = M; 
	M = new_size; 
	
	for(int j = 0; j < old_M; j++) {
		std::vector<Key> keys = _map[j].keys(); 
		typename std::vector<Key>::iterator i; 
		for(i = keys.begin(); i != keys.end(); ++i) {
			size_t h = hash(*i); 
			new_map[h].put(*i, _map[j].get(*i)); 
		} 
	}

	delete[] _map; 
	_map = new_map; 
}

	

template <class Key, class Data>
Data HashMapSepChain<Key, Data>::get(Key key) {

	size_t h = hash(key); 
	return _map[h].get(key); 
}

	


#endif 
