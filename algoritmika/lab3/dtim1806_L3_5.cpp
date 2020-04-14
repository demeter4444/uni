//Demeter Tamás
//511/2
//Olvassunk be soronként több karakterláncot. A karakterláncok kisbetűket és számjegyeket tartalmaznak. Írjunk programot, amely kiszámolja minden karakterlánc esetében a bennük esetlegesen előforduló számok összegét!
#include <stdio.h>
#include <string.h>

int szamol(char s[255]) {		//egy stringbe szamolja a szamok osszeget alprogram
	int sum = 0;
	int i = 0;
	int vegso = 0;
	strcat(s, " ");		//a fajl utolso stringjenek utolso karaktere ha szam, azt nem vette figyelembe. megcseleztem
	while(s[i] != '\0'){		//meunk string vegeig
		if ((s[i] >= '0') && (s[i] <= '9')) {  //mikor szamot talal elkezdjuk epiteni
			(sum = sum * 10 + (s[i] - '0'));
		}
		else {
			vegso = vegso + sum;	//mikor nem-szam karaktert talal, az elozo epitest befejezzuk, osszeadjuk, s lenullazzuk a szamolo valtozot
			sum = 0;
		}
		i++;
	}
	return vegso;
}

main() {
	FILE *f;
	char s[255];
	f = fopen("dtim1806_L3_5.txt", "r");
	printf("Szamok osszege: \n");
	while (!feof(f)) {
		fgets(s, 255, f);			//soronkent, fajl vegeig olvasunk be stringeket, s meghivjuk ra alprogramunkat
		printf("%d \n", szamol(s));		//a konzolba, soronkent kiirja a megfelelo beolvasott sor(string) szamjainak osszeget
	}
	fclose(f);
}
