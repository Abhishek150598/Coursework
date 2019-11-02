#!/bin/bash
# PROBLEM STATEMENT: Write a shell script that takes 4 file names (C programs) as command line arguments and prints the frequency of the occurrences of the following 3 strings “printf”, “scanf”, “int” in each file. The output (in tabular format) should clearly denote the frequency of the occurrences of each string in each file.

# Array of search words
words=("printf" "scanf" "int")

# Loop to iterate through file names
for i in "$@"
do
	echo "In file $i :"
	# Loop to iterate through search words
	for j in "${words[@]}"
	do
		count=$(grep -o -w $j $i | wc -w)
		echo "$j : $count"
	done
	echo
done