#!/bin/bash
#echo $#
if [ $# = 0 ]
then
        echo "Please supply assignment sub number in command line...terminating"
        exit 1
fi
if [ $1 = "a" ]
then
	cd CSE-02
	echo "The total number of files/sub_directories is $( ls | wc --words )"
	cd ../
elif [ $1 = "b" ]
then
	cd CSE-02
	ls
	cd ../
elif [ $1 = "c" ]
then
	cd CSE-02
	ls -R
else
	echo "Invalid assignment number, terminating"
	exit 1
fi
echo "Done"
