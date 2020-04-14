//Demeter Tamás, dtim1806, 511/2
//8. labor 7. feladat
//Egy tolvaj betört egy hentesüzletbe, ahol n áru közül válogat.
//Minden árunak ismeri a súlyát és az értékét.
//Mivel a hátizsákjába legtöbb S súly fér, szeretne úgy válogatni, hogy a nyeresége maximális legyen.
//(Ha egy áru nem fér be egészében a hátizsákba, a tolvaj nem vághat le belőle.)
//A bemenet első sora az áruk számát és a hátizsák kapacitását tartalmazza, a következő n sorban található számpárok az áruk értékét és súlyát írják le.
//A kimenet a kiválasztott áruk sorszámainak listája

#include <stdio.h>

struct aru {   //aru tulajdonsagai
	int ertek;
	int suly;
	int sorszam;
	float avg;
};

void swap(struct aru *x, struct aru *y) { //csere
	struct aru temp = *x;
	*x = *y;
	*y = temp;
}

int partition(struct aru x[50], int e, int v) { //particio(quicksorthoz)
	struct aru piv = x[v];
	int i = e - 1;
	for (int j = e; j <= v - 1; j++) {
		if (x[j].avg >= piv.avg) {  //ertek/suly szerint rendezunk novekvo sorrendbe
			i++;
			swap(&x[i], &x[j]);
		}
	}
	swap(&x[i + 1], &x[v]);
	return (i + 1);
}

void quicksort(struct aru x[50], int e, int v) { //quicksort
	if (e < v) {
		int piv = partition(x, e, v);
		quicksort(x, e, piv - 1);
		quicksort(x, piv + 1, v);
	}
}

int main() {

	FILE*f = fopen("dtim1806_L8_7.txt", "r");
	int n, s;
	struct aru v[50];
	int i;
	fscanf(f, "%d %d", &n, &s);
	for (i = 0; i < n; i++) {
		fscanf(f, "%d %d", &v[i].ertek, &v[i].suly);
		v[i].avg = v[i].ertek / v[i].suly;
		v[i].sorszam = i+1;
	}

	quicksort(v, 0, n-1);  //rendezzuk ertek/suly szerint. nezzuk hogy miket tud beletenni sorba

	for (i = 0; i < n; i++) {
		if (s >= v[i].suly) {
			printf("%d ", v[i].sorszam);
			s = s - v[i].suly;
		}
	}

	return 0;
}