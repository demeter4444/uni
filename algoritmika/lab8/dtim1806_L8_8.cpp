//Demeter Tamás, dtim1806, 511/2
//8.labor 8. feladat
//Az egyetem kapott n számítógépet, amelyeket különböző épületekbe és termekbe fognak elhelyezni úgy, hogy a számítógépek egy lineáris hálózatot alkossanak:
//minden számítógép két másikkal lesz összekötve, kivéve az elsőt és az utolsót, amelyek csak egy-egy számítógéppel lesznek összekötve.
//Beolvassuk az n számítógép x és y koordinátáit. Írjuk ki a hálózatot úgy, hogy minimális hosszúságú kábelre legyen szükség.
//A bemenet első sorában a számítógépek száma, a továbbiakban pedig soronként egy számítógép koordinátája található.
//A kimenet első sora a hálózat bejárási sorrendét, a második pedig a felhasznált kábel hosszát tartalmazza két tizedes pontossággal.

#include <stdio.h>
#include <math.h>

struct pc {  //egy gep tulajdonsagai
	int x;
	int y;
	int sorszam;
};

float dist(struct pc a, struct pc b) { //ket gep (pont) kozotti tavolsag keplete
	return (sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y)));
}

void swap(struct pc *a, struct pc *b) { //ket gep csereje
	struct pc temp = *a;
	*a = *b;
	*b = temp;
}

int partition(struct pc x[50], int e, int v,struct pc start) { //particio egy megadott gep fuggvenyeben (quicksort)
	struct pc piv = x[v];
	int i = e - 1;
	for (int j = e; j <= v - 1; j++) {
		if (dist(start, x[i]) > dist(start, x[j])) { //a startban atadott geptol valo tavolsag szerint rendezunk.
			i++;
			swap(&x[i], &x[j]);
		}
	}
	swap(&x[i + 1], &x[v]);
	return (i + 1);
}

int quicksort(struct pc x[50], int e, int v, struct pc start) { //quicksort egy megadott gep fuggvenyeben
	if (e < v) {
		int piv = partition(x, e, v, start);
		quicksort(x, e, piv - 1, start);
		quicksort(x, piv + 1, v, start);
	}
}

int main() {
	FILE*f = fopen("dtim1806_L8_8.txt", "r");
	int n, i;
	struct pc gepek[50];
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(f, "%d %d", &gepek[i].x, &gepek[i].y);
		gepek[i].sorszam = i + 1;
	}

	float maxsum = 9999.99; //lehet maxflt
	struct pc temp[50];

	for (i = 0; i < n; i++) {	//minden egyes gepet kivalasztunk kezdopontnak, majd rendezzuk a tombot ettol a geptol valo tavolsag fuggvenyeben.
		float sum = 0;

		quicksort(gepek, 0, n - 1, gepek[i]);
		for (int j = 0; j < n - 1; j++) {
			sum = sum + dist(gepek[j], gepek[j + 1]); //a kapott rendezett tombot vegigjarjuk, kiszamoljuk a halozathoz szukseges kabelt.
		}
		if (sum < maxsum) {
			maxsum = sum;
			for (int k = 0; k < n; k++) { //elmentjuk a legrovidebbet.
				temp[k] = gepek[k];
			}
		}
	}
	for (i = 0; i < n; i++) printf("%d ", temp[i].sorszam);
	printf("\n");
	printf("%f", maxsum);
	return 0;
}