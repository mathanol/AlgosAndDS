#include <iostream>
#include <algorithm>

template <class T, size_t N>
class MergeSort {

	public:
		static void sort( T (&arr) [N] );
	private:
		static void _sort(T (&arr) [N], int start, int end);
		static void merge(T (&arr) [N], int start, int mid, int end);
		static T aux[N];
};

template <class T, size_t N>
T MergeSort<T,N>::aux[N] = {0};

template <class T, size_t N>
void MergeSort<T,N>::sort( T (&arr) [N]) {
	
	_sort(arr, 0, N - 1);

}

template <class T, size_t N>
void MergeSort<T,N>::merge( T (&arr) [N], int start, int mid, int end) {

	int i = start;
	int j = mid + 1; 

	for (int k = start; k <= end; k++) 
		aux[k] = arr[k];
	
	for(int k = start; k <= end; k++) {

		if ( i > mid ) {
			 arr[k] = aux[j++];
		}
		else if ( j > end ) {
			arr[k] = aux[i++];
		}
		else if ( aux[i] < aux[j] ) {
			 arr[k] = aux[i++];
		}
		else {
			arr[k] = aux[j++];
		}
	}
		
}

template <class T, size_t N>
void MergeSort<T,N>::_sort(T (&arr) [N], int start, int end) {

	if(start >= end)
		return;

	int mid = start + (end - start) / 2;
	_sort(arr, start, mid);
	_sort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}

int main(void) {


        int foo[] = { 16, 15, 14, 40, 12, 6, 5, 18 };
        MergeSort<int, 8>::sort( foo );
        for(int i = 0; i < 8; ++i)
                std::cout << foo[i] << std::endl;

        return 0;
}
				
