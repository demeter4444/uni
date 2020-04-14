//Demeter Tamás
//511/2
//Írjunk algoritmust az ax2 + bx + c = 0 valós együtthatójú egyenlet megoldására!

#include <stdio.h>
#include <math.h>

main() {
	float a, b, c;
	printf("a= "); scanf_s("%f", &a);
	printf("b= "); scanf_s("%f", &b);
	printf("c= "); scanf_s("%f", &c);
	printf("A %fx^2 + %fx + %f egyenlet megoldasai: \n",a,b,c);
    float d = (b * b) - (4 * a * c);
	if (d == 0) {
		printf("x1 = x2 = %f", -b / (2 * a));
	}
	else if (d > 0) {
		printf("x1 = %f \n", (-b + sqrt(d)) / (2 * a));
		printf("x1 = %f", (-b - sqrt(d)) / (2 * a));
	}
	else {
		printf("x1 = %f + i* %f \n", -b / (2 * a), sqrt(abs(d)) / (2 * a));
		printf("x2 = %f - i* %f", -b / (2 * a), -sqrt(abs(d)) / (2 * a));
	}
	
	system("PAUSE>>VOID");

} 