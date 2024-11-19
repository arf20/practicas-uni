#!/bin/bash
for file in $@
do
	if [ -f $file ]; then
		echo $(wc -l $file)
	fi
done


