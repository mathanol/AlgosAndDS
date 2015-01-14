#!/bin/bash 

echo '#include "HashMapSepChain.h"

int main(void) {

        HashMapSepChain<int,int> *l = new HashMapSepChain<int, int>();
'

for i in `seq 1 100` ; do 
	echo -e "\tl->put($RANDOM, $RANDOM);"
done 
echo "      return 0;
}
"


