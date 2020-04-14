//Demeter Tamas
//dtim1806
//511/2
//L2

#include <iostream>

using namespace std;

namespace intervallum {
	 double *intervallum;

	 void init(double a, double b);
	 void felsz();
	 void duplaz();
	 void kiir();
}

void intervallum::init(double a, double b) {
	if (a > b) {
		double t = a;
		a = b;
		b = a;
	}
	intervallum = new double[2];
	intervallum[0] = a;
	intervallum[1] = b;


}

void intervallum::felsz() {
	delete[]intervallum;
}

void intervallum::duplaz() {
	double k = ((intervallum[0] + intervallum[1]) / 2) - intervallum[0];
	intervallum[0] = intervallum[0] - k;
	intervallum[1] = intervallum[1] + k;

}

void intervallum::kiir() {
	printf("(%f , %f)\n", intervallum[0], intervallum[1]);
}

int main() {

	using namespace intervallum;

	double elso = -2;
	double masodik = 6;
	init(elso, masodik);
	kiir();
	duplaz();
	kiir();
	felsz();

	return 0;
}