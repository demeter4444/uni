// Demeter Tamas
//511/2
//dtim1806
//8. tetel 4. feladat

#include <stdio.h>

int main() {
	FILE*f;
	f = fopen("dtim1806_4.txt", "r");
	int n, i;
	int*a;

	fscanf(f, "%d", &n);
	a = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)fscanf(f, "%d", &a[i]);

	i = 0;
	int db,dbmax = 0;
	int poz1 = 0;
	int poz2 = 0;
	int poz1v = 0;
	int poz2v = 0;

	//bejarjuk a tombot es ha talalunk ket egyenlo egymasutani elemet, akkor addig szamoljuk a kovetkezoket, amig egyenloek
	//amikor ez mar nem igaz, osszehasonlitjuk az eddigi leghosszabbal. a kezdo es vegso poziciokat elmentjuk.

	while (i < n) {
		if (a[i] == a[i + 1]) {
			db = 0;
			poz1 = i;
			while (a[i] == a[i + 1]) {
				db++;
				poz2 = i + 1;
				i++;
			}
			if (db > dbmax) {
				dbmax = db;
				poz1v = poz1;
				poz2v = poz2;
		}
		}
		i++;
	}

	for (i = 0; i < n; i++)printf("%d ", a[i]);
	printf("\nLeghosszabb egyenlo elemekbol allo reszsorozat: \n");
	for (i = poz1v; i <= poz2v; i++) printf("% d", a[i]);
	fclose(f);
	system("PAUSE>>VOID");
	return 0;
}