#6. Write a shell program that finds the factorial of an integer and displays the result with 
#a suitable message. Also mention the time taken to find out the corresponding factorial. Test the program for different integers.

echo -n "Enter the number: "
read num
fact=1
start=$(date +%s%N)
for((i=1;i<=num;i++)) 
do
    fact=$((fact*i))
done
end=$(date +%s%N)
echo "Factorial of $num is $fact."
diff=$((end - start))
diff=$((diff/1000))
echo "Time Taken to compute is $diff microseconds."
