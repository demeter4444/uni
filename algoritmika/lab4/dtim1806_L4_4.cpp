//Demeter Tamás
//511/2
//Adott n programozó fizetése. Válogassuk szét őket a fizetésük alapján. Az első csoportba azok kerülnek, akiknek a fizetésük nagyobb mint 1000 EUR, a másodikba a megmaradtak közül azok, akiknek a fizetése nagyobb mint 700 EUR, a harmadikban maradnak a többiek (a sorrend nem fontos). Törekedjünk egyetlen tömbbel dolgozni.

#include <stdio.h>

//lehet szetrendezesrol lenne szo, de az adott peldanal magyarul azt keri a feladat hogy rendezzuk csokkeno sorrendbe az egeszet, a csoportok ugyis kialakulnak
main() {
	FILE*f;
	f = fopen("dtim1806_L4_4.txt", "r");
	int n,i,j;
	int *v;
	fscanf(f, "%d", &n);
	v = (int*)malloc(n * sizeof(int));
	int csere,p;
	for (i = 0; i < n; i++) fscanf(f, "%d", &v[i]);
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++) if (v[j] > v[i]) {
			csere = v[i];
			v[i] = v[j];
			v[j] = csere;
		}

		//azert hogy ne csinaljak teljes csufsagot, szetvalasztom a csoportokat
	int k = 0;
	for (i = 0; i < n; i++) {
		printf("%d ", v[i]);
		if ((v[i + 1] < 1000) && (k == 0)) {
			printf("\n");
			k = 1;
		}
		if ((v[i + 1] < 700) && (k == 1)) {
			printf("\n");
			k = 2;
		}
	}

	fclose(f);
}