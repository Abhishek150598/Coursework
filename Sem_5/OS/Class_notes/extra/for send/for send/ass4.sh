#!/bin/bash
#echo $#
if [ $# = 0 ]
then
        echo "Please supply assignment sub number in command line...terminating"
        exit 1
fi

if [ $1 = "a" ]
then
        read var
	echo "The number of lines in the file is $( wc -l $var )"
elif [ $1 = "b" ]
then
        if [ $# = 1 ]; then
		echo "file name has to be supplied...terminating"
		exit 1
	fi
	echo "The number of lines in the file and the name of the file is $( wc -l $2 )"
else
        echo "wrong assignment number"
        exit 1
fi
echo "Done"

