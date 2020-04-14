//Demeter Tamás
//511/2
/*Legyen n építőkocka, amelyek 1-től n-ig vannak címkézve.
Beolvassuk az oldalaik hosszát és a színüket.
Írjunk ki minden k kockából álló tornyot, amelyeket úgy építhetünk fel, hogy nem teszünk egymásra azonos színű kockát és oldalaik mérete (lentről felfele)csökkenő sorozatot alkotnak.
A bemenet első sora tartalmazza a kockák számát és a k értékét, majd a következő n sor mindegyikében két szám található, a következő kocka színe és oldalhossza.
A kimenet annyi sorból áll, ahány tornyot fel lehet építeni, minden sorban egy sorszám-sorozat van, ami a tornyot alkotó kockák felsorolása lentről felfelé. */

#include <stdio.h>

//a bemenetbe kicsereltem a szineket szavakrol szamokra, az egyszeruseg kedveert
//pl 1 - piros 2 - kek, ...

int n, k;
int s[50];
int h[50];
struct kocka { //egy kocka tulajdonsagai
	int szam;
	int szin;
	int hossz;
};

struct kocka v[50]; //az adott kockak
struct kocka m[50]; //a megoldastomb is kockak

void kiir() {
	int i;
	for (i = 0; i < k; i++) printf("%d ", m[i].szam+1); //+1 hogy 1-tol sorszamozzunk 0 helyett(mint a peldaban)
	printf("\n");
}

int jo(int i) {
	int helyes = 1;
	if (i > 0) {
		if (m[i - 1].szin == m[i].szin)  helyes = 0; //ha az elozo szine ugyanaz nemjo
		if (m[i - 1].hossz <= m[i].hossz) helyes = 0; //hossz -||-
		}
return helyes;
}

void back(int i) {
	int j;
	for (j = 0; j < n; j++) { 
		m[i].szam = v[j].szam;
		m[i].hossz = v[j].hossz;
		m[i].szin = v[j].szin;
		if (jo(i)==1) {
			if (i == k-1) kiir();
			else back(i + 1);
		}
	}

}

main() {
	FILE*f = fopen("dtim1806_L6_4.txt", "r");
	fscanf(f, "%d %d", &n, &k);
	int i;
	for (i = 0; i < n; i++) {
		v[i].szam = i;
		fscanf(f, "%d %d", &v[i].szin, &v[i].hossz);
	}

	back(0);
	//system("PAUSE>>VOID");
}