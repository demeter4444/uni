#!/bin/bash
#Demeter Tamas
#dtim1806
#511/2
#lab5_7

#ellenorizzuk a parameterek helyesseget
if [ $# -lt 1 ]
then
echo "Hasznalat: $0 <allomanyok>"
exit 1
fi


for i in $* ;do
if [ ! -f $i ]
	then
	echo "\"$i\" nem file/hibas eleresi utvonal!"
	exit 2
	fi
done

#az adott allomanyokban minden maganhangzot megvaltoztatunk, nagyot kicsire, kicsit nagyra
for i in $*; do
sed -i "y/aeiouAEIOU/AEIOUaeiou/" $i
done

