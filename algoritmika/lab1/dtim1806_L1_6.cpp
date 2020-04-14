//Demeter Tamás
//511/2
//Számítsuk ki egy háromszög területét, ha ismerjük oldalainak a hosszát!

#include <stdio.h>
#include <math.h>

main() {
	float a, b, c;
	printf("a="); scanf_s("%f", &a);
	printf("b="); scanf_s("%f", &b);
	printf("c="); scanf_s("%f", &c);
	float p = (a + b + c) / 2;
	printf("\n A haromszog terulete: %f", sqrt(p*(p - a)*(p - c)*(p - b)));
	system("PAUSE>>VOID");
}