//Demeter Tam�s
//511/2
/*Egy t�glalap alak� kertet dr�tker�t�ssel szeretn�nk beker�teni.
Ismerj�k a kert hossz�t, sz�less�g�t, valamint a rendelkez�sre �ll� dr�t hossz�t.
Sz�m�tsuk ki mennyi dr�t marad a kert beker�t�se ut�n, illetve mennyi dr�t sz�ks�ges m�g a kert beker�t�s�hez.*/

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