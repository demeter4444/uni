//Demeter Tamás
//511/2
//Számítsuk ki hány szökőév volt/lesz két különböző évszám között!

#include <stdio.h>

main() {
	int y1, y2;
	printf("elso ev = "); scanf_s("%d", &y1);
	printf("masodik ev = "); scanf_s("%d", &y2);
	int i;
	int s = 0;
	for (i = y1; i <= y2; i++) {
		if ((i % 4 == 0) && (i % 100 != 0)) s++;
		else if (i % 400 == 0) s++;
	}
	printf("%d szokoev", s);
	system("PAUSE>>VOID");
}