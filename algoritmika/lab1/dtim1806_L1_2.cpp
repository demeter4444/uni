//Demeter Tamás
//511/2
/*Olvassunk be a billentyűzetről három egész számot. Írjuk ki őket növekvő sorrendben!*/

#include <stdio.h>

main() {
	int a,b,c;
	printf("a="); scanf_s("%d", &a);
	printf("b="); scanf_s("%d", &b);
	printf("c="); scanf_s("%d", &c);
	printf("\n");
	if ((a <= b) && (a <=c)) {
		if (b <= c) {
			printf("%d %d %d", a, b, c);
		}
		else printf("%d %d %d", a, c, b);
	}
	else if ((b <= a) && (b <= c)) {
			if (a <= c) {
				printf("%d %d %d", b, a, c);
			}
			else printf("%d %d %d", b, c, a);
		}
	
	else {
	if (a <= b) {
		printf("%d %d %d", c, a, b);
		}
	else printf("%d %d %d", c, b, a);
}
system("PAUSE>>VOID");

}