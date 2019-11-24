#!/bin/bash
echo "There are $# arguments"
declare x="$#"
declare y
declare -i count=0
rm outfile.txt
touch outfile.txt
for arg;
	do
		count=$((count+1))
		#echo $count
		#echo $x
		#echo ' '
		if [ "$count" != "$x" ]; then
			y=$arg
			printf "%s " "$arg" >> outfile.txt
		fi
done
echo "$arg" >> outfile.txt