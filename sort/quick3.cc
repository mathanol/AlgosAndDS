#include <iostream>
#include <algorithm>

template <class T, size_t N>
class Quick3 {

	public:
		static void sort( T arr[] );
	private:
		static void _sort(T arr[], int start, int end);
};


template <class T, size_t N>
void Quick3<T,N>::sort( T arr[]) {
	
	_sort(arr, 0, N - 1);

}

template <class T, size_t N>
void Quick3<T,N>::_sort(T arr[], int start, int end) {

	if(start >= end)
		return;
	
	int eq = start + 1;
	int lt = start; 
	int gt = end; 
	int pivot = arr[start];
	
	//lt points to the beginning of the equality region 
	//eq points to right after the region of uncertainity 
	//therefore the next element that needs to be compared against

	while (eq <= gt) {
		
		if (arr[eq] < pivot) std::swap(arr[lt++], arr[eq++]); 
		else if (arr[eq] > pivot) std::swap(arr[gt--], arr[eq]); 
		else 
			eq++; 
	}
	
	_sort(arr, start, lt - 1);
	_sort(arr, gt + 1, end);
}

int main(void) {


        int foo[] = { 16, 15, 14, 40, 12, 6, 5, 18, 5, 5, 6, 11, 12, 12, 40};
        Quick3<int, 15>::sort( foo );
        for(int i = 0; i < 15; ++i)
                std::cout << foo[i] << std::endl;

        return 0;
}
				
