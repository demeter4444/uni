//Demeter Tamás, dtim1806, 511/2
//8. labor, 2. feladat
//A kolozsvári színház műsorában n előadás szerepel.
//Mindenik esetében ismert a kezdés időpontja, valamint az előadás végének pontos ideje.
//Egy különleges vendég kedvéért a színház be szeretné mutatni egyetlen nap folyamán minden előadását.
//Mivel csak egy színhely áll rendelkezésre, állapítsuk meg azt a maximális számú színdarabot, amelyeket a színház bemutathat anélkül, hogy az eredeti kezdési és zárási időpontokat változtatnák.

#include <stdio.h>

main() {
	FILE*f = fopen("dtim1806_L8_2.txt", "r");
	int n;
	struct eloadas {
		int start;
		int end;
	};

	struct eloadas v[50];
	fscanf(f, "%d", &n);
	int i;
	int h1, m1, h2, m2;
	for (i = 0; i < n; i++) { 
		fscanf(f, "%d:%d %d:%d", &h1, &m1, &h2, &m2);
		v[i].start = h1 * 60 + m1;
		v[i].end = h2 * 60 + m2; //az idot percekbe merjuk, mert egyszerubb
	}

	int max = 0;
	i = 0;
	int j = 0;
	while (i < n-1) { //feltetelezzuk, hogy az eloadasok idorendi sorrendbe vannak, mint a peldaban
		j = 0;
		while (v[i].end < v[i + 1].start) {
			j++;
			i++;
		}
		if (j > max) max = j+1;
		i++;
	}
	printf("%d", max);

}