//Demeter Tamás
//511/2
/*Egy n x n méretű sakktáblán az (x, y) helyen található egy futár és az (x0, y0) helyen egy ló.
A lónak el kell jutnia erről a helyről az (x1, y1) helyre, anélkül, hogy egy bizonyos négyzetre többször lépne illetve, hogy olyan helyen állna meg, ahonnan a futár kiütheti.
Írjuk ki a ló útvonalait! A ló nem ütheti le a futárt!
A bemenet első sora tartalmazza a tábla méretét, a második a futár pozícióját, a harmadik a ló kezdőpozícióját, a negyedik pedig a cél koordinátáit.
A kimenet koordinátapárok(sor, oszlop) egymás alá írt sorozata kell hogy legyen, melyek az útvonalak lépéssorozatait jelentik.Két útvonal között ki kell hagyni egy sort.*/

#include <stdio.h>

int n;
int m[50][50];
int xlo, ylo, xfu, yfu, xcel, ycel;
const int xl[8] = { 1,2,2,1,-1,-2,-2,-1 }; //a lo lepese
const int yl[8] = { -2,-1,1,2,2,1,-1,-2 };


void kiir() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

int jo(int x, int y) {
	int k = 1;
	if ((x < 0) || (x >= n) || (y < 0) || (y >= n)) k = 0;
	if (m[x][y] == -1) k = 0; //-1 jeloli a futar altal vedett mezoket
	return k;
}

void back(int x,int y) {
	int i;
	if (jo(x, y) == 1) {
		if ((x == xcel) && (y == ycel)) {
			kiir();
		}
		else {
			for (i = 0; i < 8; i++) {
				m[x][y] = 3;
				back(x + xl[i], y + yl[i]); //3massal akartam jelolni a lo utjat
				m[x][y] = 0;
			}
		}
	}
}


main() {
	int i, j;
	FILE*f = fopen("dtim1806_L6_5.txt", "r");
	fscanf(f, "%d", &n);
	fscanf(f, "%d %d", &xfu, &yfu);
	fscanf(f, "%d %d", &xlo, &ylo);
	fscanf(f, "%d %d", &xcel, &ycel);
	xlo--;
	ylo--;
	xfu--;
	yfu--;
	xcel--;
	ycel--;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			m[i][j] = 0;
		}
	}

	i = xfu;
	j = yfu;
	while ((i >= 0) && (j >= 0)) {
		m[i][j] = -1;
		i--;
		j--;
	}

	i = xfu;
	j = yfu;
	while ((i < n) && (j < n)) {
		m[i][j] = -1;
		i++;
		j++;
	}

	m[xlo][ylo] = 1;
	m[xcel][ycel] = 2;

	back(xlo, ylo);


}