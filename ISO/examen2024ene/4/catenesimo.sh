#!/bin/bash

if [[ $# -le 3 ]]; then
	echo "numero minimo de parametros es 2"
	exit 1
fi

ren="^[0-9]+$"
if ! [[ $1 =~ $ren ]]; then
	echo "primer parametro debe ser numero natural"
	exit 1
fi

if ! [[ $1 -lt $# ]]; then
	echo "primer parametro $1 debe ser menor que numero total de parametros $#"
	exit 1
fi

for file in ${@:2}
do
	if ! [ -f "$file" ]; then
		echo "el parametro $file debe ser un fichero regular"
		exit 1
	fi
done

for file in ${@:2}
do
	if ! [ -r "$file" ]; then
		echo "el parametro $file debe tener permiso de lectura"
		exit 1
	fi
done




N=$1
i=0
for file in ${@:2}
do
	let i+=1
	if [ "$N" == "$i" ]; then
		cat $file
	fi
done


