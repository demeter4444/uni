#!/bin/bash

#Demeter Tamas
#dtim1806
#511/2
#shell2
#7. feladat

#inicializalasok
declare -A joefelhasznalok
declare -A vimfelhasznalok
maxvim=0
maxjoe=0
joeatlag1=0
joeatlag2=0
vimatlag1=0
vimatlag2=0
sec=0
while [ 1 == 1 ]; do
let sec+=1
sumjoe=0
sumvim=0

#elmentjuk a joe es vim felhasznalokat aszoc tomb segitsegevel
for i in `ps --no-header -fC vim|sed "s/  */*/g"`;do
fh=`echo $i|cut -d"*" -f1`
vimfelhasznalok[$fh]=1
done
for i in `ps --no-header -fC joe|sed "s/  */*/g"`;do
fh=`echo $i|cut -d"*" -f1`
joefelhasznalok[$fh]=1
done

#megszamoljuk a kulonbozo joe felhasznalokat
#echo "Joe felhasznalok:"
for i in "${!joefelhasznalok[@]}"; do
	if [ ${joefelhasznalok[$i]} == 1 ]
	then
	let sumjoe+=1
	#echo $i
	fi
done

#ha valtozott a "rekord", elmentjuk
if [ $sumjoe -gt $maxjoe ]
then
	let maxjoe=$sumjoe
	let maxjoet=$SECONDS
fi

#echo "$sumjoe felhasznalo"

#ugyanezt vimre
#echo "Vim felhasznalok:"
for i in "${!vimfelhasznalok[@]}"; do
	if [ ${vimfelhasznalok[$i]} == 1  ]
	then
		let sumvim+=1
        	#echo $i
	fi
done

if [ $sumvim -gt $maxvim ]
then
	let maxvim=$sumvim
	let maxvimt=$SECONDS
fi

#ellenorizzuk, hogy egy adott felhasznalo mar nem futtat-e vimet vagy joet.
#vim eseteben kiirjuk az uzenetet
#mindket esetben megfeleloen modositjuk a tomboket
for i in "${!vimfelhasznalok[@]}"; do
	if [ ${vimfelhasznalok[$i]} == 1 ]
	then
		if ps --no-header -fC vim|grep "$i" >>/dev/null 
		then
			continue
		else
			echo "$i intelligens felhasznalo :)"
			let vimfelhasznalok[$i]=0
			if eval echo "~$i"|grep "gr511" >>/dev/null
			then
			echo "gratulalok, hogy kileptel vimbol bastya"|write $i
			fi
		fi
	fi
done

for i in "${!joefelhasznalok[@]}"; do
	if [ ${joefelhasznalok[$i]} == 1 ]
	then
		if ps --no-header -fC joe|grep "$i" >>/dev/null
		then
			continue
		else
			let joefelhasznalok[$i]=0
		fi
	fi
done

#minden 5 masodpercben az atlaghoz hozzaadjuk a jelenlegi 5 masodperc adatait.
let joeatlag1+=$sumjoe
let vimatlag1+=$sumvim

#percenkenti muveletek
if [ $sec == 12  ]
then
sec=0
#meghatarozzuk az atlagokat(60 masodpercben 5 masodperc 12szer fordul elo)
let joeatlag1/=12
let vimatlag1/=12

#esettargyalasok
if [ $joeatlag2 -gt $joeatlag1 ]
then
	echo "Joe: csokkent a felhasznalok szama"

fi

if [ $joeatlag2 -eq $joeatlag1 ]
then
	echo "Joe: nem valtozott a felhasznalok szama"

fi
if [ $joeatlag2 -lt $joeatlag1 ]
then
	echo "Joe: nott a felhasznalok szama"
fi
if [ $vimatlag2 -gt $vimatlag1 ]
then
	echo "Vim: csokkent a felhasznalok szama"

fi
if [ $vimatlag2 -eq $vimatlag1 ]
then
	echo "Vim: nem valtozott a felhasznalok szama"
fi
if [ $vimatlag2 -lt $vimatlag1 ]
then
	echo "Vim: nott a felhasznalok szama"
fi

#rekordtargyalasok
echo "Joe rekord: $maxjoe a $maxjoet masodpercben"
echo "Vim rekord: $maxvim a $maxvimt masodpercben"

#atlagok leptetese 
let joeatlag2=$joeatlag1
let vimatlag2=$vimatlag1
let joeatlag1=0
let vimatlag1=0
fi #60masodperces if

sleep 5
done #vegtelen ciklus


