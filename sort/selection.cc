#include <iostream>
#include <algorithm>

template <class T, size_t N>
class Selection {

	public:
		static void sort( T (&arr) [N] );
};


template <class T, size_t N>
void Selection<T,N>::sort( T (&arr) [N]) {

	for (int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			if (arr[j] < arr[i])
				std::swap(arr[j], arr[i]);
		}
	}
}

int main(void) {


        int foo[] = { 16, 15, 14, 40, 12, 6, 5, 18 };
        Selection<int, 8>::sort( foo );
        for(int i = 0; i < 8; ++i)
                std::cout << foo[i] << std::endl;

        return 0;
}
				
