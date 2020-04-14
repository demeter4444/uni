#!/bin/bash
#Demeter Tamas
#dtim1806
#511/2
#lab5_11


#ellenorizzuk a parameterek helyesseget
if [ $# -lt 1 ]
then
echo "Hasznalat: $0 <allomanyok>"
exit 1
fi

for i in $*; do
if [ ! -f $i ]
then
echo "\"$i\" nem file/hibas eleresi utvonal!"
fi
done

#az adott allomanyok kozul torlunk mindent ami <>-ok kozott van (kicsereljuk uresstringre) (belertve a kacsacsoroket is. ez konnyen modosithato, s akar kitorolhetjuk ezutan az uressorokat is, de a feladat explicit nem kerte.
for i in $*; do
sed -i "s/<.*>//g" $i
done
