#!/bin/bash
# PROBLEM STATEMENT: Extend the shell script written in question (5) to perform the following task: User is asked to enter another word. (i) The first word (entered in question (5)) will have to be matched with the contents of the file and replaced by the second word, if a match occurs, (ii) Ignore replacing Partial matches, but show that partial matches do exist.

# Taking file name input
echo "Enter file name: "
read filename

# Taking string input
echo "Enter string: "
read string

# Finding the total no of occurences of the string in the file
count=$(grep -o $string $filename | wc -w)

# Printing the no of occurences if the word exists else printing error message
if [ $count == 0 ]
then
	echo "The given string doesn't exist in the file"
else
	echo "Number of occurences(including partial) of the given string is : $count"
	echo
	# Printing the no of occurences per line
	echo "Line-wise frequency: (including partial occurances)"
	line_number=1

	while read i
	do 
		count=$(echo $i |grep -o $string| wc -w)
		if [ $count -gt 0 ]  
		then
			echo "$line_number : $count"
		fi
		let line_number++
	done < $filename

fi

echo "Enter the string to be replaced with: "
read new_string

sed -i "s/\b$string\b/$new_string/g" "$filename"
echo "The original string has been replaced with the new string"

