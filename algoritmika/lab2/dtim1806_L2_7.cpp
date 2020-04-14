//Demeter Tamás
//511/2
//Adott egy arab szám (n ≤ 5000), írjuk ki római számjegyekkel!


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
	int n;
	printf("n = "); scanf_s("%d", &n);
	if (n <= 3999) {   //valojaban 3999 a legnagyobb szam, amit fel tudunk irni romai karakterekkel specialis szimbolumok nelkul (felulvonal). tudtom szerint legalabbis.
		int c1000 = n / 1000;	
		int c100 = (n / 100) % 10;		//a szamot felbontjuk szamjegyekre
		int c10 = (n / 10) % 10;
		int c1 = n % 10;
		printf("romai szamjegyekkel = ");
		while (c1000 != 0) {
			printf("M");
			c1000--;
		}
		while (c100 != 0) {
			if (c100 == 9) {
				printf("CM");
				c100 -= 9;
			}
			else if (c100 >= 5) {		//minden szamjegy eseten ellenorizzuk a lehetseges specialis eseteket, es ennek megfeleloen kiirjuk a karaktereket.
				printf("D");			//akarcsak az elozo feladatnal, megengedem magamnak ezt a megoldast, mivel keves ilyen eset van, es nem tudom altalanositani.
				c100 -= 5;
			}
			else if (c100 == 4) {
				printf("CD");
				c100 -= 4;
			}
			else {
				printf("C");
				c100 -= 1;
			}

		}
		while (c10 != 0) {
			if (c10 == 9) {
				printf("XC");
				c10 -= 9;
			}
			else if (c10 >= 5) {
				printf("L");
				c10 -= 5;
			}
			else if (c10 == 4) {
				printf("XL");
				c10 -= 4;
			}
			else {
				printf("X");
				c10 -= 1;
			}

		}
		while (c1 != 0) {
			if (c1 == 9) {
				printf("IX");
				c1 -= 9;
			}
			else if (c1 >= 5) {
				printf("V");
				c1 -= 5;
			}
			else if (c1 == 4) {
				printf("IV");
				c1 -= 4;
			}
			else {
				printf("I");
				c1 -= 1;
			}

		}
	}
	else printf("Tul nagy szam. (n<=3999)");
	system("PAUSE>>VOID");
}

