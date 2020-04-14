//Demeter Tamás, dtim1806, 511/2
//7. labor 7. feladat
//files -> lab7-6

#include <stdio.h>
//sajnos nem mukodik, de legalabb megprobaltam.
void feloszt(int a[50][50], int n, int xe,int ye, int xv,int yv, int qo) { //xe,ye az "eleje" pont koordinatai (bal felso sarok), xv, yv a jobb also. qo az aktualis negyed
	int xk1 = (xe + xv) / 2;
	int yk1 = (ye + yv) / 2;
	int xk2 = xk1;
	int yk2 = yk1 + 1;
	int xk3 = xk1 + 1;
	int yk3 = yk1;
	int xk4 = xk1 + 1;
	int yk4 = yk1 + 1;
	// kiszamoljuk a 4 kozeppontot
	a[xk1][yk1] = 1;
	a[xk2][yk2] = 1;
	a[xk3][yk3] = 1;
	a[xk4][yk4] = 1;
	//befedjuk oket
	switch (qo) {
	case 1: a[xk1][yk1] = 0;
		break;
	case 2: a[xk2][yk2] = 0;
		break;
	case 3: a[xk3][yk3] = 0;
		break;
	case 4: a[xk4][yk4] = 0;
	//az aktualis negyeded kihagyjuk a befedesbol
	}
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	//kiiratjuk minden lepesben, mit fedtunk le
	}
	printf("\n");
	if (n == 2) return; //ha 2x2-es akkor vege

	feloszt(a, n/2, xe, ye, xk1, yk1, 1);
	feloszt(a, n/2, xe, ye+yk1, xk1, yk1+yk1, 2);
	feloszt(a, n/2, xe+xk1, ye, xk1+xk1, yk1, 3);
	feloszt(a, n/2, xk4, yk4, xk4+xk4, yk4+yk4, 4);
	//szerintem itt a baj, a koordinatak kepletevel, de sehogy se jottem ra.
}

main() {
	int n = 8; //itt inicializaltam az adatokat
	int m = 8;
	int i, j;
	int a[50][50];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}
	int xo = 2;
	int yo = 5;
	a[xo][yo] = -1;
	int qo = 2; //ezt ki lehet szamolni, de most nem ezen volt a lenyeg
	feloszt(a, n, 0, 0, n - 1, n - 1, qo);
}