//Demeter Tamás
//511/2
//Számoljuk meg egy adott szövegben a magánhangzók számát!

//megadjuk egy konstanssal az osszes maganhangzot, majd karakterenkent szamoljuk megjelenesuket egy fajlban adott szovegben
#include <stdio.h>
const char mh[11] = { 'a','e','i','o','u','A','E','I','O','U' };
main() {
	FILE*f;
	f = fopen("dtim1806_L4_2.txt", "r");
	char c;
	int s = 0;
	int i;
	while (!feof(f)) {
		c = fgetc(f);
		for (i = 0; i < 11; i++) if (c == mh[i]) s++;
	}
	printf("Maganhangzok szama: %d", s);

	fclose(f);
	system("PAUSE>>VOID");
}