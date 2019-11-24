#!/bin/bash



declare STARTTIME=$(date "+%s")


declare -i count 								

#Stores loop counter


declare -i number								

#Stores the user input


read -p "Enter number: " number					

#Accepts input from user


count=number 				


declare factorial=1								

#Stores the factorial


while [ $count -gt 0 ] 							

#while counter > 0


do
   

factorial=$(( $factorial * $count ))			

#Mathematical evaluation of factorial*count
   

count=$(( $count - 1 ))						

#Decrement of count variable

done


echo "$number! = $factorial"	


declare ENDTIME=$(date "+%s")				


echo "Time taken to compute this is $(($ENDTIME-$STARTTIME)) seconds"
