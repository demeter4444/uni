//Demeter Tamás
//511/2
//Számítsuk ki, adott n és x értékekre, a következő összeget :
//S = 1 - x2 / 2!+ x4 / 4!- x6 / 6!+ ... + (-1)n x2n / (2n)!

#include <stdio.h>
#include <math.h>

//az agyam azt mondja iterativ vegigadogatas (hasonlo fibonaccihoz)
//de a szivem azt mondja rekurzio

int faktor(int x) {
	if (x == 0) return 1;
	else return x * faktor(x - 1);
}
float sum(float n, float x) {
	if (n == 0) return 1;
	else return (pow(-1, n)*pow(x, 2 * n) / faktor(2 * n)) + sum(n - 1, x);
}

main() {
	float n, x;
	printf("n = "); scanf("%f", &n);
	printf("x = "); scanf("%f", &x);
	printf("eredmeny = %f", sum(n, x));
}