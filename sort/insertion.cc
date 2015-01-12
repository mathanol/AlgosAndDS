#include <iostream>
#include <algorithm>

template <class T, size_t N>
class Insertion {

	public:
		static void sort( T (&arr) [N] );
};


template <class T, size_t N>
void Insertion<T,N>::sort( T (&arr) [N]) {

	for (int i = 0; i < N; i++) {
		for(int j = i; j > 0; j--) {
			if (arr[j] < arr[j-1])
				std::swap(arr[j-1], arr[j]);
			else
				break;
		}
	}
}

int main(void) {


        int foo[] = { 16, 15, 14, 40, 12, 6, 5, 18 };
        Insertion<int, 8>::sort( foo );
        for(int i = 0; i < 8; ++i)
                std::cout << foo[i] << std::endl;

        return 0;
}
				
