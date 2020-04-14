//Demeter Tamas
//dtim1806
//511/2
//lab5 2

#include <iostream>
#include <fstream>

using namespace std;

//egy tevekenyseg jellemzoi 
struct Tevekenyseg {
	int es;
	int ef;
	int ls;
	int lf;
};

int main() {
	ifstream f;
	f.open("graf.txt");
	Tevekenyseg t[50];
	int n;
	int dur[50] = { 0 };
	int pred[50][50] = { 0 };
	int i, j;
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> dur[i];
	}
	while (!f.eof()) {
		f >> i >> j;
		pred[j-1][i-1] = 1;
	}

	t[0].es = 0;
	t[0].ef = dur[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pred[i][j] == 1) {
				if (t[j].ef > t[i].es) t[i].es = t[j].ef;
				t[i].ef = t[i].es + dur[i];
			}
		}
	}

	t[n - 1].lf = t[n - 1].ef;
	t[n - 1].ls = t[n - 1].lf - dur[n - 1];

	for (int i = n-1; i >=0; i--) {
		for (int j = n-2; j >=0; j--) {
			if (pred[i][j] == 1) {
				if (t[j].lf < t[i].ls) t[j].lf = t[i].ls;
				t[j].ls = t[j].lf - dur[j];
			}
		}
	}

	cout << "Kritikus ut:" << endl;
	for (int i = 0; i < n; i++) {
		if (t[i].ef == t[i].lf) cout << i + 1 << " ";
	}
	cout << endl;
	cout << "Tevekenysegek:" << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". Tevekenyseg:" << endl;
		cout << t[i].es << " Legkorabbi kezdes" << endl;
		cout << t[i].ef << " Legkorabbi befejezes" << endl;
		cout << t[i].ls << " Legkesobbi kezdes" << endl;
		cout << t[i].lf << " Legkesobbi befejezes" << endl;
	}
	f.close();
	return 0;
}