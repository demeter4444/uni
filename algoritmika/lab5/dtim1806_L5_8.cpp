//Demeter Tam�s
//511/2
//�rjunk rekurz�v algoritmust, amely gener�lja egy adott n sz�m minden part�ci�j�t. Azok k�z�l a part�ci�k k�z�l, amelyek csak a tagok sorrendj�ben k�l�nb�znek, csak egyet kell ki�rnunk.

#include <stdio.h>

int n;
int p[50]; //globalis valtozok, mert ez megkonnyiti a feladatot

void ki(int i) {
	for (int j = 1; j <= i; j++)	//alprogram, amely egy helyes particiot kiir
		printf("%d ", p[j]);
	printf("\n");
}

void part(int i, int n) {

	for (int j = 1; j <= n; j++) {
		if (j >= p[i - 1]) {		//a particiok generalasakor mindig cserelodik az aktualis szam
			p[i] = j;				//ez mar pretty much backtrack 
			if (j == n) ki(i);
			else part(i + 1, n - j);	
		}
	}
}

int main() {
	printf("n = ");
	scanf("%d", &n);
	p[0] = 0;
	part(1, n);
}