//Demeter Tamas
//511
//01
//7. tetel R feladat
#include <stdio.h>

int x[10] = { 0,0,0,0,0,0,0,0,0,0 }; //az eredmenytomb globalis

void kiir(int x[], int n) {	//eredmenytomb kiiratasa
	for (int i = 0; i < n; i++) if (x[i] != 0) printf("%d ", x[i]);
	printf("\n");
}

void particio(int i, int n) {
	for (int j = 1; j <= n; j++) {
		x[i] = j;
		if (j < n) particio(i + 1, n - j); //ha meg valaszthatunk particiot, valasztunk
		else kiir(x, n); //kulonben kiirjuk
	}
}

int main() {
	int n;
	scanf("%d", &n);
	particio(1, n);

	return 0;
}