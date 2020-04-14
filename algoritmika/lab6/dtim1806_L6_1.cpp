//Demeter Tam�s
//511/2
//�rjunk programot, mely ki�rja az {1, 2, �, n} halmaz minden permut�ci�j�t!

#include <stdio.h>

int n;
int x[20];

void kiir(int i) { //egy permutacio kiirasa
	int j;
	for (j = 1; j <= i; j++) printf("%d ", x[j]);
	printf("\n");
}

int jo(int i) {
	int j;
	int k = 1;
	for (j = i-1; j >= 1; j--) {
		if (x[j] == x[i]) k = 0; //a permutacio akkor jo, ha ugyanaz az elem nem fordul elo tobbszor
	}
	return k;
}

void back(int i) {
	int j;
	for (j = 1; j <= n; j++) { 
		x[i] = j;
		if (jo(i) == 1) {
			if (i == n) kiir(i);
			else back(i + 1);
		}
	}
}


main() {
	printf("n = ");
	scanf("%d", &n);
	back(1);
}