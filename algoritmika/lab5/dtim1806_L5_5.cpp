//Demeter Tam�s
//511/2
//�rjunk rekurz�v algoritmust, amely kisz�m�tja az Ackermann-f�ggv�ny �rt�k�t adott m �s n �rt�kekre:

//nem igazan hallottam eddig errol a fuggvenyrol, de eleg easynek tunik

#include <stdio.h>

int ack(int m, int n) {
	if (m == 0) return n + 1;
	if (n == 0) return ack(m - 1, 1);
	else return ack(m - 1, ack(m, n - 1));
}

main() {
	int m, n;
	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	printf("%d", ack(m, n));
}