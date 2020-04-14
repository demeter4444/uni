//Demeter Tamás, dtim18ö6, 511/2
//8. labor 4. feladat
//kruskallal mondjuk meg hogy osszefuggo-e egy graf, vagy nem

#include <stdio.h>

main() {
	FILE*f = fopen("dtim1806_L8_4.txt", "r");
	 
	int n, v; //csomopontok, elek
	fscanf(f, "%d %d", &n, &v);

	struct el {
		int x;
		int y;
	};

	struct el elek[10];
	int i;
	for (i = 0; i < v; i++) 
		fscanf(f, "%d %d", &elek[i].x, &elek[i].y); //beolvassuk eleket
	

	int komp[10]; //komponensek tombe
	for (i = 1; i <= n; i++) komp[i] = i; //alapbol minden csomopont a sajat komponense

	for (i = 0; i < v; i++) {	//ha egy el osszekot 2 csomopontot, a komponenstombben mindket csomopont a kisebbik erteket veszi at
		int a = elek[i].x;
		int b = elek[i].y;
		if (komp[a] > komp[b]) komp[a] = komp[b];
		else if (komp[a] < komp[b]) komp[b] = komp[a];
	}

	//for (i = 1; i <= n; i++)printf("%d ",komp[i]); //ha ki akarjuk iratni a komponenseket

	int k = komp[1];
	int osszefuggo = 1;
	for (i = 1; i <= n; i++) {	//ha a komponens tomb minden eleme ugyanaz az ertek, osszefuggo. kulonben nem.
		if (komp[i] != k) osszefuggo = 0;
	}
	printf("\n");
	if (osszefuggo) printf("osszefuggo");
	else printf("nem osszefuggo");

	////
	/*printf("\n");
	int max = 0;
	for (i = 1; i <= n; i++) if (komp[i] > max) max = komp[i];
	for (i = max; i > 0; i--) {
		printf("%d. komponens:",i);
		for (int j = 1; j <= n; j++) {
			if (komp[j] == i) printf("%d ",j);
		}
		printf("\n");
	}*/
	

}