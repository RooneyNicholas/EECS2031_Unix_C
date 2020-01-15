#!/bin/sh

printf "Grock- "
read string1 string2 extraArgs
while [ "$string1" != "quit" ]
do
	if [ "$string1" != "setdb" ]
	then
		echo "Unrecognized command."
	elif [ -z "$string2" ]
	then
		echo "Missing argument."
	elif  [ ! -e "$string2" ]
	then
		echo "File $string2 does not exist"
	elif  [ ! -r "$string2" ]
	then
		echo "File $string2 is not readable."
	else
		badFormat=`egrep -v '^[a-z0-9]*[ ][a-z0-9]*[ ][a-z0-9]*$' "$string2"`
		if [ -n "$badFormat" ]
		then
			echo "Incorrect format in $string2"
			echo "The following lines were incorrectly formatted"
			echo "$badFormat"
			echo "Database not set"
		else
			echo "Database set to $string2"
		fi
	fi

	if [ -n "$extraArgs" ]
	then
		echo "Extra arguments ignored"
	fi

	printf "Grock- "
	read string1 string2 extraArgs
done

