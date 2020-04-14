//Demeter Tamás,dtim1806,511/2
//8.labor 6. feladat
//Adva van n + 1 cipősdoboz és n pár cipő, amelyek meg vannak számozva 1-től n-ig.
//Az n pár cipő n dobozban található, a dobozok közül egy üres.
//Mivel a cipők nincsenek a megfelelő dobozban, el kell rendezni ezeket úgy, hogy minden cipő a saját dobozába kerüljön.
//Munka közben csak egy pár cipőt szabad kivenni a dobozból, amelyben található, és azonnal be kell tenni az üres dobozba.
//Állapítsuk meg a költöztetések sorozatát minimális számú művelettel. A bemenet első sora a cipők számát tartalmazza. Ezutám következi a jelenlegi elrendezés.
//A kimenet a rendezéshez szükséges minimális lépésszámot kell hogy tartalmazza.

#include <stdio.h>

void swap(int *a, int *b) { //csere
	int aux = *a;
	*a = *b;
	*b = aux;
}

main() {
	FILE*f = fopen("dtim1806_L8_6.txt", "r");
	int n, v[50], w[50];	//v tomb az a vegso tomb, a w az inicialis (1,2,...,0)
	fscanf(f, "%d", &n);
	int i, j;
	for (i = 0; i < n; i++) fscanf(f, "%d", &v[i]);
	for (i = 0; i < n; i++) w[i] = i+1;
	int ures = 0;
	int sum = 0;

	int rendezett = 0;
	while (!rendezett) {
		rendezett = 1;
		for (i = 0; i < n; i++) {
			if (v[i] != w[i]) rendezett = 0;  //megkeressuk az elso elemet ami nincs a helyen
			break;
		}

		if (rendezett) break; //ha minden a helyen van akkor vege
		
		for (j = 0; j < n; j++) {
			if (w[j] == v[i]) break; //megkeressuk azt a poziciot, ahova a talalt elemet be kell tenni
		}



		if (w[j] == 0) { //ha a kapott pozicio ures, betesszuk a cipot
			swap(&w[i], &w[j]);
			sum++;
		}
		else {  //ha foglalt, kiuritjuk, s utana tesszuk at.
			swap(&w[j], &ures);
			swap(&w[j], &w[i]);
			sum += 2;
		}


	}

	printf("%d", sum);
}
