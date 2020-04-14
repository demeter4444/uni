//Demeter Tamás, dtim1806, 511/2
//7. labor 4.feladat
//Legyen a következő játék: az egyik játékos (Játékos1) gondol egy 0 és 1000 közötti természetes számra.
//A másik játékosnak (Játékos2) ki kell találnia ezt a számot minél kevesebb próbálgatással.
//A titkos szám „birtokosa” (Játékos1) egy-egy találgatásra csak annyit válaszol, hogy a titkos szám kisebb vagy nagyobb mint a másik játékos (Játékos2) által feltételezett szám.
//Írjunk programot amely a fenti játékot szimulálja, úgy, hogy a számítógép a Játékos2, azaz ő találja ki a felhasználó titkos számát.

#include <stdio.h>

void game(int x[1001], int n, int e, int v,int t) { //t a talalatok szama. 
	int k = (e + v) / 2;
	if (t % 2 == 0)printf("%d ?\n", k); //valamiert mindig 2szer irat ki enelkul az if nelkul.
	char  l = getc(stdin);
	if (l == 'l') v = k;
	else if (l == 'h') e = k;
	else if (l == 'y') return;
	if ((e == v)&&(l!='y')) { //ha valami logikatlan dolog fordul elo a felhasznalo valaszaiban
		printf("Problemaba utkoztem. Kezdjuk elolrol.\n");
		game(x, n, 0, 1000, 0);
	}
	game(x, n, e, v,t+1);
}

main() {
	int n, i;
	int v[1001];
	n = 1001;
	for (i = 0; i < n; i++) v[i] = i;
	printf("h = higher, l = lower, y = found\n");
	game(v, n, 0, 1000,0);

}