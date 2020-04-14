//Demeter Tamás,dtim1806,511/2
//8. labor 3. feladat
//Adott n zeneszámot tartalmazó állomány hossza.
//Ezeket az állományokat ugyanazon a mágnes szalagon szeretnénk tárolni.
//Állapítsuk meg az állományok optimális elrendezését a szalagon ahhoz, hogy az átlagos elérési idő a lehető legkisebb legyen.
//A bemenet első sora a zeneszámok számát és azok hosszát tartalmazza. A kimenet az állományok optimális elrendezését tartalmazza. 

#include <stdio.h>

struct zene {  //egy zeneszam tulajdonsagai
	int hossz;
	int sorszam;
};

void swap(struct zene *x, struct zene *y) { //ket zeneszam csereje
	struct zene temp = *x;
	*x = *y;
	*y = temp;
}

int partition(struct zene x[50], int e, int v) { //particio(quicksorthoz)
	struct zene piv = x[v];
	int i = e - 1;
	for (int j = e; j <= v - 1; j++) {
		if (x[j].hossz <= piv.hossz) {
			i++;
			swap(&x[i], &x[j]);
		}
	}
	swap(&x[i + 1], &x[v]);
	return (i + 1);
}

void quicksort(struct zene x[50], int e, int v) { //quicksort
	if (e < v) {
		int piv = partition(x, e, v);
		quicksort(x, e, piv - 1);
		quicksort(x, piv + 1, v);
	}
}

main() {
	FILE*f = fopen("dtim1806_L8_3.txt","r");
	int n;

	struct zene v[50];
	fscanf(f, "%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		fscanf(f, "%d", &v[i].hossz); //rendezzuk hossz szerint
		v[i].sorszam = i;
	}

	quicksort(v, 0, n - 1);

	for (i = 0; i < n; i++) printf("%d ", v[i].sorszam+1);


}