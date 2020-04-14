//Demeter Tamas
//511/2
//dtim1806
//P1

//A tesztelo program sikeresen lefutott 
//Minden teszt helyes volt

#include <iostream>
#include "NagyEgesz.h"

using namespace std;

int main() {

	int x[10] = { 1,2,3,4,5,6,7,8,9,1 };
	int y[5] = { 1,2,3,4,5 };

	NagyEgesz a(1, 10, x);
	NagyEgesz b(1, 5, y);
	NagyEgesz c;
	int p[1] = { 1 };
	NagyEgesz egy(1, 1, p);
	cout << "a=";
	a.kiir();
	cout << "b=";
	b.kiir();
	NagyEgesz nulla;
	cout << "a==b?" << endl;
	cout << (a == b) << endl;;
	cout << "b==0?" << endl;
	cout << (b == nulla) << endl;
	cout << endl;
	cout << "a+b=";
	a.osszead(b).kiir();
	cout << "a-b=";
	a.kivon(b).kiir();
	cout << "a == b?" << endl;
	cout << (a == b) << endl;
	cout << "a*b=";
	a.szoroz(b).kiir();
	cout << endl;
	cout << "a/b=";
	try {
		a.oszt(b).kiir();
	}
	catch (NagyEgesz::NullavalValoOsztas z) {
		cout << "Nullaval valo osztas!";
	}
	
	return 0;
}