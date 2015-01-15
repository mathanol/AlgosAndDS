#ifndef _LP_HASH_H
#define _LP_HASH_H 
#include <functional>
#include <iostream>
#define INIT_SIZE 4


template <class Key, class Data>
class LPHash {

	private:
		Key *keys; 
		Data *data; 
		int M; 
		int N;
		void resize(int new_size); 
		size_t hash(Key key); 
	
	public:
		Data get(Key key); 
		void put(Key key, Data data); 
		LPHash(); 
		

}; 

template <class Key, class Data>
LPHash<Key, Data>::LPHash() { 

	M = INIT_SIZE; 
	N = 0; 
	keys = new Key[M];
	data = new Data[M];
	
	for(int i = 0; i < M; i++)
		keys[i] = static_cast<Key>(NULL); 

}

template <class Key, class Data>
void LPHash<Key, Data>::resize(int new_size) {

	Key *new_keys = new Key[new_size]; 
	Data *new_data = new Data[new_size]; 
		
	for(int i = 0; i < new_size; i++)
		new_keys[i] = static_cast<Key>(NULL); 

	int old_M = M; 
	M = new_size; 	

	for(int i = 0; i < old_M; i++) {
		Key k = keys[i];
		if(!k)
			continue; 
		Data d = data[i]; 
		int j;
		for(j = hash(k); new_keys[j] != static_cast<Key>(NULL); j = (j + 1) % M)
			continue;
		new_keys[j] = k; 
		new_data[j] = d; 
	}
	
	delete[] keys; 
	delete[] data; 
	keys = new_keys; 
	data = new_data; 
}
	

template <class Key, class Data>
size_t LPHash<Key, Data>::hash(Key key) {

	std::hash<Key> h; 
	return (h(key) % M);

}

template <class Key, class Data>
void LPHash<Key, Data>::put(Key key, Data dat) {

	if ( N >= M / 2) 
		resize(2 * M); 
	int i;
	for(i = hash(key); keys[i] != static_cast<Key>(NULL); i = (i + 1) % M) {
		if (keys[i] == key)
			data[i] = dat; 
	}

	keys[i] = key; 
	data[i] = dat; 
	N++; 
}

template <class Key, class Data>
Data LPHash<Key, Data>::get(Key key) { 

	for( int i = hash(key); keys[i] != static_cast<Key>(NULL); i = ( i + 1 ) % M) 
		if (keys[i] == key)
			return data[i]; 
	
	return static_cast<Data>(NULL); 
}

#endif
	

		
