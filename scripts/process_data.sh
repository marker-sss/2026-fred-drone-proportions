#!/bin/sh

for file in datasets/*data*
	do
		base=$(basename "$file")
		name="${base%.*}"
		grep -v '^[[:space:]]*$' $file | sed  's/,/ /g' > cleaned.txt
		./bin/count_pixels cleaned.txt > ${name}_events.txt
	done
