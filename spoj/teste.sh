#!/bin/bash

#script to testing files from: http://olimpiada.ic.unicamp.br/passadas

###########################
#       USAGE             #
# 1- sh teste.sh name exe #
# 2- sh teste.sh name     #
###########################

NAME=$1
if [ -z $2 ]; then EXE='a.out'; else EXE=$2; fi
TESTS=$(echo $(ls ~/Downloads/$NAME | wc -l))
i=1
while((i<=$TESTS)); do
    A='~/Downloads/'$NAME'/test'$i
    CASES=$(echo $(eval $(echo 'ls '$A' | wc -l')))
    CASES=$(expr $CASES / 2)
    j=1
    while((j<=$CASES)); do
        echo 'teste: '$i','$j' -> '$(eval $(echo './'$EXE' < '$A'/in'$j' | diff '$A'/out'$j' -' ))
        j=$(expr $j + 1)
    done
    i=$(expr $i + 1)
done
