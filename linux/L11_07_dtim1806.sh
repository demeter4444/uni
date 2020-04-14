#!/bin/bash

#Demeter Tamas
#dtim1806
#511/2
#7. feladat

#A kliens információt kér állományokról. A szerver ellenőrzi, hogy létezik-e az adott állomány, és válaszként visszaküldi az állomány típusát, méretét, hány különböző néven hivatkoznak rá, szöveges állományok esetében pedig az állomány sorainak és szavainak számát is. A kliens az állományneveket paraméterként kapja.

if [ $# -lt 1 ]
then
	echo "Shellscript nem kapott parametert!"
	exit 1
fi

if [ ! -f $1 ]
then
	echo "$1 nem letezo allomany!"
	exit 1
fi

echo "$1:"
tipus=`file $1|cut -d":" -f2`
meret=`du -h $1|cut -f1`
inum=`ls -i $1|cut -d" " -f1`

echo "Tipus: $tipus"
echo "Meret: $meret"
echo "Hivatkozasok: "
find -follow -inum $inum

if echo $tipus|grep "text" >> /dev/null
then
sorok=`wc -l $1|cut -d" " -f1`
szavak=`wc -w $1|cut -d" " -f1`
echo "Sorok szama: $sorok"
echo "Szavak szama: $szavak"
fi

exit 0
