#!/bin/bash
echo "The total number of arguments is $#" > am
STR=''
for i in `seq 2 $#`
do
	STR="$STR $1"
	shift
done
printf "%s " $1 >> am
echo $STR >> am
echo "The users logged into the system $( who | cut -d' ' -f1 | sort | uniq )" >> am
echo "The current user is $( whoami )" >> am
echo "The system time is $( date )" >> am
