//Demeter Tamas
//511/2
//dtim1806
//8. tetel 3. feladat

#include <stdio.h>

int main() {
	int a, b, k,temp;
	printf("a ="); scanf("%d", &a);
	printf("\nb ="); scanf("%d", &b);
	printf("\nk ="); scanf("%d", &k);
	printf("\nEzen szamok binaris alakja tartalmas %d egyest %d es %d kozott:\n", k, a, b);
	int i;
	for (i = a + 1; i < b; i++) {
		temp = i;
		int db = 0;
		//ez a binarisba alakito algoritmusnak az elso negyede. csak siman megszamoljuk hanyszor oszthato 2vel ugy hogy 1 legyen a maradek.
		while (temp != 0) {
			if (temp % 2 == 1) db++;
			temp = temp / 2;
		}

		if (db == k) printf("%d ", i);

	}
	//system("PAUSE>>VOID");
	return 0;
}