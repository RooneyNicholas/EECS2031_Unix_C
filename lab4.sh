#!/bin/sh

#checks the total count of string "relation_name" and prints to screen
#prints message if "relation_name" does not exist in the database
cardinality_check() {
	if [ -n "$1" ]
	then
		count=`cut -f1 -d " " $database | egrep -c "^$1$"`
		if [ "$count" != 0 ]
		then
			echo "$1 $count"
		else
			echo "Relation $1 does not exist."
		fi
	fi
}

printf "Grock- "
read input
set "$input"
while [ "$1" != "quit" ]
do
	#searching for the names of relations in the database, does not need any other argument
	if [ "$1" = "relnames" ]
	then
		#to get correct behaviour, must check if database exists first
		#in this case, if the variable database is not empty same for other 2 "functions"
		if [ -n "$database" ]
		then
			cut -f1 -d " " $database | sort | uniq
		else
			echo "Database has not been set."
		fi
	#search the database for all entities, these are text fields 2 and 3 of given example
	elif [ "$1" = "entities" ]
	then
		if [ -n "$database" ]
		then
			cut -f2-3 -d " " $database | tr " " "\n" | sort
		else
			echo "Database has not been set."
		fi
	#search the database for cardinality of relations
	elif [ "$1" = "cardinality" ]
	then
		if [ -n "$database" ]
		then 
			cardinality_check "$2"
			cardinality_check "$3"
			cardinality_check "$4"
		else
			echo "Database has not been set."
		fi
	#set the database file, requires a readable text file
	#upon error of reading or finding file, prints error message
	elif [ "$1" = "setdb" ]
	then
		if [ -z "$2" ]
		then
			echo "Missing Argument."
		elif  [ ! -e "$2" ]
		then
			echo "File $2 does not exist."
		elif  [ ! -r "$2" ]
		then
			echo "File $2 is not readable."
		#if all checks of given file pass, then check the format of the given file
		else
			badFormat=`egrep -v '^[a-z0-9]*[ ][a-z0-9]*[ ][a-z0-9]*$' "$2"`
			if [ -n "$badFormat" ]
			then
				echo "Incorrect format in $2."
				echo "The following lines were incorrectly formatted."
				echo "$badFormat"
				echo "Database not set"
			else
				database=`cat $2`
				echo "Database set to $2."
			fi
		fi

		if [ -n "$3" ]
		then
			echo "Extra arguments ignored."
		fi
	else 
		echo "Unrecognized command."
	fi

	printf "Grock- "
	read input
	set $input
done

