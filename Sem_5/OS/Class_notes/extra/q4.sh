#!/bin/bash


#If filename is not passed through command-line, it asks for user input

#else, it takes the filename as the command line argument


declare 
fn
if [ $# -eq 0 ]; then
	
	echo "Command line argument not detected. Switching to manual input"
	
	read -p "Enter filename: " 
fn
else
	
	echo "Read filename from command line arguments"
	
fn=$1
fi




#if filename does not exist, then it displays error message

#else, displays the line count of the file


if [ ! -f $fn ]; then
	
	echo "File does not exist"

else
	
	declare x=$(cat "$fn" | wc -l)	
		
#Counts the number of lines in the file
	

echo "File has $x lines"

fi