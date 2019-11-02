#!/bin/bash
# PROBLEM STATEMENT: Write a shell script that counts and prints the total number of files in current working directory and in all of its sub-directories. Also (i) print total no. of files (not directories) in each subdirectory with the name of the subdirectory, (ii) print only those file names that have been created within the past 2 days. 

# PART 1: Counting total number of files
echo "The total number of files is: "
find ./ -type f | wc -w
echo

# PART 2: Printing number of files in each subdirectory
echo "The directory-wise distribution of files is: "
find . -maxdepth 1 -mindepth 1 -type d | while read dir; 
do
	count=$(find "$dir" -type f | wc -l)
  	echo "$dir : $count "  
done
echo

# PART 3: Printing files created in last 2 days
echo "The files created in last 2 days are: "
find ./ -type f -mtime -2 | sort

