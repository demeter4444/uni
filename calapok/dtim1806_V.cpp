//Demeter Tamás, dtim1806, 511/2, 59. feladat + 60. feladat

#include <stdio.h>
#include <string.h>
#define SMAX 256

int main() {
///////////////////////////////////////////////////////////////
//59. feladat (dinamikus)
//MEGJ : A bemeneti allomanyban, ha a matrixok merete kulonbozik, a kisebbiket irjuk elore, akarcsak ahogy helyes lenne az papiron. (ha osszeszorozhato)
	//fajl megnyitasa
	FILE*f = fopen("input.txt", "r");
	FILE*g = fopen("output.txt", "w");
	if (!f) {
		printf("Fajl megnyitas sikertelen\n");
		exit(0);
	}
	if (!g) {
		printf("Fajl megnyitas sikertelen\n");
		exit(0);
	}

	//elso meretek beolvasasa
	int x1, y1;
	int r = fscanf(f, "%d %d", &x1, &y1);
	if (r != 2) {
		printf("Beolvasas sikertelen\n");
		exit(1);
	}
	//elso matrix beolvasasa
	int **a;
	int i, j;
	a = (int**)malloc(x1 * sizeof(int*));
	for (i = 0; i < x1; i++) {
		a[i] = (int*)malloc(y1 * sizeof(int));
	}

	for (i = 0; i < x1; i++) {
		for (j = 0; j < y1; j++) {
			r = fscanf(f, "%d", &a[i][j]);
			if (r != 1) {
				printf("Beolvasas sikertelen");
				exit(1);
			}
		}
	}
	//masodik meretek beolvasasa
	int x2, y2;
	r = fscanf(f, "%d %d", &x2, &y2);
	if (r != 2) {
		printf("Beolvasas sikertelen");
		exit(1);
	}
	//masodik matrix beolvasasa
	int **b;
	b = (int**)malloc(x2 * sizeof(int*));
	for (i = 0; i < x2; i++) {
		b[i] = (int*)malloc(y2 * sizeof(int));
	}
	
	for (i = 0; i < x2; i++) {
		for (j = 0; j < y2; j++) {
			r = fscanf(f, "%d", &b[i][j]);
			if (r != 1) {
				printf("Beolvasas sikertelen");
				exit(1);
			}
		}
	}

	//szorzas + kiiratas
	if (y1 != x2) {
		printf("Hiba a matrixok szorzasaban");
		exit(2);
	}

	int k;
	for (i = 0; i < x1; i++) {
		for (j = 0; j < y1; j++) {
			int sum = 0;
			for (k = 0; k < y2; k++) {
				sum = sum + a[i][k] * b[k][j];
			}
			fprintf(g,"%d ", sum);
		}
		fprintf(g,"\n");
	}

////////////////////////////////////////////////////////////////////////////////////////////
//60. feladat (statikus)
	//struktura
	struct harmas {
		char nev[SMAX];
		int szam;
		char betu;
	};
	//beolvasas
	struct harmas v[100];
	i = 0;
	while (!feof(f)) {
		r = fscanf(f, "%s %d %c\n", &v[i].nev, &v[i].szam, &v[i].betu);
		if (r != 3) {
			printf("Hiba az adatok beolvasasaban");
			exit(1);
		}
		i++;
	}
	int n = i;
	if (n <= 1) {
		printf("Nincs eleg adat");
		exit(3);
	}

	//csere
	for (i = 1; i < n; i++) {
		if (v[i - 1].szam < strlen(v[i].nev)) {
			(v[i].nev)[v[i - 1].szam] = v[i - 1].betu;
		}
		else printf("%d.sorban hiba.\n",i); //ha nem lehet kicserelni
	}

	//kiiratas
	for (i = 0; i < n; i++) {
		fprintf(g,"%s\n", v[i].nev);
	}
	
	fclose(f);
	fclose(g);

	return 0;
}