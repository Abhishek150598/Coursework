#!/bin/bash

num=$1
if [ $# -ne 1 ] ; then
	echo -e "Command line argument not detected"
	read -p "Enter the number: " num
fi

echo $num
flag=0
for (( i=2;i*i<=num;i++ ))
do
	if [ $(( num%i )) -eq 0 ] ; then
		echo "$num is NOT PRIME"
		((flag=1))
	fi
done

if [ $flag -eq 0 ] ; then
	echo "$num is PRIME"
fi

i=0
a=0
b=1
while [[ $i -lt $num ]]
do
	echo $a
	((temp=a))
	((a=b))
	((b=a+temp))
	((i++))
	
done

