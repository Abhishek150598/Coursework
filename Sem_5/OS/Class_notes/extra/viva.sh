#!/bin/bash

if [ $# -eq 0 ] ; then
	echo "USAGE: $0 filename"
	exit 1
fi

if [ ! -f $1 ] ; then
	echo "INVALID FILENAME. $1 is not a valid filename."
	exit 1
fi

filename=$1
word_count=$(grep -o "[aeiou]" $filename| wc -l)
echo "$word_count instances of vowels found in file $filename"