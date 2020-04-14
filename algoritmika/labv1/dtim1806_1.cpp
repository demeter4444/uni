//Demeter Tamas
//511/2
//dtim1806
//8.tetel 1. feladat

#include <stdio.h>
//ezt eleg nehez lenne legeneralni, ugyhogy vegigmegyunk forral s megnezzuk mindet.
int main() {
	int i, c, a, s;
	printf("1000nel kisebb szamok, melyek egyenlok szamjegyei kobeinek osszegevel:\n");

	for (i = 1; i < 1000; i++) {
		a = i;
		s = 0;
		while (a != 0) {
			c = a % 10;
			s = (c*c*c) + s;
			a = a / 10;
		}
		if (s == i) printf("%d ", i);
	}

	//system("PAUSE>>VOID");
	return 0;
}