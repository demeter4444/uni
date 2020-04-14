//Demeter Tam�s
//511/2
/* Egy programoz�i versenyen t�bb els�, m�sodik �s harmadik d�jat osztanak ki. Ezeknek a sz�ma x, y, z.
A szponzorokt�l kapott�rt�kt�rgyak mind k�l�nb�z� �rt�k�ek.
A bizotts�g az x + y + z nyertesnek m darab �rt�k[i] (i = 1, 2, ..., m) �rt�k� t�rgyat fog kiosztani, �gy hogy a d�jak �rt�ke cs�kken� sorozatot alkot. 
Egy versenyz� t�bb t�rgyat is kaphat.
Az els� d�jak �rt�ke legyen azonos,ugyan�gy a m�sodik d�jak �rt�ke, valamint a harmadik d�jak�.
�rjuk ki minden lehets�ges m�dj�t annak, ahogy az m t�rgy sz�toszthat� a fenti k�vetelm�nyeknek megfelel�en.
Minden t�rgyat �t kell adni.
Ha nem lehet tiszteletben tartani a d�jkioszt�s szab�lyait, �rjunk megfelel� �zenetet. */

#include <stdio.h>

int m, x, y, z, sum;
int val[100];
int d[100];
int v[100];

void ki() {  //vegigmegyunk a dijakon, 0tol xig az elsok, xtol x+yig a masodikok, x+ytol x+y+zig a harmadikok
	int i, j;
	printf("Elsok:");

	for (i = 0; i < x; i++)
		for (j = 0; j < m; j++)
			if (v[j] == i) printf(" %d ", val[j]);

	printf("\n");

	printf("Masodikok:");
	for (i = x; i < x + y; i++)
		for (j = 0; j < m; j++)
			if (v[j] == i) printf(" %d ", val[j]);

	printf("\n");

	printf("Harmadikok");
	for (i = x + y; i < sum; i++)
		for (j = 0; j < m; j++)
			if (v[j] == i) printf(" %d ", val[j]);

	printf("\n\n");
}

int jo() {
	int i;
	for (i = 1; i < sum; i++) {
		if (d[i - 1] != d[i] && i != x && i != x + y) { //a dijak ne kulonbozzenek
			return 0;
		}
	}
	if (d[x - 1] < d[x + y - 1] || d[x + y - 1] < d[t - 1]) { //legyen meg a csokkeno sorrend
		return 0;
	}
	return 1;
}

void back(int k) {	
	int i;														
	if (k == m) {												
		if (jo())
			ki();
	}
	else
		for (i = 0; i < t; i++) {							
			d[i] += val[k];								
			v[k] = i;		//megfeleltetjuk az i. dijnak a k. targyat							
			back(k + 1);									
			d[i] -= val[k];	//majd elvesszuk, hogy tovabb tudjuk iteralni a backet.							
			v[k] = 0;									
		}
}

main() {
	int i;
	FILE*f = fopen("dtim1806_L6_8.txt", "r");
	fscanf(f, "%d", &m);
	fscanf(f, "%d %d %d", &x, &y, &z);									
	sum = x + y + z;																					 
	for (i = 0; i < m; i++)
		fscanf(f, "%d", &val[i]);
	back(0);
}
