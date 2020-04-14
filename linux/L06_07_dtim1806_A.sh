#!/bin/bash
#Demeter Tamas
#511/2
#dtim1806
#L6_7_A

if [ $# -lt 2 ]
then
	echo "Hasznalat: $0 allomany tantargy"
	exit 1
	fi

if [ ! -f $1 ]
then
	echo "Hasznalat: $0 allomany tantargy"
	echo "$1 nem allomany/hibas eleresi utvonal!"
	exit 2
	fi

datum=`date`

	awk -v datum="$datum" -v tantargy=$2 '	($4 >= 5){

	mail=sprintf("Kedves %s %s!\nA(z) %s vizsgan elert osztalyzata: %s",$1,$2,tantargy,$4)
	print datum >> sprintf("%s_log",tantargy)
	print mail >> sprintf("%s_log",tantargy)
	system("echo -e \""mail"\"|mail -s \"Vizsga\" "$3"@scs.ubbcluj.ro")
	}

	($4 < 5){

	mail=sprintf("Kedves %s %s!\nJojjon legkozelebb a(z) %s tantargybol vizsgazni.",$1,$2,tantargy)
	print datum >> sprintf("%s_log",tantargy)
	print mail >> sprintf("%s_log",tantargy)
	system("echo -e \""mail"\"|mail 0s \"Vizsga\" "$3"@scs.ubbcluj.ro")
	}

	' $1


