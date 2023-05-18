#!/bin/bash
#esercizio 2023 01 19 (gennaio)

merge() {
	a=$1;
	b=$2;
	merge=$3;
	mkdir $merge
	for file in $(ls $a)
	do
		echo "A: $file"
		cp -r $a/$file $merge
	done
	for file in $(ls $b)
	do
		echo "B: $file"
		cat $b/$file | cat >> $merge/$file
	done
}

merge $1 $2 $3

