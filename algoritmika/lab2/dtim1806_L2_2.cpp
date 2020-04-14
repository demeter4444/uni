//Demter Tamás
//511/2
//Határozzuk meg az 1 milliónál kisebb, legnagyobb prímszámot!

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool prim(long int x) {
	if ((x == 1) | (x==0)) return 0;
	else {
		int db = 0;
		long int i;
		for (i = 2; i <= x / 2; i++) {  //fuggveny, mellyel ellenorizzuk egy szamrol, hogy prim-e
			if (x % i == 0) db++;
		}
		if (db == 0) return 1;
		else return 0;
	}
}

main(){
	long int i;
	for (i = 1000000; i > 1; i--) {
		if (prim(i)) {
			printf("Az elso 1.000.000-nal kisebb prim: %d", i);	//elindulunk 1.000.000-tol visszafele, es sorba nezzuk a szamokat. az elso talalatnal kilepunk.
			break;										//valoszinuleg van matematikailag hatekonyabb modja, de nem ismerem.
		}
	}
	system("PAUSE>>VOID");
}