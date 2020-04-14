//Demeter Tamás
//511/2
//Adott egy római szám, írjuk ki arab számjegyekkel!

//I - 1
//V - 5
//X - 10
//L - 50
//C - 100
//D - 500
//M - 1000

// IV, IX, XL, XC, CD, CM -specialis esetek

#include <stdio.h>
#include <string.h>

main() {
	char szam[20];
	fgets(szam, sizeof(szam), stdin);
	int i;
	int s = 0;								//beolvassuk string-kent a romai szamot, majd vegigjarjuk az elemeit, minden lehetseges esetet ellenorizve.
	for (i = 0; i < strlen(szam); i++) {    //megengedem magamnak ezt a megoldast, mert viszonylag keves "eset" van
		if (szam[i] == 'M') s += 1000;
		if (szam[i] == 'D') s += 500;
		if (szam[i] == 'C') {
			if (szam[i + 1] == 'D') {
				s += 400;
				i++;
			}
			else s += 100;
		}
		if (szam[i] == 'L') s += 50;
		if (szam[i] == 'X') {
			if (szam[i + 1] == 'C') {
				s += 90;
				i++;
			}
			else if (szam[i + 1] == 'L') {
				s += 40;
				i++;
			}
			else s += 10;
		}
		if (szam[i] == 'V') s += 5;
		if (szam[i] == 'I') {
			if (szam[i + 1] == 'X') {
				s += 9;
				i++;
			}
			else if (szam[i + 1] == 'V') {
				s += 4;
				i++;
			}
			else s += 1;
		}


	}
	printf("Arab szamkent = %d", s);
	system("PAUSE>>VOID");
}