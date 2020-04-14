#!/bin/bash
#Demeter Tamas
#dtim1806
#511/2
#lab5_3

#ellenorizzuk a parameterek helyesseget
if [ $# -lt 2 ]
then
	echo "Hasznalat: $0 <szoveg> <allomanyok>"
	exit 1
fi

szoveg=$1
shift

for i in $* ;do
	if [ ! -f $i ]
	then
	echo "\"$i\" nem file/hibas eleresi utvonal!"
	exit 2
	fi
done

#az adott szoveg minden elofordulasat (elso 30 sorban) kicserelunk egy olyan karakterre, amely nem fordulna elo altalaban, pl. csillag
#ezutan kitorlunk minden sort amely csillagot tartalmaz

for i in $* ;do
sed -i "1,30s/"$szoveg"/*/g" $i 
sed -i "/\*/d" $i 
done


