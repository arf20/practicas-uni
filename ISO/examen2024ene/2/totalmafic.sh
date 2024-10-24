#!/bin/bash

total=0
for tam in $(find $1 -type f -user $2 -printf "%s\n" 2> /dev/null)
do
	let total+=tam	
done
echo "tamaño de ficheros en $1: $total bytes"


