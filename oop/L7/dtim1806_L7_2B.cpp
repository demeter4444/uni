//Demeter Tamas
//dtim1806
//511/2
//L7_2B

#include <iostream>

using namespace std;

class Komplex {

	double re;
	double im;
public:
	Komplex(double = 0, double = 0);
	Komplex(const double& x);
	Komplex(const int& x);
	void kiir();
	Komplex& operator *=(const Komplex &i);
	Komplex& operator /=(const Komplex &i);

};

Komplex::Komplex(double a, double b) {
	re = a;
	im = b;
}

Komplex::Komplex(const double& x) {
	re = x;
	im= 0.0;
}

Komplex::Komplex(const int& x) {
	re = (double)x;
	im = 0.0;
}

void Komplex::kiir() {
	if (im == 0) {
		cout << re;
	}
	else if (im < 0) {
		cout << re << " " << im;
	}
	else {
		cout << re << " +" << im;
	}
	cout << endl;
}

Komplex& Komplex::operator *=(const Komplex &i) {
	if (i.im != 0) im = im * i.im;
	else im = im * i.re;
	re = re * i.re;
	return *this;
}

Komplex& Komplex::operator /=(const Komplex &i) {
	if (i.im != 0) im = im / i.im;
	else im = im / i.re;
	re = re / i.re;
	return *this;
}

int main() {

	/*Komplex z1(1.2, -3);
	Komplex z2(2.5, 2.7);
	double x = 5;
	z2.kiir();*/
	
	Komplex a(1, 5);
	a.kiir();
	a *= 2;      // előbb 2-ről Komplex-re konvertál
	a.kiir();
	a /= 2;      // előbb 2-ről Komplex-re konvertál
	a.kiir();
	Komplex b(5);
	b.kiir();    // Az imaginárius rész 0. Kimenet: 5
	
	return 0;
}