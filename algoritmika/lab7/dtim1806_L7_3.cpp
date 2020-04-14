//Demeter Tamás, dtim1806, 511/2
//7. labor, 3. feladat
//Adott egy sorozat. Tudva, hogy a sorozat nem rendezett, állapítsunk meg minden olyan helyet, ahol egy adott érték áll.

#include <stdio.h>

void pos(int x[50], int n, int e, int v, int t) { // t a keresendo elem
	// bontogatjuk reszsorozatokra, a kozepso elemeket nezzuk
	if (e != v) {
		int k = (e + v) / 2;
		if (x[k] == t) printf("%d ", k+1);
		pos(x, n, e, k, t);
		pos(x, n, k + 1, v, t);
	}
}

main() {
	FILE*f = fopen("dtim1806_L7_3.txt", "r");
	int n, k, i;
	int v[50];
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++) fscanf(f, "%d", &v[i]);
	fscanf(f, "%d", &k);
	pos(v, n, 0, n - 1, k);
}