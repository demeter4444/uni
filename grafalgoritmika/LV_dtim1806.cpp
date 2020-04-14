//Demeter Tamas
//dtim1806
//511/2
//Labvizsga

#include <iostream>
#include <fstream>

using namespace std;

//ket szam minimuma
int min(int a, int b) {
	if (a <= b) return a;
	return b;
}

//egy vektor maximuma
int max(int n, int v[]) {
	int temp = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i] > temp) temp = v[i];
	}
	return temp;
}

int main() {

	ifstream f;
	f.open("asterix.txt");
	int n, e;
	int a[50][50] = { 0 };
	int sz[50][50] = { 0 };
	f >> n >> e;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e; j++) {
			f >> a[i][j];
		}
	}

	//a illeszkedesi->szomszedsagi
	cout << "Szomszedsagi: " << endl;
	int cs1, cs2;		
	for (int i = 0; i < e; i++) {
		cs1 = -1;
		cs2 = -1;
		for (int j = 0; j < n; j++) {
			if ((a[j][i] == 1) && (cs1 == -1)) {
				cs1 = j;
				for (int k = j+1 ; k < n; k++)
					if (a[k][i] == 1) cs2 = k;
				sz[cs1][cs2] = 1;
				sz[cs2][cs1] = 1;
			}

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << sz[i][j] << " ";
		}
		cout << endl;
	}

	//b freeman
	int csomopontok[50] = { 0 };
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += sz[i][j];
		}
		csomopontok[i] = sum;
	}
	int maxf = max(n, csomopontok);
	int fsum = 0;
	for (int i = 0; i < n; i++) {
		fsum += maxf - csomopontok[i];
	}
	double freeman = (double)fsum / (n - 1)*(n - 2);
	cout << "Freeman egyutthato: " << freeman << endl;

	//c osszefuggo
	int v[50];
	for (int i = 0; i < n; i++) v[i] = i; 
	for (int i = 0; i < n; i++) {			
		for (int j = 1; j <= n; j++) {		
			if (sz[i][j] != 0) {
				v[i] = min(v[i], v[j]);
				v[j] = min(v[i], v[j]);
			}
		}
	}
	//cout << "Vektor: " << endl;
	//for(int i=0;i<n;i++) cout << v[i] << " ";
	int maxk = v[0];
	int of = 1;
	for (int i = 0; i < n; i++) if (v[i] != maxk) {
		cout << "Nem osszefuggo";
		of = 0;
		break;
	}
	if (of == 1) cout << "Osszefuggo";
	cout << endl;

	//d izolalt
	cout << "Nincs baratjuk: ";
	for (int i = 0; i < n; i++) {
		int izolalt = 1;
		for (int j = 0; j < e; j++) {
			if (a[i][j] != 0) izolalt = 0;
		}
		if (izolalt == 1) cout << i << " ";
	}
	cout << endl;

	//e paros
	if (of == 1) {
		//szelessegi -> szinezes
		int s = 0;
		int szinek[50];
		int cs[50];
		int lat[50];
		szinek[s] = 1;

		for (int i = 0; i < n; i++) {
			cs[i] = 0;
			lat[i] = 0;
		}

		cs[0] = s;
		lat[s] = 1;
		int el = 1, ve = 1;

		while (el <= ve) {
			int akt = cs[el];
			el++;
			for (int i = 0; i < n; i++) {
				if ((sz[akt][i] == 1) && (lat[i] == 0)) {
					ve++;
					cs[ve] = i;
					lat[i] = lat[akt] + 1;
					szinek[i] = (szinek[i - 1] + 1) % 2;
				}
			}
		}
		int paros = 1;
		for (int i = 1; i < n; i++) {
			if (szinek[i] == szinek[i - 1])paros = 0;
		}
		if (paros == 1) {
			cout << "A graf paros" << endl;
		
		}
		else cout << "A graf nem paros" << endl;
	}
	else cout << "A graf nem paros" << endl;
	f.close();
	return 0;
}