//Demeter Tamas
//dtim1806
//511/2
//L4 1

#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream f;
	f.open("graf.txt");
	int n;
	f >> n;
	int fokszam[100] = { 0 }; //fokszamok csomopontoknak
	int sz[100][100] = { 0 }; //szomszedsagi matrix

	while (!f.eof()) {
		int i, j;
		f >> i >> j;
		fokszam[i]++;
		fokszam[j]++;
		sz[i][j] = 1;
		sz[j][i] = 1;
	}

	int pcount = 0;
	if (n <= 2) { //legyen legalabb 3 csomopont
		cout << "Hiba";
		exit(1);
	}

	while (pcount != n-2){ //a prufer kod n-2 elembol all
		for (int i = 1; i <= n; i++) { //megkeressuk az elso legkisebb indexu 1-fokszamu csomopontot
			if (fokszam[i] == 1) {
				for (int j = 1; j <= n; j++) { //megkeressuk az elso lekisebb indexu szomszedjat
					if (sz[i][j] == 1) {
						cout << j << " "; //betesszuk a prufer kodba
						pcount++;
						sz[i][j] = 0; //kivesszuk a grafbol
						sz[j][i] = 0;
					}
				}
			}
		}
	}

	f.close();
	return 0;
}