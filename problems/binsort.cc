#include <iostream>
#include <algorithm>

using namespace std; 
void prnt(int arr[], int len) {
	for(int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl; 
}
int main(void) {

	int a[] =  {1,0,0,1,1,0,0,1,0,1,1};
	int start = 0;
	int pivot = a[0]; 
	int end = sizeof(a) / sizeof(int); 
	int fwd = start - 1;
	int bwd = end; 
	
	while(true) {
		
		while (a[++fwd] == 0)
			if(fwd == end)
				break;
 
		while (a[--bwd] == 1) 
			if(bwd == start)
				break; 
		
		if(fwd >= bwd)
			break; 

		std::swap(a[fwd], a[bwd]) ;
		prnt(a, end); 
	}
	


	return 0; 
}

