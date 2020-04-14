//Demeter Tamás
//511/2
/*Határozzuk meg a b sorozatban azt a pozíciót, amellyel kezdődően a b sorozatba beszúrható az a
sorozat úgy, hogy a b sorozat továbbra is növekvően rendezett maradjon.
Ha nincs ilyen pozíció, írjunk ki egy megfelelő üzenetet. */
#include <stdio.h>

int lnko(int x, int y) {
	while (x != y) {
		if (x > y) x = x - y;  //matematikai alapon meghatarozzuk, lnko segitsegevel (korben valo szamolas peldaja) erre a feladatra a kepletet
		else y = y - x;
	}
	return x;
}

main() {
	int n, k;
	printf("n= "); scanf_s("%d", &n);
	printf("k="); scanf_s("%d", &k);
	printf("minden %d . gyerek nem kap csokit", n - n / lnko(n, k)); 
	system("PAUSE>>VOID");
}