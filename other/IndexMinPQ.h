#ifndef _INDEX_MIN_PQ
#define _INDEX_MIN_PQ

#include <iostream>
using namespace std;

template <class T>
class IndexMinPQ;

template <class T>
std::ostream& operator<<(std::ostream& out, const IndexMinPQ<T>&);

template <class T>
class IndexMinPQ {

	
	private:
		int NMAX; 
		int N; 
		void sink(int k);
		void swim(int k); 
		void exchg(int j, int k);
		int left(int); 	
		int right(int); 
		int parent(int);  
		
		//Mapping of the location of the index in the 
		int *iton;
		//Mapping of key in PQ array at N to index i
		int *ntoi;
		T *keys; 

	public:
		IndexMinPQ(int nmax); 
		friend std::ostream& operator<< <> (std::ostream&, const IndexMinPQ<T>&);
		bool contains(int i);
		T keyOf(int i);
		int delMin(); 
		void decreaseKey(int i, T key);
		void insert(int index, T key); 
		bool empty(); 
};

template <class T>
IndexMinPQ<T>::IndexMinPQ(int nmax) { 

	NMAX = nmax; 
	iton = new int[NMAX]; 
	ntoi = new int[NMAX];
	for(int i = 0; i < NMAX; i++)
		iton[i] = -1; 

	keys = new T[NMAX]; 
	N = 0; 
}

template <class T>
bool IndexMinPQ<T>::contains(int i) {

	if(i < 0 || i > NMAX)
		return false; 
	return iton[i] != -1;
}

template <class T>
void IndexMinPQ<T>::insert(int i, T key) {

	if((N + 1) > NMAX) {
		cout << "PQ full!" << std::endl; 
		return; 
	}
		
	iton[i] = N; 
	ntoi[N] = i;
	keys[N] = key; 
	N++;
	swim(N - 1); 
}
template <class T>
bool IndexMinPQ<T>::empty() {
	return N == 0; 
}

template <class T>
int IndexMinPQ<T>::left(int k) {
	return (k << 1) + 1; 
}

template <class T>
int IndexMinPQ<T>::right(int k) {
	return (k << 1) + 2; 
}

template <class T>
int IndexMinPQ<T>::parent(int k) {
	return (k - 1) >> 1; 
}

template <class T>
void IndexMinPQ<T>::exchg(int j, int k) {

 
	std::swap(keys[j], keys[k]); 
	std::cout << "keys[" << j << "] = " << keys[j] << endl; 
	std::cout << "keys[" << k << "] = " << keys[k] << endl; 
	std::swap(iton[ntoi[j]], iton[ntoi[k]]); 
	std::cout << "iton[" << ntoi[j] << "] = " << iton[ntoi[j]] << endl; 
	std::cout << "iton[" << ntoi[k] << "] = " << iton[ntoi[k]] << endl; 
	std::swap(ntoi[j], ntoi[k]); 
	std::cout << "ntoi[" << j << "] = " << ntoi[j] << endl; 
	std::cout << "ntoi[" << k << "] = " << ntoi[k] << endl; 
	
}

template <class T>
void  IndexMinPQ<T>::swim(int k) {
	while(k) {
		int p = parent(k);
		cout << "P: " << p << endl; 
		if (keys[p] > keys[k]) {
			exchg(k, p); 
			k = p; 
		}
		else
			break; 
	}
}

template <class T>
void  IndexMinPQ<T>::decreaseKey(int i, T key) {

	int n = iton[i];
	cout << "n: " << n << endl;
	if (keys[n] <= key) {
		cout << "Error: key should be less" << std::endl; 
		return;
	}
	
	keys[n] = key; 
	swim(n); 
	
}
	
template <class T>
void  IndexMinPQ<T>::sink(int k) {

	while(left(k) < N) {
		int l = left(k); 
		if( l < N - 1 && keys[l+1] < keys[l] )l++; 
		if(keys[l] < keys[k]) {
			exchg(l, k); 
			k = l; 
		}
		else
			break; 
	}
}

template <class T>
int IndexMinPQ<T>::delMin() {

	if (N == 0) {
		cout << "Empty Queue, No deletion" << endl; 
		return -1; 
	}

	T min = keys[0]; 
	std::cout << "min: " << min << endl; 
	int min_index = ntoi[0]; 
	exchg(0, N - 1); 
	N--;
	iton[min_index] = -1; 
	sink(0);
	return min_index; 
}

template <class T>
std::ostream& operator<< ( std::ostream& out, const IndexMinPQ<T>& p) {

        for( int i = 0; i < p.N; i++ )
                out << p.keys[i] << " ";

        out << std::endl;
        return out;

}

#endif
