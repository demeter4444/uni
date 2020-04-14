//Demeter Tamás
//511/2
/*Adott egy n elemű, egész számokból álló sorozat. Írjunk programot, amely szétrendezi a sorozatot! Szétrendezés alatt azt a műveletsort értjük, amelynek elvégzése után a legkisebb elem az első helyen, az érték szerint következő az utolsó helyen stb. helyezkedik el. A szétrendezést orgonasíp-rendezésnek is nevezzük. A bemenet első sora tartalmazza az n értékét, ezt követően pedig az n elemet. A kimenet a szétrendezett sorozatot tartalmazza.*/
#include <stdio.h>

main() {
	FILE*f;
	int n,i,j;
	int v[30];
	f = fopen("dtim1806_L3_4.txt", "r");
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(f, "%d", &v[i]);
	}
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {	//eloszor rendezzuk siman novekvobe a tombot
			if (v[i] > v[j]) {
				int csere = v[i];
				v[i] = v[j];
				v[j] = csere;
			}
		}
	}
	
	int v1[15];
	int v2[15];			//utana kettebontjuk a tombunket, mert tudjuk hogy a rendezett tombbol minden paros indexu elem a szetrendezes egyik vegere, minden paratlan indexu pedig a masik vegere kerul.
	int k = 0;
	int l = 0;
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			v2[k] = v[i];
			k++;
		}
		else {
			v1[l] = v[i];
			l++;
		}
	}
	j = 0;
	while (j<n) {
		for (i = 0; i < k; i++) {		//ezek utan, ujraepitjuk az eredeti vektort, mert ugy az igazi.
			v[j] = v2[i];
			j++;
		}
		for (i = l - 1; i >= 0; i--) {
			v[j] = v1[i];
			j++;
		}
	}
	for (i = 0; i < n; i++)printf("%d ", v[i]);  //kiiratjuk szetrendezve
	fclose(f);
	system("PAUSE>>VOID");
}
//alprogramokra nem volt szukseg, mert csak egyszer vegzunk el minden feladatot, s atlathato: rendezes,ketteosztas,visszaosztas