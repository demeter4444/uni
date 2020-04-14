//Demeter Tamás
//511/2
//Írjunk rekurzív algoritmust, amely ellenőrzi, hogy egy beolvasott szám tökéletes szám - e(egyenlő - e a nála kisebb osztóinak összegével)!

#include <stdio.h>
#include <math.h>

int rek(int*p, int n, int x, int i) {
	if (i > n) return 0;
	else return p[i] * pow(x, i) + rek(p, n, x, i + 1); //a rekurzio parameterei a polinom,ennek fokszama,a kert pont,es az aktualis fokszam(i).
}

main() {
	FILE*f = fopen("dtim1806_L5_3.txt", "r");
	int n;
	fscanf(f, "%d", &n);
	int i;
	int* p = (int*)malloc(n * sizeof(int));
	for (i = n; i >= 0; i--)fscanf(f, "%d", &p[i]);
	int x;
	fscanf(f, "%d", &x);
	printf("%d", rek(p, n, x, 0));
	fclose(f);
}
