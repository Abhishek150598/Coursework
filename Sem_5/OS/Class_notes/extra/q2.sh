#!/bin/bash


#If there are no command line arguments, shows an error and exits


if [ "$#" -eq 0 ]; then
	
	echo "Usage: ./q2.sh <ROLL_NUMBER>"
	

exit 1
fi



#If the directory exists, shows appropriate message

#else, creates the new directory


if [ -d "CSE-$1" ]; then
	
	echo "Directory Exists. Not creating again"

else
	
	mkdir "CSE-$1"
fi
declare dir_name="CSE-$1"



#Q2(a)

#Allows READ permissions for user, group and others


chmod 444 $dir_name

echo -e "\nJust read permissions for all users"


echo "Check out the file listing"
ls -al | grep "$dir_name"

read -p "Enter any key to continue" yn




#Q2(b)

#Allows READ and WRITE permissions for user and group

#No permissions for others


chmod 660 $dir_name

echo -e "\nJust read and write for owner and group"


echo "Check out the file listing"
ls -al | grep "$dir_name"

read -p "Enter any key to continue" yn




#Q2(c)

#Allows READ, WRITE, EXEC permissions for the user

#only EXEC permission for group. No permissions for others


chmod 710 $dir_name
echo -e "\nJust execute permissions for group. All permissions for owner"

echo "Check out the file listing"
ls -al | grep "$dir_name"

