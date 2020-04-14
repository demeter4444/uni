#!/bin/bash
#Demeter Tamas
#511/2
#dtim1806
#L06_7_B

last|sed 's/[ ][ ]*/ /g'|sed 's/system boot/systemboot/g'|awk '{
	bejelentkezesek[$4]++
	}
	END {
	printf("Bejelentkezesek:\n")
	printf("Hetfo: %d\n",bejelentkezesek["Mon"])
	printf("Kedd: %d\n",bejelentkezesek["Tue"])
	printf("Szerda: %d\n",bejelentkezesek["Wed"])
	printf("Csutortok: %d\n",bejelentkezesek["Thu"])
	printf("Pentek: %d\n",bejelentkezesek["Fri"])
	printf("Szombat: %d\n",bejelentkezesek["Sat"])
	printf("Vasarnap: %d\n",bejelentkezesek["Sun"])
	max=bejelentkezesek["Mon"]
	maxnap="Hetfo"
	for (i in bejelentkezesek)
		if (bejelentkezesek[i] > max)
			max=bejelentkezesek[i]
	for (i in bejelentkezesek)
		if (bejelentkezesek[i] == max)
			maxbejelentkezesek[i]=i
	
	printf("Legtobb bejelentkezes: %d\n",max)
	printf("Ezeken a napokon: \n")
	for (i in maxbejelentkezesek){
		maxnap=i
		if (maxnap == "Mon"){
			maxnap="Hetfo"
			}
		if (maxnap == "Tue"){
			maxnap="Kedd"
			}
		if (maxnap == "Wed"){ 
			maxnap="Szerda"
			}
		if (maxnap == "Thu"){ 
			maxnap="Csutortok"
			}
		if (maxnap == "Fri"){ 
			maxnap="Pentek"
			}
		if (maxnap == "Sat"){ 
			maxnap="Szombat"
			}
		if (maxnap == "Sun"){ 
			maxnap="Vasarnap"
			}
		
	print maxnap
	}
}'
