#/bin/bash
for $i in "$1" "${@:2}"
do
	echo "$i"
	grep -o $1 "$i" | wc
done

