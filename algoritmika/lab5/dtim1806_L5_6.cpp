//Demeter Tam�s
//511/2
//�rjunk rekurz�v algoritmust, amely kisz�m�tja az n-edik Fibonacci-sz�mot. 

#include <stdio.h>

int fibo(int n) {
	if (n <= 1) return n;
	return fibo(n - 1) + fibo(n - 2);
}

main() {
	printf("n = ");
	int n;
	scanf("%d", &n);
	printf("%d", fibo(n));
}

//ennel atlathatobb programot eletemben nem irtam 