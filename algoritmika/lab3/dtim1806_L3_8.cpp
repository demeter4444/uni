//Demeter Tamás
//511/2
/*Adva van több valós együtthatójú polinom. A polinomok száma ismeretlen. Írjunk programot, amellyel kiszámítjuk az összegüket, és kiválasztjuk azt a polinomot, amelynek az a pontban kiszámított értéke a legnagyobb az összes megadott polinom ugyanazon a pontban kiszámított értékei között.
Egy polinomot a fokszámán és az együtthatóin keresztül adunk meg. Írjuk ki a megadott polinomok összegét, valamint azt a polinomot, amelynek az értéke maximális az adott a pontban. Amennyiben nem csak egy ilyen polinom van, elegendő egyet kiírni. 
A bemenet első sorában az adott a valós érték található. A következő sorok mindegyike egy p fokszámot (0≤p≤100), majd a fokszámnak megfelelő számú valós együtthatót tartalmaz. A fokszám után a legnagyobb fokszámú tag együtthatója következik (amely kötelezően nem nulla), majd az eggyel kisebb fokszámúé, stb. Például:
2 5 -1.5 0   ->   5X2 - 1.5X
A kimenet első sora az összegpolinomot tartalmazza, a második a kiválasztott, az a pontban legnagyobb értékű polinomot, a harmadik pedig a kiválasztott polinom kiszámított értékét az a pontban.*/

#include <stdio.h>
#include <math.h>

main() {
	FILE*f;
	f = fopen("dtim1806_L3_8.txt", "r");
	int a;
	fscanf(f, "%d", &a);
	float p[200][200];
	int i;
	int j;
	for (i = 0; i < 200; i++) {
		for (j = 0; j < 200; j++) {		//a polinomokat egy matrixba fogjuk tarolni
			p[i][j] = 0;
		}
	}
	int psorsz[200];		//a beolvasast ugy oldjuk meg, hogy minden sor elso elemet egy kulon tombbe olvassuk be, ami az adott indexu polinom fokszamat fogja tartalmazni
	int n;
	i = 0;
	int max = 0;
	while (!feof(f)) {
		fscanf(f, "%d", &psorsz[i]);
		if (psorsz[i] > max) max = psorsz[i];	
		for (j = psorsz[i]; j >= 0; j--) {	//a fokszam beolvasasa utan elkezdjuk epiteni matrixunkat. a sor az a polinom index, az oszlop az az adott fokszamon szereplo egyuthato
			fscanf(f, "%f", &p[i][j]);
		}
		i++;


	}
	n = i - 1;
	float s = 0;
	float osszp[200];
	for (j = max; j >= 0; j--) {	//max-ban taroljuk a legnagyobb fokszamu polinomot. max-ig osszeadjuk minden polinom megfelelo egyuthatojat
		s = 0;
		for (i=0; i<=n; i++) {
			s = s + p[i][j];
		}
		osszp[j] = s;
		
	}
	printf("Az osszegpolinom:\n");
	for (i = max; i >= 0; i--) {
		if (osszp[i] != 0) printf("(%f*X^%d) + ", osszp[i],i);	//ahol nem 0 az egyuthato, ott megjelenitjuk
	}
	

	s = 0;
	float maxx = 0;
	int maxpoz = -1;
	for (i = 0; i <= n; i++) {
		s = 0;
		for (j = max; j >= 0; j--) {
			s = s + p[i][j] * (float)pow(a, j);		//behelyettesitunk minden polinomba, s szamoljuk maxx-ban a legnagyobb helyettesitesi erteket. amikor ez megvan, az erteket es a polinom indexet elmentjuk.
		}
		if (s > maxx) {
			maxx = s;
			maxpoz = i;
		}
	}

		printf("\n a legnagyobb erteket ebbe a polinomba helyettesitve kapjuk:\n");
	for (i = max; i >= 0; i--) {
		if (p[maxpoz][i] != 0) printf("(%f*X^%d) +", p[maxpoz][i],i);	//az elobb elmentett adatokat felhasznaljuk
	}
	printf("\n ennek erteke: %f", maxx);
	fclose(f);
	system("PAUSE>>VOID");
	//csorba az egesz programom, s nincs alprogramom, de egyszeruen nem tudtam mire irni. pontlevonast megertem.
}