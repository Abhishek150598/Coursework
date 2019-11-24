#!/bin/bash
#echo $#
if [ $# = 0 ]
then
	echo "Please supply assignment sub number in command line...terminating"
	exit 1
fi
if [ $1 = "a" ]
then
	echo "Allowing everyone to list files in CSE-02"
	chmod +r CSE-02
elif [ $1 = "b" ]
then
	echo "Giving group and owners all permits,Revoking all from others"
	chmod 770 CSE-02
elif [ $1 = "c" ]
then
	echo "Giving owner all permits,group execute, revoking all from others"
	chmod 710 CSE-02
else
	echo "wrong assignment number"
	exit 1
fi
echo "Done"
