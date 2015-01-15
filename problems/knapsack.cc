#include <iostream>

using namespace std; 

int knapsack(int *w, int *v, int W, int num_items) { 

	int M[W + 1][num_items + 1]; 
	int keep[W + 1][num_items + 1]; 
	
	for(int i = 0; i <= W; i++) {

		for(int j = 0; j <= num_items; j++) {

			if ( i == 0 || j == 0 ) {
				M[i][j] = 0; 
				keep[i][j] = 0; 
			}

			else if (w[j - 1] <= i) {
				if (M[ i - w[j - 1] ][j - 1] + v[j - 1] > M[i][j - 1]) {
					keep[i][j] = 1;
					M[i][j] = M[ i - w[j - 1] ][j - 1] + v[j - 1]; 
				} else {
					keep[i][j] = 0; 
					M[i][j] = M[i][j - 1]; 
				}
			} else {
				M[i][j] = M[i][j - 1];
				keep[i][j] = 0;
			}

		}

	}
	int i = W;
	int j = num_items;
	while( i >= 0 && j >= 0 ) {
		if(keep[i][j]) {
			 i = i - w[j - 1]; 
			 cout << "Item: " << j << endl; 
			 j--;
		}
		else 
			j--; 
	}
	

	return M[W][num_items]; 
}

int main(void) { 

	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int  W = 50;
	
	std::cout << knapsack(wt, val, W, 3) << std::endl; 

	return 0; 
}

   
