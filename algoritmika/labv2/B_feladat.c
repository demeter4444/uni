//Demeter Tamas
//511/2
//dtim1806
//7.tetel B feladat

#include <stdio.h>
#include <stdlib.h>


int keres(int i, int j, int a[50][50], int m, int n) { //alprogram amely egy 1eshez tartozo minden 1est megszamol es kicserel -1re
	a[i][j] = -1;
	if ((i < m) && (j < n)) {
		if (a[i - 1][j] == 1) {
			return 1 + keres(i - 1, j, a, m, n);
		}
		if (a[i + 1][j] == 1) {
			return 1 + keres(i + 1, j, a, m, n);
		}

		if (a[i][j + 1] == 1) {
			return 1 + keres(i, j + 1, a, m, n);
		}

		if (a[i][j - 1] == 1) {
			return 1 + keres(i, j - 1, a, m, n);
		}
	}

	return 1;

}

int main()
{
	int a[50][50];
	int n;
	int m;
	FILE*f = fopen("harmadik.txt", "r");
	fscanf(f, "%d %d", &m, &n);
	int i;
	int j;
	for (i = 0; i<m; i++) {
		for (j = 0; j<n; j++) {
			fscanf(f, "%d", &a[i][j]);
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	int indexeki[50];
	int indexeky[50];
	int sum[50];
	int k = 0;

	i = 0;
	while (i < m) {
		j = 0;
		while (j < n) {
			if (a[i][j] == 1) {
				indexeki[k] = i;
				indexeky[k] = j;
				sum[k] = keres(i, j, a, m, n); //bejarjuk a matrixot, ahol talalunk 1est hasznaljuk az alprogramot.
				k++;
			}
			j++;
		}
		i++;
	}

	printf("\n");
	for (i = 0; i < k; i++)printf("%d. targy x,y koordinataja es merete: %d %d %d \n",i, indexeki[i], indexeky[i], sum[i]);



	scanf("\n");
	return 0;
}
