//Demeter Tamás
//511/2
//Írjunk rekurzív algoritmust, amely ellenőrzi, hogy egy beolvasott szám tökéletes szám-e (egyenlő-e a nála kisebb osztóinak összegével)!

#include <stdio.h>
#include <stdbool.h>

bool tok(int n, int o, int s) { //n a szam, o az aktualis oszto, s az aktualis osszeg
	if (s == n) return true; //megallunk ha tokeletes
	else if (o > n / 2) return false; //vagy ha mar biztos nem lehet az
	else if (n%o == 0) return tok(n, o + 1, s + o); //s-t csak osztok eseten noveljuk
	else return tok(n, o + 1, s);
	
}

main() {
	int n;
	printf("n = ");
	scanf("%d", &n);
	if (tok(n, 1, 0)) printf("tokeletes");
	else printf("nem tokeletes");

}