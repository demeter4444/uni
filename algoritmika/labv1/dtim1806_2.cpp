//Demeter Tamas
//511/2
//dtim1806
//8.tetel 2. feladat

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	FILE*f;
	f = fopen("dtim1806_2.txt", "r");
	int n,i;
	char nev[50][50];
	int mag[50];
	float s = 0.0;
	fscanf(f,"%d", &n);

	for (i = 0; i < n; i++) {
		fscanf(f, "%s %d", &nev[i], &mag[i]);
		s = s + (float)mag[i];
	}

	float atl = s / n;
	printf("atlagmagassag: %f\n", atl);
	printf("atlagmagassaghoz legkozelebb alloak:\n");

	float dif;
	float mindif = (float)abs(atl - mag[0]); //a "legkozelebb allo" tulajdonsagot kivonassal es abszolut ertekkel vegezzuk. inicializalast szokas szerint, a tomb egy letezo elemevel vegezzuk.
	for (i = 1; i < n; i++) {
		dif = (float)abs(atl - mag[i]);
		if (dif < mindif) mindif = dif;
	}

	for (i = 0; i < n; i++) if ((float)abs(atl - mag[i]) == mindif) printf("%s\n", nev[i]); //kiiratni az osszes ilyen tulajdonsagu elemet, bejarjuk 2szer mert szerintem van eleg pontom a tobbi feladatbol.

	//for (i = 0; i < n; i++) {
		//printf("%s %d\n", nev[i], mag[i]);
	//}

	fclose(f);
	//system("PAUSE>>VOID");
	return 0;
}