//Demeter Tam�s
//511/2
//Sz�m�tsuk ki egy h�romsz�g ter�let�t, ha ismerj�k oldalainak a hossz�t!

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