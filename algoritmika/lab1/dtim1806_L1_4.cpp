//Demeter Tamás
//511/2
/*Írjunk algoritmust, amely kiszámítja egy személy ideális testsúlyát!
Útmutatás
 S=50+0.75(M-150)+(É-20)/40,             férfiak esetén.
 S=0.9(50+0.75(M-150)+(É-20)/40),      nők esetén.
 ahol az S az ideális testsúly (kg), M a magasság (cm) és É az életkor (évek száma).*/

#include <stdio.h>

main() {
	int m, e;
	char n;
	printf("Nem? (f/n) = "); scanf_s("%c", &n);
	if ((n == 'f') | (n == 'n')) {
		printf("Magassag = "); scanf_s("%d", &m);
		printf("Eletkor = "); scanf_s("%d", &e);
		printf("\n");
		if (n == 'n') printf("Idealis testsuly: %f kg", 0.9*(50 + 0.75*(m - 150) + (e - 20) / 40));
		else printf("Idealis testsuly: %f kg", 50 + 0.75*(m - 150) + (e - 20) / 40);
	}
	else printf("Kerem adja meg helyesen a nemet");
	system("PAUSE>>VOID");
}