#include <stdio.h>
#include <stdlib.h>

struct activity {
	int start; 
	int finish;
	int id;
};

int cmp(const void *x, const void *y) { 

	int a = ((struct activity *)x)->finish;
	int b = ((struct activity *)y)->finish;
	
	if(a > b)
		return 1;
	else if(a < b)
		return -1;
	return 0;
}

void sel_activity(struct activity *ac, int len) { 
	
	qsort(ac, len, sizeof(*ac), cmp); 
	int sel = 0;
	printf("%d selected\n", ac[sel].id); 
	for(int i = 1; i < len; i++) { 
		if (ac[i].start >= ac[sel].finish) {
			printf("%d selected\n", ac[i].id); 
			sel = i;
		}
	}
}

int main(void) { 
	int len = 6;
	struct activity *ac = (struct activity *)malloc(len * sizeof(struct activity)); 
	
	ac[0].start = 5;
	ac[0].finish = 9;
	ac[0].id = 0;
	
	ac[1].start = 0;
	ac[1].finish = 6;
	ac[1].id = 1;
	
	ac[2].start = 3;
	ac[2].finish = 4;
	ac[2].id = 2;

	ac[3].start = 8;
	ac[3].finish = 9;
	ac[3].id = 3;

	ac[4].start = 1;
	ac[4].finish = 2;
	ac[4].id = 4;

	ac[5].start = 5;
	ac[5].finish = 7;
	ac[5].id = 5;

	sel_activity(ac, len); 
	free(ac);
}
