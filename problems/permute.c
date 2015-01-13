#include <stdio.h>



void swap( char *a, int i, int j ) {

	char temp = a[j];
	a[j] = a[i]; 
	a[i] = temp; 
}

void permute( char *a, int start, int end ) {
	
	if (start == end)
		printf("%s\n", a); 
	else{
	
		for( int j = start; j <= end; j++) {

			//Swap start with each letter till the end
			swap( a,start, j ) ; 
			//Fix the string till the position of the swap
			permute( a, start + 1, end ); 
			//Remove the swap
			swap ( a, start, j ); 

		}
	}
}


int main(void) { 

	char a[4] = "ABC" ; 
	permute( a, 0 , 2); 

	return 0;
}

	


