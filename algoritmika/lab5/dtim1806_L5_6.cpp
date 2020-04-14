//Demeter Tamás
//511/2
//Írjunk rekurzív algoritmust, amely kiszámítja az n-edik Fibonacci-számot. 

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