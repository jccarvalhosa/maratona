#!/bin/bash

#script to testing files from: http://olimpiada.ic.unicamp.br/passadas

###########################
#       USAGE             #
# 1- bash teste.sh name exe #
# 2- bash teste.sh name     #
###########################

DIR=/Users/jocarvalhosa/Downloads/$1
if [ -z "$2" ]; then EXE="a.out"; else EXE="$2"; fi
for T in $(ls $DIR); do
	for IN in $(ls $DIR/$T | grep in); do
		echo -n "$T: $IN -> "
		OUT=$(echo $IN | sed 's/in/out/')
		DIFF=$(diff -by $DIR/$T/$OUT <(./$EXE < $DIR/$T/$IN))
		if [ $? -eq 0 ]; then echo 'OK' ; else echo "$DIFF" ; fi
	done
done
