//Demeter Tamás
//511/2
//Írjatok fel egy számot négyzetszámok összegeként.
#include <stdio.h>
#include <math.h>

void sqrsum() {
	int a; //az adott szam
	scanf_s("%d", &a);
	int r = sqrt(a); //ennek gyoke, kerekitve
	printf("%d \n", r);
	int s = 0;  
	while (s < a) {
		if ((r*r + s) < a) {
			printf(" %d +", (int)(r*r)); //elkezdunk szamolni a szamhoz legkozelebb eso negyzetszamtol
			s = s + r * r;				//ahanyszor jo egy szam, annyiszor osszeadjuk, kulonben csokkentunk.
		}
		else if (r*r + s == a) {
			printf(" %d", (int)(r*r));
			s = s + r * r;
		}
		else if (r*r + s > a)  r--;
	}
		printf("\n = %d", s);
		system("PAUSE>>VOID");
}
main() {
	sqrsum();
}