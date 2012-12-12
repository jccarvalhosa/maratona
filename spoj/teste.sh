#!/bin/bash

TESTS=20
CASES=3
NAME=$1
EXE=$2

i=1
while((i<=$TESTS)); do
    j=1
    while((j<=$CASES)); do
        echo 'teste: '$i','$j' -> '$(eval $(echo './'$EXE' < ~/Downloads/'$NAME'/test'$i'/in'$j' | diff ~/Downloads/'$NAME'/test'$i'/out'$j' -' ))
        j=$(expr $j + 1)
    done
    i=$(expr $i + 1)
done
