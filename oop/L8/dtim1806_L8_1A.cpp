#include <iostream>

using namespace std;

/*1 statute mile = 8 furlong = 1760 yard = 1609, 344 m
1 furlong = 40 pole = 201, 16 m
1 pole / perch / rod = 5, 5 yard = 5, 03 m
1 fathom = 2 yard = 1, 83 m*/
class Hossz_m;

class Hossz_f {
	int fathom;
	int pole;
	int furlong;
	int statute_mile;
public:
	Hossz_f(int fa, int p, int fu, int s);
	int getfa() const;
	int getp() const;
	int getfu() const;
	int getst() const;
	//operator Hossz_m();

};


class Hossz_m {
	int m;
	int dam;
	int hm;
	int km;
	double maradek;
public:
	void kiir();
	Hossz_m(int kilo, int hekto, int deka, int meter, double mar);
	Hossz_m(const Hossz_f& f);
};


int Hossz_f::getfa() const {
	return fathom;
}

int Hossz_f::getp() const {
	return pole;
}

int Hossz_f::getfu() const {
	return furlong;
}

int Hossz_f::getst() const {
	return statute_mile;
}

Hossz_m::Hossz_m(int kilo, int hekto, int deka, int meter, double mar) {
	km = kilo;
	hm = hekto;
	dam = deka;
	m = meter;
	maradek = mar;
}

void Hossz_m::kiir() {
	cout << km << " km " << hm << " hm " << dam << " dam " << m << " m " << maradek << " maradek ";
}

Hossz_f::Hossz_f(int fa, int p, int fu, int s) {
	fathom = fa;
	pole = p;
	furlong = fu;
	statute_mile = s;
}

Hossz_m::Hossz_m(const Hossz_f& f) {
	double meter = f.getst()*1609.344 + f.getfu()*201.16 + f.getp()*5.03 + f.getfa()*1.83;
	m = trunc(meter);
	maradek = meter - m;
	//cout << m << "*";
	//cout << maradek << "*";
	km = m / 1000;
	m = m - km * 1000;
	hm = m / 100;
	m = m - hm * 100;
	dam = m / 10;
	m = m - dam * 10;
}

/*
Hossz_f::operator Hossz_m() {
	double meter = statute_mile*1609.344 + furlong*201.16 + pole*5.03 + fathom*1.83;
	int m = trunc(meter);
	double maradek = meter - m;
	//cout << m << "*";
	//cout << maradek << "*";
	int km = m / 1000;
	m = m - km * 1000;
	int hm = m / 100;
	m = m - hm * 100;
	int dam = m / 10;
	m = m - dam * 10;
	return Hossz_m(km, hm, dam, m, maradek);
}
*/
//fathom pole furlong statutemile
int main() {
	Hossz_f a(0, 0, 0, 2);
	Hossz_m b = a;
	b.kiir();
}