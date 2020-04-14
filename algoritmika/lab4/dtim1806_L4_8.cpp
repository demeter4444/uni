//Demeter Tamás
//511/2
//Két természetes számot rokonnak nevezünk, ha van legalább két (különböző) közös számjegyük. Döntsük el adott két számról, hogy rokonok-e vagy sem!

#include <stdio.h>

main() {
	int a, b,c;
	printf("a = "); scanf("%d", &a);
	printf("b = "); scanf("%d", &b);
	int v[10] = { 0,0,0,0,0,0,0,0,0,0 }; //elofordulasokat szamolunk a 2 szamban
	int w[10] = { 0,0,0,0,0,0,0,0,0,0 };
	while (a > 0) {
		v[a % 10]++;
		a /= 10;
	}
	while (b > 0) {
		w[b % 10]++;
		b /= 10;
	}
	int i;
	int k = 0;
	for (i = 0; i <= 9; i++) {
		if ((v[i] > 0) && (w[i] > 0) && (k == 1)) {		//okosan hasznaljuk az igazsagfeltetelt(k) es minden jo ha jo a vege
			printf("rokon");
			k = 2;
			break;
		}
		if ((v[i] > 0) && (w[i] > 0)) k = 1;
	}
	if (k != 2) printf("nem rokon");
}