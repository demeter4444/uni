#!/bin/bash
#Demeter Tamas
#dtim1806
#511/2
#L4/7


#ellenorizzuk, hogy legalabb egy parameter legyen
if [ $# -lt 1 ]
then
echo "Hasznalat: $0 <szerverek>"
exit 1
fi
#az osszes parametert pingeljuk 3szor, ha a ping sikeres volt (1es exitcodeja lesz,ha legalabb 1 packett viszajott) akkor elerheto kulonben nem.
#a hibacsatorna atiranyitasat ha mellozzuk, meghatarozhatjuk azt is, hogy egyaltalan letezik-e az adott szerver.
for i in $* ; do
	ping -c3 $i 2>>/dev/null 1>>/dev/null
	if [ $? -eq 0 ]
	then
	echo "$i:Elerheto"
	else
	echo "$i:Nem Elerheto"
	fi
done
