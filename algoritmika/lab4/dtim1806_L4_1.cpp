//Demeter Tamás
//511/2
//Adott egy programozási verseny eredmény-listája, valamint az a legkisebb pontszám, amellyel be lehet nevezni a következő fordulóra. Hány százalékot képez a következő fordulóra beiratkozók száma?

#include <stdio.h>

main() {
	FILE*f;
	f = fopen("dtim1806_L4_1.txt", "r");
	int v[50];
	int n, i, am;
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++) fscanf(f, "%d", &v[i]);
	fscanf(f, "%d", &am);
	int db = 0;
	for (i = 0; i < n; i++) {
		if (v[i] >= am) db++;
	}
	printf("Kovetkezo fordulora beiratkozottak ennyi szazalekot jelentenek: %d", (100 * db) / n);	//megszamoljuk az atmenok darabszamat, majd a szazalekot harmasszabally kepletevel megadjuk
	fclose(f);
	system("PAUSE>>VOID");
}