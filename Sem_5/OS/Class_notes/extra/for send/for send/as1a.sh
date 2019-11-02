#!/bin/bash
echo "The total number of arguments is $#"
STR=''
for i in `seq 2 $#`
do
        STR="$STR $1"
        shift
done
printf "%s " $1
echo $STR
