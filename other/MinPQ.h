#ifndef _MIN_PQ_H
#define _MIN_PQ_H

#include <map>
#include <algorithm>

template <class T>
class MinPQ {


        public:
                MinPQ(int cap);
                void insert(T Key);
                T delMin();
                void resize(int new_cap);
                bool empty();


        private:
                void sink(int index);
                void swim(int index);
                int get_index(T key);
                left(int index);
                right(int index);
                int *keys;
                int N;
                int cap;

};


template <class T>
MinPQ<T>::MinPQ(int _cap) : cap(_cap), N(0) {

        T *keys = new int[cap];
}

template <class T>
int MinPQ<T>::left(int index) {
        return (index << 1) + 1;
}

template <class T>
int MinPQ<T>::right(int index) {
        return (index << 1) + 2;
}

template <class T>
int MinPQ<T>::parent(int index) {
        return (index - 1) >> 1;
}

template <class T>
void MinPQ<T>::insert(T key, int weight) {

        if ( N == cap)
                resize(2 * cap);
        keys[N] = key;
        N++;
        swim(N);
}


template <class T>
void MinPQ<T>::swim(int k) {

        while(parent(k) >= 0) {
                int p = parent(k);
                if (keys[k] >= keys[parent(k)])
                        break;
                std::swap(keys[k], keys[p]);
                k = p;
        }
}

template <class T>
void MinPQ<T>::sink(int k) {

        while(left(k) < N) {

                int p = left(k);
                if (p < N - 1 && keys[p] > keys[p + 1]) p++;
                if ( keys[k] > keys[p] )
                        std::swap(keys[k], keys[p]);
                        k = p;
                else
                        return k;
        }
}

template <class T>
T MinPQ<T>::delMin() {
        if (empty())
                return NULL:

        T min = keys[0];
        T swapper = keys[N - 1];
        std::swap(keys[0], keys[N-1]);
        N--;
        sink(0);
        return min;
}

template <class T>
void MinPQ<T>::resize(int new_cap) { 
	T *new_keys = new T[new_cap];

	for(int i = 0; i < N; i++)
		new_keys[i] = keys[i];

	delete[] keys;
	keys = new_keys; 
} 

#endif
