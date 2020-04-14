//Demeter Tamas
//511/2
//dtim1806
//P1

//A tesztelo program sikeresen lefutott 
//Minden teszt helyes volt

#include <iostream>
#include "NagyEgesz.h"

using namespace std;

//ket int felcserelese
void swap(int& a, int& b) { 
	int t = a;
	a = b;
	b = t;
}

//egy tomb megforditasa
void reverse(int n, int* x) {
	for (int i = 0; i < n/2; i++) {
		swap(x[i], x[n - i-1]);
	}
}

//alapertelmezett konstruktor
NagyEgesz::NagyEgesz() {
	hossz = 1;
	e = 1;
	szam = new int;
	szam[0] = 0;
}

//parameteres konstruktor
NagyEgesz::NagyEgesz(int elojel, int n, const int* szamjegyek) {
	e = elojel;
	hossz = n;
	szam = new int[n];
	for (int i = 0; i < hossz; i++) {
		szam[i] = szamjegyek[i];
	}
}

//masolo konstruktor
NagyEgesz::NagyEgesz(const NagyEgesz& x) {
	hossz = x.hossz;
	e = x.e;
	szam = new int[hossz];
	for (int i = 0; i < hossz; i++) {
		szam[i] = x.szam[i];
	}
}

//= operator, hogy konyebb legyen az atadas.
NagyEgesz NagyEgesz::operator=(const NagyEgesz& x) {
	hossz = x.hossz;
	e = x.e;
	szam = new int[hossz];
	for (int i = 0; i < hossz; i++) {
		szam[i] = x.szam[i];
	}

	//a folosleges 0akat hanyagoljuk 
	while (szam[0] == 0) {
		
		for (int i = 0; i < hossz; i++) {
			szam[i] = szam[i + 1];
		}
		hossz--;
	}

	return *this;
}

//== operator, osszehasonlitasra
bool NagyEgesz::operator==(const NagyEgesz& x) {
	

	bool egyenlo = true;
	int i = 0;
	int j = 0;

	//folosleges 0ak ha vannak, nem rontja el(ugy vesszuk, hogy a szam*ba lehetnek folosleges 0-ak, ha a hossz valtozo ezt nem veszi figyelembe.
	while (j < x.hossz) {
		if (x.szam[i] != 0) break;
		j++;
	}

	while (i < hossz) {
		if (szam[i] != 0) break;
		i++;
	}
	
	//specialis esetek (0==0,stb)
	if ((i == hossz) && (j == x.hossz)) return true;
	if ((i == hossz) || (j == x.hossz)) return false;
	if (hossz != x.hossz) return false;

	while ((i < hossz) && (j < x.hossz)) {
		if (szam[i] != x.szam[j]) {
			egyenlo = false;
		}
		i++;
		j++;
	}

	return egyenlo;
}

//kiir
void NagyEgesz::kiir() const {
	if (e == -1)cout << "-";
	int n = 0;
	for (int i = 0; i < hossz; i++) {
		if (szam[i] != 0) n = 1;
		if (n==1) cout << szam[i] ;
	}
	if (n == 0) cout << 0;
	cout << endl;
}

//destruktor
NagyEgesz::~NagyEgesz() {
	delete[] szam;
}

//osszeadas
NagyEgesz NagyEgesz::osszead(const NagyEgesz& x) {

	NagyEgesz eredmeny;
	//elojelek alapjan beallitjuk az eredmeny elojelet, vagy kivonast vegzunk
	if ((e == -1) && (x.e == 1)) {
		NagyEgesz temp(*this);
		temp.e = 1;
		NagyEgesz temp2(x);
		return temp2.kivon(temp);
	}
	if ((e == 1) && (x.e == -1)) {
		NagyEgesz temp(x);
		temp.e = 1;
		return this->kivon(temp);
	}
	if ((e == -1) && (x.e == -1)) {
		eredmeny.e = -1;
	}
	if ((e == 1) && (x.e == 1)) {
		eredmeny.e = 1;
	}

	//szamokat megforditjuk
	int carry = 0;
	NagyEgesz rovidebb = hossz <= x.hossz ? *this : x;
	NagyEgesz hosszabb = hossz > x.hossz ? *this : x;
	reverse(rovidebb.hossz,rovidebb.szam);
	reverse(hosszabb.hossz,hosszabb.szam);

	//az eredmeny hossza legfennebb a ket szam kozul a hosszabbik hossza+1
	
	eredmeny.hossz = hosszabb.hossz + 1;
	eredmeny.szam = new int[eredmeny.hossz];
	for (int i = 0; i < hosszabb.hossz; i++) {
		eredmeny.szam[i] = hosszabb.szam[i];
	}
	eredmeny.szam[hosszabb.hossz] = 0;

	//rovidebbig megyunk, elvegezzuk a papiron valo osszeadas algoritmusat
	int i = 0;
	for (i = 0; i < rovidebb.hossz; i++) {
		eredmeny.szam[i] = eredmeny.szam[i] + rovidebb.szam[i] + carry;
		if (eredmeny.szam[i] > 9) {
			eredmeny.szam[i] %= 10;
			carry = 1;
		}
		else carry = 0;
	}

	eredmeny.szam[i] += carry;

	//visszaforditjuk, ha maradt carry betesszuk, ha nem 0 marad. = operator gondoskodik rola, kiir nem irja ki.
	reverse(eredmeny.hossz, eredmeny.szam);
	

	

	return eredmeny;
}

//kivonas
NagyEgesz NagyEgesz::kivon(const NagyEgesz& x) {

	NagyEgesz kisebb;
	NagyEgesz nagyobb;
	int carry = 0;
	int tempe = 0;

	//meghatarozzuk a kisebbik es nagyobbikat.
	if (hossz == x.hossz) {
		int i = 0;
		bool egyenlo = true;
		while (szam[i] == x.szam[i]) {
			if (szam[i] != x.szam[i])egyenlo = false;
			i++;
		}
		if ((i == hossz) && (egyenlo == true)) { 
			NagyEgesz nulla;
			return nulla;
		}
		else {
			kisebb = szam[i] <= x.szam[i] ? *this : x;
			nagyobb = szam[i] > x.szam[i] ? *this : x;
		}

	}
	else {
		kisebb = hossz <= x.hossz ? *this : x;
		nagyobb = hossz > x.hossz ? *this : x;
	}

	//elojel kezelesek az aktualis objektum es a hivott parameter sorrendjei es egymashoz viszonyitott nagysagai szerint.
	//letezik -0 es +0 de nem befolyasol semmit kulonosen.

	if ((e == 1) && (x.e == 1)) {
		if (*this == nagyobb) {
			tempe = 1;
		}
		else tempe = -1;
	}

	if ((e == 1) && (x.e == -1)) {
		NagyEgesz temp(x);
		temp.e = 1;
		return temp.osszead(*this);
	}

	if ((e == -1) && (x.e == 1)) {
		NagyEgesz temp(x);
		temp.e = -1;
		return temp.osszead(*this);
	}

	if ((e == -1) && (x.e == -1)) {
		if (*this == nagyobb) {
			tempe = -1;
		}
		else tempe = 1;
	}


	//megforditjuk a szamokat a konyebb szamolasert
	reverse(kisebb.hossz, kisebb.szam);
	reverse(nagyobb.hossz, nagyobb.szam);

	//elvegezzuk a papiron valo kivonas algoritmusat
	int i;
	for (i = 0; i < kisebb.hossz; i++) {
		nagyobb.szam[i] = nagyobb.szam[i] - kisebb.szam[i] - carry;
		if (nagyobb.szam[i] < 0) {
			nagyobb.szam[i] += 10;
			carry = 1;
		}
		else carry = 0;
	}

	//ha marad carrynk elintezzuk. biztos nem lesz vegtelen ciklus.
	while (carry == 1) {
		nagyobb.szam[i] -= 1;
		if (nagyobb.szam[i] < 0) {
			nagyobb.szam[i] += 10;
			carry = 1;
		}
		else carry = 0;
		i++;
	}

	//visszaforditjuk
	reverse(nagyobb.hossz, nagyobb.szam);
	nagyobb.e = tempe;
	return nagyobb;
}

//szorzas
NagyEgesz NagyEgesz::szoroz(const NagyEgesz& x) {

	NagyEgesz kisebb;
	NagyEgesz nagyobb;

	//meghatarozzuk a ketto kozul melyik a kisebb s nagyobb
	if (hossz == x.hossz) {
		int i = 0;
		while (szam[i] == x.szam[i]) {
			i++;
		}
		if (i == hossz) {
			kisebb = *this;
			nagyobb = x;
		}
		else {
			kisebb = szam[i] <= x.szam[i] ? *this : x;
			nagyobb = szam[i] > x.szam[i] ? *this : x;
		}

	}
	else {
		kisebb = hossz <= x.hossz ? *this : x;
		nagyobb = hossz > x.hossz ? *this : x;
	}

	
	NagyEgesz eredmeny;
	int p[1] = { 1 };
	NagyEgesz egy(1, 1, p);
	NagyEgesz nulla;

	//elojel targyalas
	int tempe;
	if ((kisebb.e == 1) && (nagyobb.e == 1)) {
		tempe = 1;
	}
	if ((kisebb.e == -1) && (nagyobb.e == 1)) {
		tempe = -1;
	}
	if ((kisebb.e == 1) && (nagyobb.e == -1)) {
		tempe = -1;
	}
	if ((kisebb.e == -1) && (nagyobb.e == -1)) {
		tempe = 1;
	}

	nagyobb.e = 1;
	kisebb.e = 1;

	//ismetelt osszeadas
	while (!(kisebb==nulla)) {
		eredmeny = eredmeny.osszead(nagyobb);
		kisebb = kisebb.kivon(egy);
	}
	eredmeny.e = tempe;
	return eredmeny;

}

//osztas
NagyEgesz NagyEgesz::oszt(const NagyEgesz& x) {

	NagyEgesz kisebb(*this);
	NagyEgesz nagyobb(x);
	NagyEgesz nulla;
	
	//kivetel
	if (nagyobb == nulla) {
		throw NullavalValoOsztas();
	}

	//elojel
	int tempe;
	if ((kisebb.e == 1) && (nagyobb.e == 1)) {
		tempe = 1;
	}
	if ((kisebb.e == -1) && (nagyobb.e == 1)) {
		tempe = -1;
	}
	if ((kisebb.e == 1) && (nagyobb.e == -1)) {
		tempe = -1;
	}
	if ((kisebb.e == -1) && (nagyobb.e == -1)) {
		tempe = 1;
	}

	int p[1] = { 1 };
	NagyEgesz egy(tempe, 1, p);

	//kisebb/nagyobb
	if (hossz == x.hossz) {
		int i = 0;
		bool egyenlo = true;
		while (szam[i] == x.szam[i]) {
			if (szam[i] != x.szam[i])egyenlo = false;
			i++;
		}
		if ((i == hossz) && (egyenlo == true)) {
			
			return egy;
		}
		else {
			kisebb = szam[i] <= x.szam[i] ? *this : x;
			nagyobb = szam[i] > x.szam[i] ? *this : x;
		}

	}
	else {
		kisebb = hossz <= x.hossz ? *this : x;
		nagyobb = hossz > x.hossz ? *this : x;
	}

	if (*this == kisebb) {
		return nulla;
	}
	
	nagyobb.e = 1;
	kisebb.e = 1;
	NagyEgesz eredmeny;
	//ismetelt kivonas
	while (nagyobb.e == 1) {
		eredmeny = eredmeny.osszead(egy);
		nagyobb = nagyobb.kivon(kisebb);
	}
	eredmeny = eredmeny.kivon(egy);

	return eredmeny;


}

