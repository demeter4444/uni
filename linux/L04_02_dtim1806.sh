#!/bin/bash
#Demeter Tamas
#dtim1806
#511/2
#L4_2

#ellenorizzuk, hogy legalabb 2 parameter szerepel, s az elso kivetelevel mind fajl

if [ $# -lt 2 ]
then
echo "Hasznalat: $0 <szo> <allomanyok>"
exit 1
fi

szo=$1
shift

for i in $* ;do
	if [ ! -f $i ]
	then
	echo "\"$i\" parameter nem fajl/helytelen eleresi utvonal!"
	exit 2
	fi
done

#a szavat tartalmazo allomanyokat sorszamozva kiirjuk
echo "$szo-t tartalmazzak (kulon szo-kent!):"
c=0
for i in $* ;do
	let c+=1
	if grep -w "$szo" $i >>/dev/null
	then
	echo "$c. $i"
	fi
done
