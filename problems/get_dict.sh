#!/bin/bash 

DICT_DIR=./dict
if [[ -f $DICT_FILE ]]; then 
	echo $DICT_DIR exits
	exit 1
fi 
mkdir $DICT_DIR
cd $DICT_DIR

wget http://archive.services.openoffice.org/pub/mirror/OpenOffice.org/contrib/dictionaries/en_US.zip
unzip en_US.zip
rm -f en_US.zip
rm -f README_en_US.txt

