//Demeter Tamás
//511/2
/*Adott egy n * n méretű tömb. Határozzuk meg a mellékátló alatti elemek közül a legnagyobbat! A bemenet első sora tartalmazza az n értékét, ezt követően pedig az n x n elemet.*/
#include <stdio.h>

main() {
	FILE* f;
	int i,j,n;
	int a[20][20];
	f = fopen("dtim1806_L3_2.txt", "r");
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fscanf(f, "%d", &a[i][j]);
		}
	}
	int max = -1;
	for (i = n-1; i > 0; i--) {			//duplaforral megyunk, de nem jarjuk be a teljes matrixot. lasd:elso,masodik parameter forokban.
		for (j = n-1; j+i >= n; j--) {		//nem ereztem szukseget, hogy ebbol a par sorbol alprogramot keszitsek, mivel maga a feladat nem igazan osszetett, s csak ennyit ker
			if (a[i][j] > max) max = a[i][j];
		}
	}

	for (i = 0; i < n; i++) {		//matrix kiiratasa, a szemleletesseg kedveert
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\nA mellekatlo alatti legnagyobb elem: %d", max);
	fclose(f);
	system("PAUSE>>VOID");
}