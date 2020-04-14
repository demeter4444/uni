//Demeter Tamas
//dtim1806
//511/2
//lab6 tsp greedy

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//lehet classba is vagy mindig atadni parameterkent alprogramoknak, de megelegszem igy vele, hogy mukodik.
double szm[2050][2050];
int feldolgozott[2050];
int n = 0;
double minut = 0;

void beolvas()
{

	//fajl beolvasasa
	int i;
	int kx[2050];
	int ky[2050];
	ifstream f;
	f.open("graf.txt");
	while (!f.eof()) {
		f >> i;
		f >> kx[i] >> ky[i];
		n++;
	}

	//varosok kozotti tavolsagok meghatarozasa
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			szm[i][j] = sqrt((kx[j] - kx[i]) * (kx[j] - kx[i]) + (ky[j] - ky[i]) * (ky[j] - ky[i]));
		}
		feldolgozott[i] = 0;
	}

	//tavolsagok kiirasa. sok varos eseten nem ajanlott.

	/*cout << endl << "Szomszedsagi: " << endl;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			cout << szm[i][j] << "\t";
		}
		cout << endl;
	}*/
	f.close();
}


//adott v indexu varostol legkisebb tavolsagra levo varos kiszamolasa, feldolgozasa (Djikstra kb)
int greedymin(int v)
{
	double min = 999999;
	int uv = -1;

	for (int i = 1; i < n; i++)
	{
		if ((szm[v][i] != 0) && (feldolgozott[i] == 0))
			if (szm[v][i]< min)
			{
				min = szm[v][i]; 
				uv = i;
			}
	}

	//ha talaltunk utat akkor noveljuk az utvonalunk hosszat
	if (min != 999999)
		minut += min;

	return uv;
}

//utvonal kiszamitasa es kiirasa. a fuggveny rekurziv hivasaival lepegetunk varosrol varosra
void szamolut(int varos)
{
	int i, ujvaros;

	feldolgozott[varos] = 1;

	cout << varos << "->";
	ujvaros = greedymin(varos);

	//ha befejeztuk utunkat, az utolso lepesunk, hogy visszalepjunk a kiindulo poziciora (elso varos). ennek ertelmeben az utvonal hosszahoz meg hozzaadjuk ezt a tavolsagot.
	if (ujvaros == -1)
	{
		ujvaros = 1;
		cout << ujvaros;
		minut += szm[varos][ujvaros];
		return;
	}

	szamolut(ujvaros);
}

int main()
{
	beolvas();

	cout << "Az utvonal:" << endl;
	szamolut(1);
	cout << endl;

	cout << "Az ut hossza (minimalis): " << minut;

	return 0;
}