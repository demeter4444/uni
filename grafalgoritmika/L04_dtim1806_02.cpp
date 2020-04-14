//Demeter Tamas
//dtim1806
//511/2
//L4 3

#include <iostream>
#include <fstream>

using namespace std;

struct cspont { //huffmann binarisfa-beli csomopont jellemzoi 
	char kar; //karakter
	int ertek; //elofordulas
	cspont* bal; //bal ag
	cspont* jobb; //jobb ag
};

struct fa { //huffmann binaris fa jellemzoi
	int meret; //aktualis meret
	int maxmeret; //maximalis meret(elhanyagolhato)
	struct cspont** cspontok; //csomopontok
};

struct cspont* ujcspont(char adat, int szam) { //uj csomopont letrehozasa adott karakterre es elofordulasra

	struct cspont* temp = new cspont;

	temp->bal = NULL;
	temp->jobb = NULL;
	temp->kar = adat;
	temp->ertek = szam;

	return temp;

}

void cserel(struct cspont*& x, struct cspont*& y) { //ket csomopont felcserelese
	cspont* temp = x;
	x = y;
	y = temp;
}

struct fa* ujfa(int cap) { //fa letrehozasa adott maxmeretre
	struct fa* ujfa = new fa;
	ujfa->meret = 0;
	ujfa->maxmeret = cap;
	ujfa->cspontok = new cspont*[ujfa->maxmeret];
	return ujfa;
}

void felepitfa(struct fa* f, int i) { //binaris-fa felepito standard algoritmus(ihlet)

	int min = i;
	int bal = 2 * i + 1;
	int jobb = 2 * i + 2;

	if (bal < f->meret && f->cspontok[bal]->ertek < f->cspontok[min]->ertek) {
		min = bal;
	}

	if (jobb < f->meret && f->cspontok[jobb]->ertek < f->cspontok[min]->ertek) {
		min = jobb;
	}

	if (min != i) {
		cserel(f->cspontok[min],f->cspontok[i]);
		felepitfa(f, min);
	}
}

int egyelem(struct fa* f) { //lecsekkolja ha egy eleme van-e a fanak
	return (f->meret == 1);
}

struct cspont* kiveszmin(struct fa* f) { //kiveszi a minimalis erteku csomopontot a fabol

	struct cspont* temp = f->cspontok[0];
	f->cspontok[0] = f->cspontok[f->meret - 1];
	--f->meret;
	felepitfa(f, 0);
	return temp;
}

void beteszcspont(struct fa* f, struct cspont* cs) { //betesz egy csomopontot a faba

	++f->meret;
	int i = f->meret - 1;
	while (i && cs->ertek < f->cspontok[(i - 1) / 2]->ertek) {
		f->cspontok[i] = f->cspontok[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	f->cspontok[i] = cs;
}

void letrehozfa(struct fa* f) { //a fafelepito standard algoritmust hasznalva, felepit egy adott mutatoju fat.
	int n = f->meret - 1;
	for (int i = (n - 1) / 2; i >= 0; i--) {
		felepitfa(f, i);
	}
}

void kiir(int v[], int n) { //kiir egy n elemu v vektort (kodok)
	for (int i = 0; i < n; ++i) {
		cout << v[i];
	}
	cout << endl;
}

int level(struct cspont* cs) { //lecskekkolja, hogy level-e az adott csomopont(nincs bal es jobb leszarmazott)

	return !(cs->bal) && !(cs->jobb);

}

struct fa* letrehozesfelepitfa(char adat[], int ertek[], int meret) { //adott karakter-elofordulas tombokbol es meretbol letrehoz es felepit egy uj fat

	struct fa* f = ujfa(meret);
	for (int i = 0; i < meret; i++) {
		f->cspontok[i] = ujcspont(adat[i], ertek[i]);
	}

	f->meret = meret;
	letrehozfa(f);
	return f;
}

struct cspont* huffmann(char adat[], int ertek[], int meret) { //az  elozo algorimussal letrehoz es felepit egy uj fat, majd elvegzi a huffmann algoritmust rajta.
	struct cspont* bal, *jobb, *szulo;
	struct fa* f= letrehozesfelepitfa(adat, ertek, meret);

	while (!egyelem(f)) {
		bal = kiveszmin(f);
		jobb = kiveszmin(f);
		szulo = ujcspont('*', bal->ertek + jobb->ertek); // a "betu nelkuli" csomopontokat *-al "indexeljuk"
		szulo->bal = bal;
		szulo->jobb = jobb;
		beteszcspont(f, szulo);
	}

	return kiveszmin(f); //az egyszeruseg kedveert a fuggveny a letrehozott fanak a gyokerenek a cimet teriti vissza
}

void kodok(struct cspont* gyok, int v[], int i) { //kiirja a huffmann-kodokat rekurzio segitsegevel (melysegi bejaras, pretty much)

	if (gyok->bal) {
		v[i] = 0;
		kodok(gyok->bal, v, i + 1);
	}

	if (gyok->jobb) {
		v[i] = 1;
		kodok(gyok->jobb, v, i + 1);
	}

	if (level(gyok)) {
		cout << gyok->kar << ": ";
		kiir(v, i);
	}
}

int main() {

	ifstream f;
	f.open("graf.txt");
	char x;

	int stat[128] = { 0 }; //kezdeti statisztikavektor a karaktereknek

	while (!f.eof()) { //beolvassuk karakterenkent a fajlt (bitenkent)
		f >> x;
		stat[x]++;
	}

	char chars[128] = {}; // tovabbi karakter-elofordulas vektorpar, hogy lehetove tegye a rendezest es praktikus hasznalatot
	int vals[128] = {};
	int count = 0;

	for (int i = 0; i < 128; i++) { 
		if (stat[i] > 0) {
			chars[count] = (char)i;
			vals[count] = stat[i];
			count++;
		}
	}

	for (int i = 0; i < count-1; i++) { //rendezes novekvo sorrendbe
		for (int j = i + 1; j < count; j++) {
			if (vals[i] > vals[j]) {
				char tempc = chars[i];
				int tempval = vals[i];
				vals[i] = vals[j];
				chars[i] = chars[j];
				vals[j] = tempval;
				chars[j] = tempc;
			}
		}
	}

	for (int i = 0; i < count; i++) { //statisztika kiirasa
		cout << chars[i] << " : " << vals[i] << endl;
	}

	struct cspont* gyoker = huffmann(chars, vals, count); //huffmann elvegzese
	int v[100];
	int i = 0;
	cout << endl << "Kodok:" << endl;
	kodok(gyoker, v, i);

	f.close();
	return 0;
}