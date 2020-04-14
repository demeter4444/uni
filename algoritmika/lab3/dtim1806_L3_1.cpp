//Demeter Tamás
//511/2
/*A karácsonyi vásáron m áruházban n különböző terméket árusítanak. Az egyes termékek árát egy m * n méretű tömbben tároljuk (m a sorok száma, n az oszlopoké). A tömb i. sora az i. áruház termékenkénti árait tartalmazza. Feltéve, hogy minden terméknek ismerjük az árát, határozzuk meg:
- annak az áruháznak a sorszámát, amelyben a legmagasabb az átlagár;
- a legolcsóbb áru/áruk sorszámát;
- azt az áruházat/áruházakat, ahol egy adott j sorszámú áru a legdrágábban vásárolható, és azt ahol a legolcsóbban;
- egy adott i sorszámú áruház termékeinek átlagárát két tizedes pontossággal.
A bemenet első sora az áruházak és a termékek számát tartalmazza, az ezt követő m sor pedig a termékenkénti árakat. Ezt követi két szám: annak a terméknek a sorszáma, amiről el kell dönteni, hol a legdrágább, és hol a legolcsóbb, valamint annak az áruháznak a sorszáma, amelyben az átlagárat kell kiszámolni. A sorszámok 1-es indexeléssel értendőek.
*/
#include <stdio.h>

int minszamol(int a[10][10], int m,int n) {  //ez az alprogram megadja a matrix legkisebb elemet.
	int i, j, min;
	min = a[1][1];
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (a[i][j] < min) min = a[i][j];
		}
	}
	return min;
}

main() {
	FILE *f;
	int m, n,i,j,t,ah;
	int a[10][10];
	f = fopen("dtim1806_L3_1.txt", "r");
	fscanf(f, "%d %d\n", &m, &n);
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			fscanf(f, "%d", &a[i][j]);
		}
	}
	fscanf(f, "%d %d", &t, &ah);	//az ertekek beolvasasa

	int max = -1;
	int min = 1;
	int minertek = a[1][1];
	int mint = a[1][t];
	int maxt = -1;

	printf("legolcsobb termekek: ");
	for (i = 1; i <= m; i++) {
		int atl = 0;
		minertek = a[i][1];			//ugyanabban a duplaforban nezzuk: -oszloponkent a legkisebb elemet, ha ez megegyezik a matrix legkisebb elemevel, akkor az a termek "legolcsobb", tehat kiiratjuk. 
		for (j = 1; j <= n; j++) {
			atl = atl + a[i][j];	//-soronkent a legmagasabb atlagot, ezt a vegen kiiratjuk
			if (a[i][j] < minertek) {
				min = j;
				minertek = a[i][j];
			}
		}
		atl = atl / n;
		if (atl > max) max = i;
		if (minertek == minszamol(a, m, n)) printf("%d, ", min);
	}
	printf("\nlegmagasabb atlagaru aruhaz: %d",max);
	

	for (i = 1; i <= m; i++) {		//ebben a forban nezzuk egyszerre, hol a legolcsobb es hol a legdragabb az adott termek.
		if (a[i][t] < mint) mint = i;
		if (a[i][t] > maxt) maxt = i;
	}
	float atll = 0;		
	for (j = 1; j <= n; j++) atll = atll + a[ah][j];	//ebben a forban szamoljuk az adott aruhaz atlagarat
	atll = atll / n;

	printf("\naz adott termek itt a legolcsobb %d  , itt a legdragabb : %d", mint,maxt);
	printf("\naz adott aruhaz termekeinek atlagara: %f", atll);
	system("PAUSE>>VOID");
	fclose(f);
}