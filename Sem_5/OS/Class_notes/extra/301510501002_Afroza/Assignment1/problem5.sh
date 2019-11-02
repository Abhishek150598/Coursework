#5. Modify the script in (4) to substitute word “Module” preceded by word “This” to word “Function”.

if [ $# -ne 6 ]; 
	then 
		echo "You are supposed to enter 6 file names in command line."
else	
	for entry in "$@"
	do
	filename=$entry
	if [[ -f $filename ]] ; 
	then
    	sed -i -e 's/This Function/This Module/g' $filename
		echo "Processed $filename."
	else
    	echo "The file $filename does not exist."
	fi
	done
fi

