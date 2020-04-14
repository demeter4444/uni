//Demeter Tamás
//511/2
/*Írjunk algoritmust, amely megkeresi és kiírja az első n ikerprímet!
Két prímszám, p és q ikerprímek, ha |q – p| = 2.*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool prim(int x) {
	if ((x == 1) | (x == 0)) return 0;
	else {
		int i;
		int db = 0;
		for (i = 2; i <= x / 2; i++) {	//primellenorzo fuggveny
			if (x % i == 0) db++;
		}
		if (db == 0) return 1;
		else return 0;

	}


}

main() {
	int n;
	int p[2];			//hasznalunk egy ketelemu tombot (valojaban 2 valtozot), mely elemei primszamok lesznek
	p[0] = 2;		//inicializaljuk az elso primszammal, mindket valtozot
	p[1] = 2;
	printf("n="); scanf_s("%d", &n);
	printf("Az elso %d ikerprim: \n", n);
	int db = 0;
	int i = 1;
	while (db < n) {			//az i valtozoval vegigballagung a szamokon,mikor talalunk egy primet akkor a kovetkezot tesszuk:
		if (p[1] - p[0] == 2) {				//a tomb elso elemebe kerul a masodik, a masodikba pedig az uj prim
			printf("(%d,%d) ", p[0], p[1]);	//ha az ikerprim feltetele teljesul a parra, kiiratjuk, kulonben megyunk tovabb.
			db++;
			p[0] = 0; //erre a nullazasra azert van szukseg, hogy ne lepjen be ugyanarra a megoldasra tobbszor az ikerprim-ellenorzesbe, ami a while-on belul egy if. megtartani amugyis csak a masodik elemet kell.
		}
		i++;
		if (prim(i)) {
			p[0] = p[1];
			p[1] = i;
		}
	}


	system("PAUSE>>VOID");

}