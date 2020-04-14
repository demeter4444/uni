//Demeter Tamás
//511/2
//dtim1806
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main() {
	time_t t;
	srand((unsigned)time(&t));
	FILE *f;
	int n;
	char nev[10][10];
	f = fopen("input_L2.txt", "r");
	if (!f) printf("Hiba : Fajlmegnyitas sikertelen");
	fscanf(f, "%d\n",&n);
	fscanf(f, "%s\n%s\n%s\n%s\n%s", &nev[0], &nev[1], &nev[2], &nev[3], &nev[4]);
	fclose(f);
	f = fopen("output_L2.txt", "w");
	int a[10][10];
	int i, j;
	int s = 1;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = s;
			s++;
			fprintf(f, "%d ", a[i][j]);
		}
		fprintf(f,"\n");
	}
	fprintf(f,"\n \n");

		//
	int k = 0;
	i = 0;
	j = 0;
	int dir = 1;
		//1 jobb
		//2 le
		//3 bal
		//4 fel
	int c = 0;
	while (k < n*n) {
		
		if ((dir == 1) && (j != n - c -1)) {
			fprintf(f,"%d ", a[i][j]);
			j++;
			k++;
		}
		else if ((dir == 2) && (i != n - c -1)) {
			fprintf(f,"%d ", a[i][j]);
			i++;
			k++;
		}
		else if ((dir == 3) && (j != c)) {
			fprintf(f,"%d ", a[i][j]);
			j--;
			k++;
		}
		else if ((dir == 4) && (i != c)) {
			fprintf(f,"%d ", a[i][j]);
			i--;
			k++;
		}
		else if ((j == n - c - 1) && (i==c)) {
			dir = 2;
		}
		else if ((i == n - c - 1) && (j==n-c-1)) {
			dir = 3;
		
		}
		else if ((j == c) && (i == n-c-1)){
			dir = 4;
			
		}
		else if ((i == c) && (j == c)) {
			dir = 1;
			i++;
			j++;
			c++;
			
		}
		if ((k == (n*n) - 1) && (n%2 != 0)) {
			fprintf(f,"%d ", a[n / 2][n / 2]);
			break;
		}
	
	}
	fprintf(f, "\n\n");

			
	
		//

	fprintf(f, "\t   %s %s %s %s %s\n", nev[0], nev[1], nev[2], nev[3], nev[4]);
	int d1, d2;
	for (j = 1; j <= n*5; j++) {
		fprintf(f,"%d. kor ", j);
		for (i = 1; i <= n; i++) {
			d1 = rand() % 6 + 1;
			d2 = rand() % 6 + 1;
			if ((j-i)%n==0) {
				fprintf(f, "   -  ");
				continue;
			}
			fprintf(f, "(%d,%d) ", d1, d2);
			if (d1+d2 == 12) {
				break;
			}
		}
		if (d1+d2 == 12) {
			fprintf(f, "\n\nA nyertes %s \nA jatek a %d. korben ert veget.", nev[i-1], j);
			break;
		}
		fprintf(f, "\n");
	}
	if (j > n * 5) fprintf(f,"\n\n Mindenki nyert");
	fclose(f);
	return 0;
}