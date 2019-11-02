# !/bin/bash 

while true
do
	# Taking user input
	read -p "Enter first number:  " userv1
	read -p "Enter second number:  " userv2

	# Checking for data type of input
	if [[ ( "$userv1" =~ ^[0-9]*$ || "$userv1" =~ ^[0-9]*[.][0-9]*$ ) && ( "$userv2" =~ ^[0-9]*$ || "$userv2" =~ ^[0-9]*[.][0-9]*$ )]] 
	then
		# Finding sum, difference, product and quotient
		sum=$(echo "$userv1 + $userv2" | bc)
		difference=$(echo "$userv1 - $userv2" | bc)
		product=$(echo "$userv1 * $userv2" | bc)
		

		if(( $(echo "$userv2 == 0" | bc -l) )) 
		then
			quotient="Error division by zero"
		else
			quotient=$(echo "scale=3 ; $userv1 / $userv2" | bc)
		fi

		# Printing the sum, difference, product and quotient
		echo "$userv1 + $userv2 = $sum"
		echo "$userv1 - $userv2 = $difference"
		echo "$userv1 * $userv2 = $product"
		echo "$userv1 / $userv2 = $quotient"
	else
		# Printing error massage if input are neither integers not floats
		echo "Invalid input"
	fi

	echo "To continue press 1 else 0"
	read ch
	if [[ ch -eq 0 ]]   
	then
		exit 0
	fi
done
