//Demeter Tamás		12 24   36 24  36 12
//511/2
/**/


#include <stdio.h>

main() {
	int a, b;
	printf("a= "); scanf_s("%d", &a);
	printf("b= "); scanf_s("%d", &b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("\na= %d \n", a);
	printf("b= %d", b);
	system("PAUSE>>VOID");
}