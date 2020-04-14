//Demeter Tamás
//511/2
//Írjunk rekurzív algoritmust, amely kiszámítja n természetes szám legnagyobb közös osztóját!

#include <stdio.h>

int lnko(int m, int n) {
	if ((n == 0) || (m == 0)) return 1;
	if (m % n == 0) return  n; 
	else return lnko(n, m%n);
}

main() {
	FILE*f = fopen("dtim1806_L5_4.txt", "r");
	int n;
	fscanf(f, "%d", &n);
	int* s = (int*)malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++) fscanf(f, "%d", &s[i]);

	int l = lnko(s[0], s[1]);
	for (i = 0; i < n-1; i++) {
		if (lnko(s[i], s[i + 1] != l)); //kepezzuk sorba a szamokon az lnkokat
			l = lnko(lnko(s[i], s[i + 1]), l);
	}

	printf("%d", l);
	fclose(f);
}