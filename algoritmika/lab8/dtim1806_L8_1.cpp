//Demeter Tamás, dtim1806, 511/2
//8. labor 1. feladat
//Legyen két, egész számokat tartalmazó halmaz: A = {a1, a2, ..., am} és B = {b1, b2, …, bn} (1 <= m <= n <= 100).
//Határozzuk meg a B halmaz azon X = {x1, x2, …, xm} részhalmazát, amelynek megfelelően az E = a1x1 + a2x2 + … + amxm kifejezés értéke a lehető legnagyobb.
//A bemenet szerkezete: m értéke, A elemei, n értéke, B elemei. A kimenet a maximális értéket kell tartalmazza.

#include <stdio.h>

void swap(int *x, int *y) { //csere
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int x[50], int e, int v) { //particio
	int piv = x[v];
	int i = e - 1;
	for (int j = e; j <= v - 1; j++) {
		if (x[j] <= piv) {
			i++;
			swap(&x[i], &x[j]);
		}
	}
	swap(&x[i + 1], &x[v]);
	return (i + 1);
}

void quicksort(int x[50], int e, int v) { //quicksort
	if (e < v) {
		int piv = partition(x, e, v);
		quicksort(x, e, piv - 1);
		quicksort(x, piv + 1, v);
	}
}

int main() {
	FILE*f = fopen("dtim1806_L8_1.txt", "r");
	int n,m, i, a[50],b[50];
	fscanf(f, "%d", &m);
	for (i = 0; i < m; i++)fscanf(f, "%d", &a[i]);
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++)fscanf(f, "%d", &b[i]);
	quicksort(a, 0, m - 1);
	quicksort(b, 0, n - 1); //rendezzuk a ket tombot
	int j = n - 1;
	int k = 0;
	int sum = 0;
	for (i = m - 1; i >= 0; i--) { //pozitiv elemnek nagy elemet, negativ elemnek kis elemet adunk.
		if (a[i] >= 0) {
			sum = sum + a[i] * b[j];
			j--;
		}
		else {
			sum = sum + a[i] * b[k];
			k++;
		}
	}

	printf("%d", sum);
	return 0;
}