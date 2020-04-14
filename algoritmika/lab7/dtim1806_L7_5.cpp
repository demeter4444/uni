//Demeter Tamás, dtim1806, 511/2
//7. Labor, 5. feladat
//Írjunk programot amely a 4-es feladat játékát szimulálja, úgy, hogy a számítógép a Játékos1, azaz ő generál egy véletlenszerű számot amit a felhasználónak ki kell találnia.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game(int s) { //ebbe nemtudom mi kene a divide et impera legyen, de igy eleg egyszerunek tunt megoldani
	int l;
	scanf("%d", &l);
	if (l > s) {
		printf("Kisebb\n");
		game(s);
	}
	else if (l < s) {
		printf("Nagyobb\n");
		game(s);
	}
	else if (l == s) {
		printf("Talalt\n");
		return;
	}
	else { //ez az ag nem mukodik, es nem is fog a c alapveto mukodesi modja miatt. (scanf)
		printf("Invalid karakter\n");
		return;
	}
}

main() {
	time_t t;
	srand((unsigned)time(&t));
	int szam = rand() % 1000;
	printf("Talald ki a szamot!\n");
	game(szam);
}