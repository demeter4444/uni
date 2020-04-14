//Demeter Tamás, dtim1806, 511/2
//7. labor, 1. feladat
//Legyen n természetes szám, állapítsuk meg a számok összegét!

#include <stdio.h>

int sum(int x[50], int n, int e, int v) {
	int k = (e + v) / 2;
	if (e == v) return x[e]; //ha egy elemunk van, az az osszeg
	else return sum(x, n, e, k) + sum(x, n, k + 1, v); //kulonben felbontjuk
}

main() {
	FILE* f = fopen("dtim1806_L7_1.txt", "r");
	int n;
	fscanf(f, "%d", &n);
	int i;
	int v[50];
	for (i = 0; i < n; i++) fscanf(f, "%d", &v[i]);
	printf("%d", sum(v, n, 0, n-1));
}