#!/bin/bash


#Deletes outfile.txt if it already exists


if [ -e "outfile.txt" ];then
	
	rm outfile.txt

fi


	touch outfile.txt									

#Creates the outfile.txt




echo "There are $# arguments" >> outfile.txt		

#Number of arguments passed over command line
													
#output written to file




echo "$8 $1 $2 $6 $7 $3 $4" >> outfile.txt			

#Rearranged argument written to file


echo >> outfile.txt									

#One line whitespace to neaten the output



echo -e "\nAll users on the system: " >> outfile.txt	

who >> outfile.txt									

#The different users logged onto the current system



echo -e "\nCurrent User Details: " >> outfile.txt	

who am i >> outfile.txt								

#Complete details of the current user



echo -e "\nCurrent System Date: " >> outfile.txt	

date "+%d-%m-%Y">> outfile.txt									

#Current System date
