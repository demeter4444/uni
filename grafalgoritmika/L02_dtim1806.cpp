//Demeter Tamas
//dtim1806
//511/2
//L2

#include <iostream>
#include <fstream>

using namespace std;


void df_r(int cs,int l[],int* a[],int n, int v[]) { //melysegi bejaras rekurzivan. sok parameter + static a globalis valtozok elkerulesere szolgalnak.
//	printf("%d ", cs); //ha ki akarjuk irni a bejart csomopontokat.
	static int cs_instance=0;
	v[cs_instance%n] = cs;
	cs_instance++;

	l[cs] = 1;
	for (int k = 1; k <= n; k++) {
		if ((a[cs][k] == 1) && (l[k] == 0)) { 
			df_r(k, l, a, n, v);
		}
	}

}

int main() {

	ifstream f;
	f.open("graf.txt");

	int n;
	f >> n;

	int **a = new int* [n+1]; //szomszedsagi
	int **trl = new int*[n + 1]; //tranzitiv
	for (int i = 1; i <= n; i++) {
		a[i] = new int[n + 1];
		trl[i] = new int[n + 1];
	}

	for (int i = 1; i <= n; i++) {//inic.
		for (int j = 1; j <= n; j++) {
			a[i][j] = 0;
			trl[i][j] = 0;
		}
	}

	int x, y;
	while (!(f.eof())) { //szomszedsagi beolvasasa, tranzitiv inicializalasa
		f >> x >> y;
		a[x][y] = 1;
		trl[x][y] = 1;
	}

	for (int i = 1; i <= n; i++) { //szomszedsagi kiirasa
		for (int j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	//szelessegi
	printf("\nKiindulo csomopont = ");
	int s,k;
	cin >> s;
	printf("k = ");
	cin >> k;
	int *cs = new int[n + 1]; //csomopontok vektora
	int *lat = new int[n + 1]; //latogatottsagi vektor, ami egyben tavolsagvektor
	for (int i = 1; i <= n; i++) {
		cs[i] = 0;
		lat[i] = 0;
	}
	cs[1] = s;
	lat[s] = 1;
	int e = 1, v = 1;

	printf("\n%d -d rendu ismerosok:", k);
	while (e <= v) { //amig van meg amit bejarjunk, jarjuk szelessegibe a grafot, s ennek megfeleloen modositjuk a vektorokat
		int akt = cs[e];
		e++;
		for (int i = 1; i <= n; i++) {
			if ((a[akt][i] == 1) && (lat[i] == 0)) {
				v++;
				cs[v] = i;
				lat[i] = lat[akt] + 1;
				if (lat[i] == k+1) printf("%d ", i); //ha k lepes alatt elertunk egy csomopontot, kiirjuk
			}
		}
	}


	
	printf("\n");
		
	//melysegi

	int *ds = new int[n + 1]; //segedvektor az alkalmankent bejart csomopontok eltarolasara
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) lat[j] = 0; //a latogatottsagot es segedvektort minden bejaras elott lenullazzuk.
		for (int l = 1; l <= n; l++) ds[l] = 0;
		df_r(i, lat, a, n, ds);
		for (int k = 1; k <= n; k++) { //minden csomopont bejarasa utan megfeleloen modositjuk a tranzitiv lezarast
			trl[i][ds[k]] = 1;
		}
	}

	printf("\n\n Tranzitiv lezaras:\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)trl[i][j] = 1;
			printf("%d ", trl[i][j]);
		}
		printf("\n");
	}

	delete[] a;
	delete[] trl;
	delete[] ds;
	f.close();
	return 0;
}