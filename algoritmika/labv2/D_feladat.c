//Demeter Tamas
//511/2
//dtim1806
//7.tetel D feladat

#include <stdio.h>

void binkeres(int e, int v) {
	int k = (e + v) / 2;
	printf("%d ? (l=lower, h=higher, y=yes) \n", k);
	char c = 'a';
	char c = getc(stdin);
	if (c == 'y') return;
	if (c == 'h') binkeres(k + 1, v);
	else if (c == 'l') binkeres(e, k - 1);
	else return;
}


int main() {
	binkeres(0, 1000); //vegzunk egy binaris keresest 1000 elemre, minden lepesbe megkerdezzuk hogy megtalaltuk-e az elemet, vagy ha kisebb/nagyobb.
	return 0;
}