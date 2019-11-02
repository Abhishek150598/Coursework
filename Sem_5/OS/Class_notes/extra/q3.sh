#!/bin/bash


#The function foo() lists the number of files/directories in the folder

#and also lists the details of files/directories inside the folder
 function 

foo()

{
	
	
	#echo -e "\n"										
	#Newlines to neaten output
	

	declare x=$(ls | wc -l)								

	#Returns the linecount of the ls command. 
	#Gives the number of
 files/directories in the present working directory
	
	#echo "$x FILES/FOLDERS IN THIS DIRECTORY"
	

	declare dir_count=$(ls -l | grep "^d"|  wc -l)		

	#Returns the number of directories in the present working dir
	

	declare file_count=$(($x-$dir_count))				

	#Difference between the previous two results gives the number of files
	
	

	printf "%d FILES, %d FOLDERS\n" $file_count $dir_count 


}




tab_value=0												

#Since output is like a tree, tab value keeps tracks of the tabs at the beginning of a line of the output

function fooRecur()										
#Calls the function foo for the current directory for dir in */										
#Iterates over each directory in the current folder (filename ending with /)
	

do
		
#echo -e "\nSubdirectory: $dir"					
#Displays name of subdirectory
		

printf "\t%.0s" $tab_value
		
printf "%s: " $dir
		
cd "$dir" 										

#Changes PWD
		

foo												

#Calls foo with subdirectory as the PWD
		

(( tab_value+= 1))								

#Increases tab value every time it goes deeper into directory tree
		
		

declare dir_count=$(ls -l | grep "^d"|  wc -l)
		
if [ $dir_count -ne 0 ]; then					

#If the directory has further subdirectories, then it recurses
			

fooRecur									

#over all subdirectories
		

fi
		
		
cd ..											

#Changes back PWD
		

(( tab_value-= 1))
	
done




#Main function	


echo 
printf "%s: " ${PWD##*/}

foo

fooRecur

