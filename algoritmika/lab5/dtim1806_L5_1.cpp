//Demeter Tamás
//511/2
//dtim1806
//Írjunk rekurzív algoritmust, amely kiír egy n természetes számot törzstényezőkre bontva!
#include <stdio.h>
void torzs(int x, int o) {
	if (x < 2)
		return;

	if (x%o == 0) {
		int db = 0;
		while (x%o == 0) {
			db++;			//esetleg a darab is lehetne parameter, de igy egyszerubb. ha nem hatvany formaba akarjuk kiirni, akkor teljesen rekurziv maradhat.
			x = x / o;
		}
		printf("%d^%d *", o, db);
		torzs(x, o + 1);
	}
	
	else {
		torzs(x, o + 1);
	}
}


main() {
	int n;
	printf("n = ");
	scanf("%d", &n);
	torzs(n, 2);
}