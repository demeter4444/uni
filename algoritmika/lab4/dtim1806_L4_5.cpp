//Demeter Tam�s
//511
//Ismerj�k k�t sz�m pr�msz�m oszt�it. Hat�rozzuk meg a k�t sz�m legkisebb k�z�s t�bbsz�r�s�nek pr�msz�m oszt�it! (A k�t sz�mot nem ismerj�k, csup�n a prim oszt�ikat)

#include <stdio.h>

main() {
	FILE*f;
	f = fopen("dtim1806_L4_5.txt", "r");
	int n=0;
	int v[200];
	v[0] = -1;
	int i,x;
	//fajlvegeig beolvasunk mindent, s osszehasonlitjuk minden eddigi elemmel. ha mar volt, hagyjuk, ha nem kiiratjuk. (nem kerte a feladat a novekvo sorrendet vagy tomb felepiteset)
	while (!feof(f)) {
		int van = 0;
		fscanf(f, "%d", &x);
		for (i = 0; i <= n; i++) {
			if (v[i] == x) {
				van = 1;
				break;
			}
		}
		if (van == 0) {
			v[n] = x;
			n++;
		}

	}
	for (i = 0; i < n; i++) printf("%d ", v[i]);
	fclose(f);
}