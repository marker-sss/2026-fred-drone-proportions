#!/bin/sh
for file in networks/*
	do
		echo $file >> fitness_matrices.txt
		$cppa/bin/classify_risp -a test -n $file >> fitness_matrices.txt
		echo "" >> fitness_matrices.txt
	done
