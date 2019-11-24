#!/bin/bash
#echo $#
if [ $# = 0 ]
then
        echo "Please supply assignment sub number in command line...terminating"
        exit 1
fi
val=1
for i in `seq 1 $1`
do
	val=$(($val*i))
done
now=$( date )
echo "The factorial is $val"
times
