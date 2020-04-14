//Demeter Tamás
//511/2
/*Egy téglalap alakú kertet drótkerítéssel szeretnénk bekeríteni.
Ismerjük a kert hosszát, szélességét, valamint a rendelkezésre álló drót hosszát.
Számítsuk ki mennyi drót marad a kert bekerítése után, illetve mennyi drót szükséges még a kert bekerítéséhez.*/

#include <stdio.h>

main() {
	int a, b, h;
	printf("hossz= "); scanf_s("%d", &a);
	printf("szelesseg= "); scanf_s("%d", &b);
	printf("drothossz= "); scanf_s("%d", &h);
	printf("\n");
	int k = 2 * a + 2 * b;
	if (k > h) printf("Meg szukseges %d egyseg drot", k - h);
	else if (k < h) printf("Marad %d egyseg drot", h - k);
	else printf("Pontosan eleg drot van");
	system("PAUSE>>VOID");
}