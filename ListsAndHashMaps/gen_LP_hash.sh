#!/bin/bash 

echo '#include "LPHash.h"

int main(void) {

        LPHash<int,int> *l = new LPHash<int, int>();
'

for i in `seq 1 100` ; do 
	echo -e "\tl->put($RANDOM, $RANDOM);"
done 
echo "      return 0;
}
"


