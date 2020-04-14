//Demeter Tamás
//dtim1806
//511/2
//L3

#include <iostream>
#include <fstream>

using namespace std;

struct el {
	int cs1;
	int cs2;
	int suly;
};


//Bellmann Ford
void bf(int n, int e, el elek[],int src, int(&x)[100]) {
	int dist[100];
	int utvonal[100] = { 0 };

	//init
	for (int i = 1; i <= n; i++) {
		dist[i] = 9999;
		dist[src] = 0;
	}
	
	//relax
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < e; j++) {
			int u = elek[j].cs1;
			int v = elek[j].cs2;
			int su = elek[j].suly;
			if (dist[u] != 9999 && dist[u] + su < dist[v]) {
				dist[v] = dist[u] + su;
				utvonal[v] = u;
			}
		}
	}

	//negativkor
	for (int i = 1; i < e; i++) {
		int u = elek[i].cs1;
		int v = elek[i].cs2;
		int su = elek[i].suly;
		if (dist[u] != 9999 && dist[u] + su < dist[v]) {
			cout << "Negativ kor!";
			return;
		}
	}

	//kiir
	for (int i = 1; i <= n; i++) {
		cout << i << ". csomoponttol tavolsag: " << dist[i] << endl;
		int j = i;
		if (dist[i] != 9999) {
			cout << i << ". csomopontbol utvonal(visszafele): " << i << " ";
			while (utvonal[j] != 0) {
				cout << utvonal[j] << " ";
				j = utvonal[j];
			}
		}
		else cout << i << ". csomopontba nincs utvonal.";
		cout << endl;
		cout << endl;
	}
	for (int i = 0; i < 100; i++)x[i] = dist[i];
}

//Halk Bellmann-Ford (nem nez negativ kort es nem ir ki semmit. hasznaljuk Johnsonnal, az utolso parameterkent atadott tombben visszakapjuk a tavolsagokat).
void bf_halk(int n, int e, el elek[], int src, int(&x)[100]) {
	int dist[100];
	int utvonal[100] = { 0 };

	//init
	for (int i = 1; i <= n; i++) {
		dist[i] = 9999;
		dist[src] = 0;
	}

	//relax
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < e; j++) {
			int u = elek[j].cs1;
			int v = elek[j].cs2;
			int su = elek[j].suly;
			if (dist[u] != 9999 && dist[u] + su < dist[v]) {
				dist[v] = dist[u] + su;
				utvonal[v] = u;
			}
		}
	}

	for (int i = 0; i < 100; i++)x[i] = dist[i];
}

//djikstrahoz: minimalis tavolsagu csomopont visszateritese nem bejartakbol.
int mind(int dist[], bool bejart[], int n) {
	int min = 9999;
	int mini;

	for (int i = 1; i <= n; i++)
		if (bejart[i] == false && dist[i] <= min)
			min = dist[i], mini = i;

	return mini;
}

//Djikstra
void dj(int n, int a[100][100], int src, int dest) {

	int dist[100];
	bool bejart[100];
	int utvonal[100];

	//init.
	for (int i = 1; i <= n; i++) {
		utvonal[src] = 0;
		dist[i] = 9999;
		bejart[i] = false;
	}

	dist[src] = 0;


	//bejaras
	for (int i = 1; i <= n; i++)
	{
		int u = mind(dist, bejart,n);
		bejart[u] = true;
		for (int v = 1; v <= n; v++)
			if (!bejart[v] && a[u][v] && dist[u] + a[u][v] < dist[v]) {
				utvonal[v] = u;
				dist[v] = dist[u] + a[u][v];
			}
	}

	//kiir
	cout << src << ".bol " << dest << ".ba a tavolsag: " << dist[dest] << endl;
	if (dist[dest] != 9999) {
		cout << dest << ". csomopontbol utvonal(visszafele): " << dest << " ";
		int j = dest;
		while (utvonal[j] != 0) {
			cout << utvonal[j] << " ";
			j = utvonal[j];
		}
	}
	else cout << dest << ". csomopontba nincs utvonal.";

}

//Johnson
void jh(int n, int a[100][100],int e, el elek[]) {
	//uj cspont hozzaadasa, elek huzasa minden cspontba
	int ujcspont = n + 1;
	int ee = e;
	for (int i = 1; i <= n ; i++) a[ujcspont][i] = 0;
	for (int i = 1; i <= n; i++) {
		elek[e].cs1 = ujcspont;
		elek[e].cs2 = i;
		elek[e].suly = 0;
		e++;
	}
	int tavolsagok[100];

	//Bellmann-Ford meghivasa az uj grafra
	bf_halk(n, e, elek, ujcspont, tavolsagok);
	
	//Uj sulyok beallitasa
	for (int i = 1; i < e; i++) {
		elek[i].suly = elek[i].suly + tavolsagok[elek[i].cs1] - tavolsagok[elek[i].cs2];
	}

	//Djikstra meghivasa minden cspontbol minden cspontba
	for (int i = 1; i <= n; i++) {
		cout << endl;
		cout << endl;
		for (int j = 1; j <= n; j++) {
			dj(n,a,i,j);
			cout << endl;
		}
	}
	
}

int main() {

	ifstream f;
	int a[100][100];
	el elek[100];

		//szomszedsagi,tavolsag init.
		for (int i = 1; i < 100; i++) {
			for (int j = 1; j < 100; j++) {
				a[i][j] = 0;
			}
		}

	//szomszedsagi be
	int e = 1;
	int n;
	f.open("graf.txt");
	f >> n;
	while (!f.eof()) {
		int i, j, s;
		f >> i >> j >> s;
		elek[e].cs1 = i;
		elek[e].cs2 = j;
		elek[e].suly = s;
		a[i][j] = s;
		e++;
	}

	//kiir szomszedsagi
	cout << "A beolvasott graf szomszedsagi matrixa:" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	int menu=-1;
	while (menu != 0) {
		cout << endl;
		cout << "Mit szeretne futtatni?" << endl;
		cout << "1. Bellmann-Ford" << endl;
		cout << "2. Djikstra" << endl;
		cout << "3. Johnson" << endl;
		cout << "0. Exit" << endl;
		cin >> menu;
		switch (menu) {
			case 1:
				int semmi[100];
				int bfsrc;
				cout << "B.F: Kiindulo csomopont?" << endl;
				cin >> bfsrc;
				bf(n, e, elek, bfsrc, semmi);
				break;
			case 2:
				int djsrc, djdest;
				cout << "Dj.: Kiindulo csomopont?" << endl;
				cin >> djsrc;
				cout << "Dj.: Cel csomopont?" << endl;
				cin >> djdest;
				dj(n, a, djsrc, djdest);
				break;
			case 3:
				jh(n, a, e, elek);
				break;
			default:
				exit(1);
		}

	}

	return 0;
}

