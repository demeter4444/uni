//Demeter Tamas
//dtim1806
//511/2
//L2

#include <iostream>

using namespace std;

static double *intervallum;

void init(double a, double b) {
	if (a > b) {
		double t = a;
		a = b;
		b = a;
	}

	intervallum = new double [2];
	intervallum[0] = a;
	intervallum[1] = b;
}

void felsz() {
	delete[] intervallum;
}

void duplaz() {
	double k = ((intervallum[0] + intervallum[1]) / 2)-intervallum[0];
	intervallum[0] -=  k;
	intervallum[1] +=  k;
}

void kiir() {
	printf("(%f , %f)\n", intervallum[0], intervallum[1]);
}

