//Demeter Tamás
//511/2
/*Adott egy n * n méretű négyzetes tömb. Rendezzük át a tömb oszlopait úgy, hogy az oszlopelemek összege növekvő sorozatot alkosson! A bemenet első sora tartalmazza az n értékét, ezt követően pedig az n x n elemet.*/
#include <stdio.h>

int sum(int a[20][20], int n, int j) { //alprogram, mely kiszamolja egy oszlop osszeget
	int s = 0;
	int i;
	for (i = 0; i < n; i++) {
		s += a[i][j];
	}
	return s;

}

void rendez(int a[20][20], int n,int x,int y) {  //alprogram, mely megcserel 2 oszlopot egy matrixban(x,y)
	int i;
	int csere;
	for (i = 0; i < n; i++) {
		csere = a[i][x];
		a[i][x] = a[i][y];
		a[i][y] = csere;
	}
}

main() {
	FILE* f;
	int a[20][20];
	int n, i, j;
	f = fopen("dtim1806_L3_3.txt", "r");
	fscanf(f,"%d", &n);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++) {
			fscanf(f, "%d", &a[i][j]);
		}
	}


	
	for (i = 0; i < n-1; i++) {
		for (j = i + 1; j < n; j++) {
			if (sum(a, n, i) > sum(a, n, j)) {		//kozvetlencseres stilussal (lustavagyokna, de igerem tudok jobbakat is) novekvo sorrendbe rendezzuk az oszlopok osszege szerint
				rendez(a, n, i, j);
			}
		}
	}

	printf("\nrendezes utan:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);		//kiiratjuk 
		}
		printf("\n");
	}
	printf("\n");
	fclose(f);
	system("PAUSE>>VOID");
}