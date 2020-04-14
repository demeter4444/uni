//Demeter Tamas
//511/2
//dtim1806
//C 7.feladat fo
/*Írjunk egy „tavolsag(x, y, n)” függvényt, amelyik kiszámítja az x = (xi) és y = (yi), i = 1, ..., n vektorok euklideszi távolságát (a vektorok azonos rangú elemei különbsége négyzetösszegének a négyzetgyöke). Ezt a függvényt használjuk 2 vektor távolságának kiszámítására. A vektorokat az „input.dat” file-ból olvassuk be, az eredményt pedig, a bemenő adatokkal együtt az „output.dat” file-ba írjuk.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tavolsag.h"

int main(){

        FILE* f;
	FILE* g;
        f=fopen("input.dat","r");
	if (!f) {
		printf("Fajl megnyitasa sikertelen!");
		exit(1);
	}
        g=fopen("output.dat","w");
        int n,m;
        fscanf(f,"%d",&n);
	double* x=(double*)malloc(n*sizeof(double));
        int i;
        for(i=0;i<n;i++){
		fscanf(f,"%lf",&x[i]);
	}
	fscanf(f,"%d",&m);
	double* y=(double*)malloc(m*sizeof(double));
	for(i=0;i<m;i++){
	fscanf(f,"%lf",&y[i]);
	}
	fprintf(g,"A ket vektor kozti tavolsag: %f\n",tavolsag(x,y,n));
        fclose(f);
        fclose(g);
	free(x);
	free(y);
	return 0;
}

