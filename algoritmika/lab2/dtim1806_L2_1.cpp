//Demeter Tamás
//511/2
/*Írjunk algoritmust, amely megkeresi és kiírja az első n tökéletes számot! 
Egy szám tökéletes, ha egyenlő a nála kisebb osztóinak összegével */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool tokeletes(long int x) {
	long int s = -x;
	long int i;
	for (i = 1; i <= (long int)(sqrt(x)); i++) {  //fuggveny ami lecsekkolja egy szam tokeletesseget (gyokig,parban szamolva)
		if (x % i == 0) s += i + x/i;
	}
	if (s == x) return 1;
	else return 0;
}

main() {
	long int n;
	printf("n = "); scanf_s("%d", &n);
	printf("Az elso %d tokeletes szam: \n", n);
	long int i = 6;
	long int db = 0;
	while (db < n) {				
		if (tokeletes(i)) {
			db++;				//elindulunk az elso tokeletes szamtol, es nezzuk mindet n-ig egy darabszamlaloval.
			printf("%d ", i);   //4 folott mar nem mukodik a klasszikus megoldassal, mert hatalmas szamok lepnek fel.
		}
		i++;
	}
	system("PAUSE>>VOID");
}