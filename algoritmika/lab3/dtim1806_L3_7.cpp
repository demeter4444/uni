//Demeter Tamás
//511/2
/*Adott egy n elemű természetes számokat tartalmazó sorozat. Keressük meg és írjuk ki azt a leghosszabb sb, sb+1, …, sj tömbszakaszt, amely csak prímszámokat tartalmaz! A bemenet első sora tartalmazza az n értékét, ezt követően pedig az n elemet.
Útmutatás ■ Elemezzük a következő eseteket:
- Ha minden szám prím?
- Ha nincs egyetlen prímszám sem?
- Ha az aktuális részsorozathoz hozzátartozik az adott sorozat utolsó eleme is?*/
#include <stdio.h>
#include <stdbool.h>

bool prim(int x) {
	if (x == 1) return 0;
	else if (x == 2 || x == 3) return 1;
	else if (((x + 1) % 6 == 0) || ((x - 1) % 6 == 0)) return 1;	//alprogram mely csekkol primalitast
	else return 0;
}


main() {
	FILE*f;
	f = fopen("dtim1806_L3_7", "r");
	int i, n;
	int v[50];
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++) fscanf(f, "%d", &v[i]);
	i = 0;
	int db = 0;
	int max = 0;
	int poz1 = -1;
	int poz2 = -1;
	int poz1vegso = -1;
	int poz2vegso = -1;
	while (i < n) {				//egy while-al megyunk vegig a sorozaton
		if (prim(v[i])) {
			poz1 = i;
			while (prim(v[i])) {	//elso prim talalatkor elmentjuk a poziciot, es haladunk elore amig vannak meg sorban primek. a hosszat a sornak elmentjuk, a vegen pedig az utolso poziciot
				db++;
				i++;
			}
			poz2 = i - 1;
		}
		if (db >= max) {		//ha az eddig talalt sorozat hossza maximalis, akkor ket vegso valtozoba elmentjuk az elso es utolso indexet
			max = db;
			poz1vegso = poz1;
			poz2vegso = poz2;
		}
		db = 0;  //amikor mar nem primet talalunk, fontos hogy a db-t lenullazzuk
		i++;
	}

	for (i = 0; i < n; i++)printf("%d ", v[i]);
	printf("\nA reszsorozat:\n");
	if ((poz1vegso < 0)||(poz2vegso<0)) printf("Nincs prim");		//ha nem valtoztak inicializalas ota az ertekek, akkor nincs primunk. ha igen, akkor elso indextol utolsoig kiirjuk a reszsorozatot
	else {
		for (i = poz1vegso; i <= poz2vegso; i++) printf("%d ", v[i]);
	}
	fclose(f);
	system("PAUSE>>VOID");
	//a program mukodik minden kert esetre:
	//-ha minden prim
	//-ha nincs prim
	//-ha az utolso elem tagja a reszsorozatnak
}