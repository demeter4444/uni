//Demeter Tamas
//511
//01
//7. tetel R feladat
#include <stdio.h>

int x[10] = { 0,0,0,0,0,0,0,0,0,0 };

void kiir(int x[], int n) {
	for (int i = 0; i < n; i++) 
		if (x[i] != 0) printf("%d ", x[i]);
	printf("\n");
}

void particio(int i, int n) {
	for (int j = 1; j < n; j++) {
		x[i] = j;
		if (n-j>=0) particio(i + 1, n - j);
		else kiir(x, n);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	particio(0, n);

	system("PAUSE>>VOID");
	scanf("asd");
	return 0;
}