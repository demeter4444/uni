//Demeter Tamás
//511/2
/*Határozzuk meg a b sorozatban azt a pozíciót, amellyel kezdődően a b sorozatba beszúrható az a
sorozat úgy, hogy a b sorozat továbbra is növekvően rendezett maradjon.
Ha nincs ilyen pozíció, írjunk ki egy megfelelő üzenetet. */
#include <stdio.h>

main() {
	int m = 5;
	int n = 6;
	int a[10] = {13,14,15,16,17};
	int b[10] = {-1,1,11,12,20,23,25};
	int min = a[0]; 
	int max = a[m-1];   //vegulis a beszurando tomb elso es utolso eleme fontos csak
	int i;
	int e = 0;
	int v = n - 1;
	int k;
	if (n % 2 != 0) k = n / 2;
	else k = n / 2  +1;
	printf("kozepe: %d \n", k);
	while (e != v) {
		if (b[k] < min) {
			if (b[k + 1] > max) {
				printf("beszurhato innen: %d", k);
				break;
			}
		}
		if (b[k] <= min) {
			e = k;										//megkeressuk (binaris) azt a ket elemet, ami koze beszurhatjuk
			if (((v + e) % 2) != 0) k = (v + e) / 2 ;  
			else k = (v + e) / 2  + 1;
		}
		else {
			v = k;
			if (((v + e) % 2) != 0) k = (v + e) / 2  ;
			else k = (v + e) / 2  +1 ;
		}
	}


	if (e == v) printf("nem lehet");   //a kiirt ertek, ha lehetseges, annak az elemnek az indexe, ami utan beszurhatjuk. kulonben "nem lehet"

	system("PAUSE>>VOID");



}