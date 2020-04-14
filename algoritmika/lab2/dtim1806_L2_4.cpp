//Demeter Tamás
//511/2
//Írjunk algoritmust, amely megadja a Fibonacci-sorozat egy adott számnál kisebb elemeinek számát!

#include <stdio.h>

main() {
	int f1, f2, f3, n;
	printf("n= "); scanf_s("%d", &n);
	f1 = 0;
	f2 = 1;
	f3 = f1 + f2;
	int i;
	int db = 1;								//alapalgoritmus, nincs sok magyaraznivalo.
	while(f3 < n) {							//db-t 1-el inicializaljuk, mert elvileg a 0 is tagja a sorozatnak.
		db++;
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}
	printf("A(z) %d -nel kisebb fibonacci-sorozat tagok szama: %d", n, db);
	system("PAUSE>>VOID");
}