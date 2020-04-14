//Demeter Tamas
//dtim1806
//511/2
//L9 b

#include <iostream>
#include <cmath>

#define pi 3.1415

using namespace std;

class Alakzat {
public:
	virtual double terulet()=0;
	virtual double kerulet()=0;
	virtual void nagyit(double s)=0;
};

class Haromszog : public Alakzat {
protected:
	double o1, o2, o3;
public:
	Haromszog() {
		o1 = 1;
		o2 = 1;
		o3 = 1;
	}
	Haromszog(double a,double b,double c) {
		o1 = a;
		o2 = b;
		o3 = c;
	}
	double kerulet() {
		return o1 + o2 + o3;
	}
	double terulet() {
		double f = kerulet() / 2;
		return sqrt(f*(f - o1)*(f - o2)*(f - o3));
	}
	void nagyit(double s) {
		o1 += s;
		o2 += s;
		o3 += s;
	}
};

class Kor : public Alakzat {
	double r;
public:
	Kor(double a) {
		r = a;
	}
	double kerulet() {
		return 2 * pi*r;
	}
	double terulet() {
		return pi * r*r;
	}
	void nagyit(double s) {
		r += s;
	}
};

class DerekszoguHaromszog : public Haromszog {
public:
	DerekszoguHaromszog(double x,double y, double z){
		if ((x*x == y * y + z * z) || (y*y == x * x + z * z) || (z*z == x * x + y * y)) {
			o1 = x;
			o2 = y;
			o3 = z;
		}
		else throw "Nem derekszogu!";
	}
};

int main() {

	Alakzat *a[] = { new Kor(3), new Haromszog, new DerekszoguHaromszog(3,4,5) };

	cout << a[0]->kerulet() << ", " << a[0]->terulet() << endl;

	cout << a[1]->kerulet() << ", " << a[1]->terulet() << endl;

	cout << a[2]->kerulet() << ", " << a[2]->terulet() << endl;

	try {
		DerekszoguHaromszog X(1, 2, 2);
	}
	catch (const char* s) {
		cout << s << endl;
	}
	return 0;
}