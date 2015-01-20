#include <iostream>
#include <algorithm>

template <class T, size_t N>
class QuickSort {

	public:
		static void sort( T arr[] );
	private:
		static void _sort(T arr[], int start, int end);
		static int partition(T arr[], int start, int end);

};


template <class T, size_t N>
void QuickSort<T,N>::sort( T arr[]) {
	
	_sort(arr, 0, N - 1);

}

template <class T, size_t N>
int QuickSort<T,N>::partition( T arr[], int start, int end) {

	int ploc = start + rand() % ( end - start + 1);
	std::swap(arr[ploc], arr[start]);
	int pivot = arr[start];
	int forward = start; 
	int backward = end + 1;

	while(true) {
	
		while( arr[++forward] < pivot ) {
			if(forward == end)
				break;
		}

		while( arr[--backward] > pivot ) {
			if (backward == start)
				break;
		}

		if (forward >= backward) {
			break;
		}
		std::swap(arr[forward], arr[backward]);

	}

	std::swap(arr[start], arr[backward]);
	return backward;
}

template <class T, size_t N>
void QuickSort<T,N>::_sort(T arr[], int start, int end) {

	if(start >= end)
		return;
	int part = partition(arr, start, end);
	_sort(arr, start, part - 1);
	_sort(arr, part + 1, end);
}

int main(void) {


        int foo[] = { 16, 15, 14, 40, 12, 6, 5, 18, 5, 5, 6, 11, 12, 12, 40};
        QuickSort<int, 15>::sort( foo );
        for(int i = 0; i < 15; ++i)
		std::cout << foo[i] << " ";
	std::cout << std::endl;
        return 0;
}
				
