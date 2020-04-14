//Demeter Tamás, dtim1806, 511/2
//7.labor, 2.feladat
//Legyen n természetes szám. Határozzuk meg a számok legkisebb és legnagyobb elemét egyidőben.

#include <stdio.h>

void minmax(int x[50], int n, int e, int v, int *max, int *min) { //a min, max parametereken keresztul kapjuk vissza a megoldast. ezt cimszerint adjuk at
	if (e != v) { 
		int k = (e + v) / 2;
		if (x[k] < *min) *min = x[k];
		if (x[k] > *max) *max = x[k];
		minmax(x, n, e, k, max, min);
		minmax(x, n, k + 1, v, max, min);
	}
	else { // ez kell ,ha a keresett ertek a tomb egyik szelen van
		if (x[e] < *min) *min = x[e];
		if (x[e] > *max) *max = x[e];
	}
}

main() {
	FILE*f = fopen("dtim1806_L7_2.txt", "r");
	int n;
	fscanf(f, "%d", &n);
	int i;
	int v[50];
	for (i = 0; i < n; i++)fscanf(f, "%d", &v[i]);
	int min = v[0];
	int max = v[0];
	minmax(v, n, 0, n - 1,&max,&min);
	printf("Max = %d\nMin = %d", max, min);

}