//Demeter Tamás
//511/2
/*Egy utazóügynök házról házra jár az áruival.
A cégnek n féle áruja van; minden áru súlyát és árát ismerjük.
Tudva azt, hogy az ügynök hátizsákjába legtöbb S súlyú árut lehet becsomagolni, írjuk ki azokat az árukat, amelyeket az ügynök kiválaszt az n áru közül tudva, hogy az áruk értékének legkevesebb Összeg-gel kell egyenlőnek lennie.
A bemenet első sorában az árucikkek száma, a minimális összeg és a hátizsák kapacitása van feltüntetve.
A következő n sorban az egyes árucikkek súly-érték-párosa található.
A kimenet minden sora egy árucikk-sorszámokból álló sorozatot kell hogy tartalmazzon, melyek mindegyike megfelel az előírtaknak*/

#include <stdio.h>


int n, min, cap;
struct termek { //egy termek tulajdonsagai
	int szam;
	int suly;
	int ar;
};

struct termek v[50]; //az adott termekek
struct termek m[50]; //a megoldastomb is termekek

void kiir(int i) {
	int j;
	for (j = 0; j <= i; j++) printf("%d ", m[j].szam+1); //+1 hogy 1-tol sorszamozzunk 0 helyett(mint a peldaban)
	printf("\n");
}

int jo(int i) {
	int helyes = 1;
	int j;
	int sum = 0;
	int val = 0;
	for (j = 0; j <= i; j++) { //novekvo sorrend, minden termek csak 1szer
		sum = sum + m[j].suly;
		val = val + m[j].ar;
	}
	for (j = 1; j <= i; j++) {
		if (m[j - 1].szam >= m[j].szam) helyes = 0; 
	}
	if (sum > cap) helyes = 0; //ne legyen nehezebb a kapacitasnal
	if (val < min) helyes = 0; //ne legyen kevesebb a minimalis erteknel
	return helyes;
}

void back(int i) {
	int j;
	int val = 0;
	for (j = 0; j < n; j++) {
		m[i].szam = v[j].szam;
		m[i].suly = v[j].suly;
		m[i].ar = v[j].ar;
			if (i < n) {
			if (jo(i)) kiir(i);
			back(i + 1);
		}
		
	}

}

main() {
	FILE*f = fopen("dtim1806_L6_6.txt", "r");
	fscanf(f, "%d %d %d", &n, &min, &cap);
	int i;
	for (i = 0; i < n; i++) {
		v[i].szam = i;
		fscanf(f, "%d %d", &v[i].suly, &v[i].ar);
	}

	back(0);
	//system("PAUSE>>VOID");
}