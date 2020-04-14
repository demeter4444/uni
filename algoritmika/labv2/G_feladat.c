//Demeter Tamas
//511/2
//dtim1806
//7. tetel G feladat

#include <stdio.h>

struct ido { //egy idopont ket eleme
	int eleje;
	int vege;
};

void swap(struct ido *a, struct ido *b) { //csere
	struct ido temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	struct ido idopontok[50];
	FILE*f = fopen("be.txt", "r");
	int n;
	fscanf(f, "%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		fscanf(f, "%d %d", &idopontok[i].eleje, &idopontok[i].vege);
	}

	/*for (i = 0; i < n; i++) {
		printf("%d %d \n", idopontok[i].eleje, idopontok[i].vege);
	}*/

	int j;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (idopontok[i].vege > idopontok[j].vege) swap(&idopontok[i], &idopontok[j]); //rendezzuk az idopontokat a vegso ido szerint novekvobe
		}
	}

	/*for (i = 0; i < n; i++) {
		printf("%d %d \n", idopontok[i].eleje, idopontok[i].vege);
	}*/

	int megoldas[50];
	int k = 0;
	megoldas[0] = 0;
	for (i = 1; i < n; i++) {
		if (idopontok[i].eleje > idopontok[k].vege) { //vegigmegyunk, s beillesszuk a lehetseges idopontokat
			k++;
			megoldas[k] = i;
		}
	}

	for (i = 0; i < k; i++) printf("%d ", megoldas[i]);

	scanf("asd");
}