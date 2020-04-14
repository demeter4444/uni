//Demeter Tamás
//511/2
//Írjunk rekurzív algoritmust, amely átalakít egy, a 16-os számrendszerben megadott számot a 10-es számrendszerbe!

#include <stdio.h>
#include <math.h>
#include <string.h>

int alakit(char *hex, int i, int h) { //hex maga a szam, karakterlanckent, i az aktualis pozicio (az utolsotol kezdjuk), h az aktualis hatvany (0tol kezdjuk)

	if (i >= 0) {

		char chr = hex[i];
		int szj;

		if ((chr >= 'A' && chr <='F')) szj = chr - 'A' + 10; //a karaktert szamma alakitjuk.
		else if ((chr >= 'a' && chr <= 'f')) szj = chr - 'a' + 10;
		else szj = chr - '0';

		return szj * (int)pow(16, h - 1) + alakit(hex, i - 1, h + 1) ; //a karakterek "osszeget" rekurzivan allitjuk elo

	}
	else 
		return 0;
	}



main() {
	char h[16]; //legyen mondjuk max 64 bites szam
	printf("hexa szam  = ");
	fgets(h, 16, stdin);
	printf("%d", alakit(h, strlen(h)-1, 0));
}