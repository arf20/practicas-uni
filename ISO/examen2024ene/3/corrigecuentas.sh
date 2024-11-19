#!/bin/bash

while read linea
do
	if ! [ -z $linea ]; then
		expresion=$(echo $linea | cut -f1 -d"=")
		let result=$expresion
		testresult=$(echo $linea | cut -f2 -d"=")  
	
		if [ "$result" == "$testresult" ]; then
			echo "resultado correcto"
		else
			echo "resultado incorrecto: $expresion=$result"
		fi
	fi
done < $1

exit 0

