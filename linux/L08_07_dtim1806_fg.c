//Demeter Tamas
//511/2
//dtim1806
//C 7.feladat modul
/*Írjunk egy „tavolsag(x, y, n)” függvényt, amelyik kiszámítja az x = (xi) és y = (yi), i = 1, ..., n vektorok euklideszi távolságát (a vektorok azonos rangú elemei különbsége négyzetösszegének a négyzetgyöke). Ezt a függvényt használjuk 2 vektor távolságának kiszámítására. A vektorokat az „input.dat” file-ból olvassuk be, az eredményt pedig, a bemenő adatokkal együtt az „output.dat” file-ba írjuk.*/

#include <stdio.h>
#include <math.h>
#include "tavolsag.h"

double tavolsag(double* x, double* y, int n){
	int i;
	double sum=0.0;
	double temp=0.0;
	for(i=0;i<n;i++){
		temp=x[i]-y[i];
		sum=sum+(temp*temp);
	}
	return sqrt(sum);
}

