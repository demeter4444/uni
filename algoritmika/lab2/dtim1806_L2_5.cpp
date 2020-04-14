//Demeter Tamás
//511/2
//Írjunk ki egy, a 60-as számrendszerben megadott számot a 10-es számrendszerben! 

#include <stdio.h>
#include <string.h>
#include <math.h>

main() {
	int c[130];
	int i,j;
	j = 0;
	for (i = 48; i <= 57; i++) {
		c[i] = j;
		j++;
	}
	for (i = 65; i <= 90; i++) {	//A-tol Z-ig es a-tol x-ig felhasznaljuk a betuket, hogy elerjuk a 60 szamjegyet
		c[i] = j;					//Hasznalunk egy tombot, hogy minden megegyezo karakter ascii kodjanak az indexen levo mennyiseg a szamrendszerben elfoglalt helye. pl. x(120ascii)=59
		j++;
	}
	for (i = 97; i <= 120; i++) {
		c[i] = j;
		j++;
	}

	char szam[100];
	printf("60as szamrendszerbeli szam = \n");
	fgets(szam,sizeof(szam),stdin);		//beolvassuk string-kent a 60as szamrendszerbeli szamot, majd elemenkent, a klasszikus szamrendszeratalakitos (nagyobb -> kisebb) keplettel kiszamoljuk az eredmenyt
	unsigned long int s = 0;
	int h = 0;
	for (i = strlen(szam) - 2; i >= 0; i--) {
		s = s + (int)pow(60, h)*c[szam[i]]; //a tomb indexe mindig az adott karakter ascii kodja. 
		h++;
	}
	printf("Tizes szamrendszerben: %d \n", s);
	system("PAUSE>>VOID");
}