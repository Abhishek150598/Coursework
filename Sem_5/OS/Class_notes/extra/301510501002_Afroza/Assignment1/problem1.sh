#1. Write a shell script that 
#a) Counts the total number of files in CSE-xx. 
#b) Lists separately the files and sub-directories in CSE-xx.
#c) Repeat steps (a) and (b) for each sub-directory in CSE-xx.

echo "No. of files in this directory: "
ls | wc -l
echo "Listing only files in this directory: "
ls -al | grep ^-
echo "Listing only the sub-directories in this directory: "
ls -ld */

for dir in */;
do
	cd $dir
	echo "Now in subdirectory: $dir"
	echo "No. of files in this directory: "
	ls | wc -l
	echo "Listing only the files in this directory: "
	ls -al | grep ^-
	echo "Listing only the sub-directories in this directory: "
	ls -ld */
	cd ..
done

