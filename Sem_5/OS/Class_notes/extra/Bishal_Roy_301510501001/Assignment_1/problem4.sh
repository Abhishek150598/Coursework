#4. Write a shell script to search the word “Module” in six files simultaneously. Show the  output with 
#(i) total no. of occurrences of the word in each file, 
#(ii) no. of occurrences and the corresponding line no., for each file and 
#(iii) grand total of occurrences in all files.

if [ $# -ne 6 ];
  then
	echo "You are supposed to enter 6 file names in command line."
else
	read -p "Enter the word you want to find: " word
	sum1=0
	for entry in "$@"
	do
	filename=$entry
	if [[ -f $filename ]];
	  then
    	echo "Number of occurences of $word in $filename: "
    	grep -n "$word" "$filename" | wc -l
    	flag=$(grep -n "$word" "$filename" | wc -l)
    	sum1=$((sum1 +flag))
    	echo "LINE NO.:"
    	grep -n "$word" "$filename" | awk -F":" '{print $1}'
	else
    	echo "The file $filename does not exist."
	fi
	done
	echo "Total occurences of $word is $sum1."
fi
