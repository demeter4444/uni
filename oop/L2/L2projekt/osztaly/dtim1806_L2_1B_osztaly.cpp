//Demeter Tamas
//dtim1806
//511/2
//L2

#include <iostream>

using namespace std;

class intervallum {
	double *intervallumm;
public:
	intervallum(double a, double b);
	~intervallum();
	void duplaz();
	void kiir();
};

intervallum::intervallum(double a, double b) {
	if (a > b) {
		double t = a;
		a = b;
		b = a;
	}
	intervallumm = new double[2];
	intervallumm[0] = a;
	intervallumm[1] = b;
}

 intervallum::~intervallum() {
	 printf("destruktor meghivva \n");
	delete[] intervallumm;
}

void intervallum::duplaz() {
	double k = ((intervallumm[0] + intervallumm[1]) / 2) - intervallumm[0];
	intervallumm[0] = intervallumm[0] - k;
	intervallumm[1] = intervallumm[1] + k;
}

void intervallum::kiir() {
	printf("(%f , %f)\n", intervallumm[0], intervallumm[1]);
}

int main() {

	double elso1 = 0;
	double masodik1 = 4;
	double elso2 = 1;
	double masodik2 = 3;
	intervallum i1(elso1, masodik1), i2(elso2, masodik2);
	i1.kiir();
	i1.duplaz();
	i1.kiir();
	
	i2.kiir();
	i2.duplaz();
	i2.kiir();
	return 0;
}