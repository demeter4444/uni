//Demeter Tamas
//dtim1806
//511/2
//L4 2

#include <iostream>
#include <fstream>

using namespace std;

int bennevan(int x, int v[100], int n) { //alprogram megkeres valamit egy vektorban
	for (int i = 0; i < n; i++) {
		if (v[i] == x) return 1;
	}
	return 0;
}

void shift(int x, int v[100], int n) { //alprogram balra shiftel egy vektort es betesz egy elemet a vegere
	for (int i = 0; i < n-1; i++) {
		v[i] = v[i + 1];
	}
	v[n - 1] = x;
}

int main() {

	ifstream f;
	f.open("graf.txt");
	int m;
	int p[100]; //prufer kod
	int sz[100][100] = { 0 }; //szomszedsagi matrix
	f >> m;
	int n = m + 2; //csomopontok szama
	for (int i = 0; i < m; i++) {
		f >> p[i];
	}

	for (int i = 0; i <m; i++) { //vegigmegyunk a kodon

			//minden iteracioban:
			int elso = p[0]; //az elso csomopont a kod elso eleme
			int masodik; //a masodik csomopont az a legkisebb indexu csomopont ami nincs a kodban
			for (int j = 1; j <= n; j++) {
				if (bennevan(j, p, m) == 0) {
					masodik = j;
					break;
				}
			}
			sz[elso][masodik] = 1; //a ketto kozott huzunk elt
			sz[masodik][elso] = 1;
			shift(masodik, p, m); // a kodot balra toljuk s a vegere tesszuk a masodikat

	}

	//az utolso ket elem azok amelyek nincsenek a vegen a kodban.
	int elso = -1;
	int masodik = -1;
	for (int i = 1; i <= n; i++) {
		if ((elso != -1) && (bennevan(i, p, m) == 0)) {
			masodik = i;
			break;
		}
		if ((elso == -1) && (bennevan(i, p, m) == 0)) {
			elso = i;
		}
	}

	//a ketto kozott meghuzzuk az utolso elt
	sz[elso][masodik] = 1;
	sz[masodik][elso] = 1;

	//kiir
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << sz[i][j] << " ";
		}
		cout << endl;
	}

	f.close();
	return 0;
}