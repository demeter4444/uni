//Demeter Tamás
//511/2
//Bontsuk törzstényezőkre egy adott természetes számot!


#include <stdio.h>

main() {
	int n;
	printf("n=");
	scanf_s("%d", &n);
	int o = 2;				//egy valtozoval vegigmegyunk a lehetseges osztokon
	int i ;					//minden oszto eseten szamoljuk, hanyszor oszthato
	printf("Az adott szam torzstenyezokre bontva: \n");
	while (n != 1) {
		i = 0;
		while (n % o == 0) {
				i++;
				n = n / o;
		}
		if (i != 0) {
			if (n !=1) printf("%d^%d * ", o, i);	//az eredmenyt felirjuk hatvany es szorzat formajaban.
			else printf("%d^%d", o, i);
		}
		o++;
	}
	system("PAUSE>>VOID");
}