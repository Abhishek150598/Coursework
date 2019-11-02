#!/bin/bash
# PROBLEM STATEMENT: Write a shell script that counts the number of disk blocks occupied by a file (the file name is passed as an argument and the file may be assumed to be in the current directory). 

echo "The total number of disc blocks occupied by the file is:" 
stat -c "%b" $1