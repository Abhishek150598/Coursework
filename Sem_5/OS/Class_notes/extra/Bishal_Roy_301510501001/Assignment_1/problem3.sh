#3. Write a shell script to count the number of lines in a file.
#a) the name of the file is to be given by the user.
#b) the name of the file is a command-line argument.
#Take appropriate measures if file does not exist.

if [ $# -ne 0 ];
  then
  	if [ -f "$*" ];
	  then
		echo -n "No. of lines in the file: "
		wc -l < $*
	else
		echo "File does not exist!"
	fi
else
	echo -n "No arguments supplied. Enter the file name: "
	read text
	if [ -f "$text" ];
	  then
		echo -n "No. of lines in the file: "
		wc -l < $text
	else
		echo "File does not exist!"	
	fi
fi




