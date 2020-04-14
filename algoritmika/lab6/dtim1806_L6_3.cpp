//Demeter Tamás
//511/2
/*Adva van egy n db egész számot tartalmazó sorozat (2 <= n < 10).
Helyezzünk az adott számok közé n – 1 aritmetikai műveleti jelt (+, –, *, /), úgy, hogy a kifejezés értéke legyen egyenlő egy adott K számmal!
Amennyiben lehetetlen megoldást találni, írjunk ki megfelelő üzenetet!
A kifejezés értéke minden lépésben legyen egész szám!
A műveleteket nem a matematikából ismert operátorprecedencia szerint végezzük, hanem megjelenésük sorrendjében.*/

#include <stdio.h>
int n;
int k;
int x[50];
char m[49];
const char v[4] = { '+','-','*','/' };
int db = 0;

//a kiir fuggvenyben ellenorizzuk, hogy helyes e a muveletsor eredmenye.
void kiir() {
	int i;
	int j = 0;
	int s = x[0];

	for (i = 1; i < n; i++) {
		switch (m[j]){
			case '+':
				s = s + x[i];
				j++;
				break;
			case '-':
				s = s - x[i];
				j++;
				break;
			case '*':
				s = s * x[i];
				j++;
				break;
			case '/':
				s = s / x[i];
				j++;
				break;

		}
	}
	if (s == k) {
		for (i = 0; i < n; i++) {
			printf("%d %c ", x[i], m[i]);
		}
		printf("\n");
		db++;
	}
}

//backtrack
void back(int i) {
	int j;
	for (j = 0; j < 4; j++) {
		m[i] = v[j];
		if (i == n - 2) kiir();
		else back(i + 1);
	}
}

 main() {
	FILE*f = fopen("dtim1806_L6_3.txt", "r");
	fscanf(f, "%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		fscanf(f, "%d", &x[i]);
	}
	fscanf(f, "%d", &k);
	back(0);
	if (db == 0) printf("Nincs megoldas");
}