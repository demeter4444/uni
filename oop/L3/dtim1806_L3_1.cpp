//Demeter Tamás
//511
//dtim1806
//L3

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

const double pi = 3.1415;

class Pont {
private:
	double x, y;
public:
	Pont() {
		x = 0;
		y = 0;
	}
	Pont(double _x, double _y) {
		x = _x;
		y = _y;
	}
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	void kiir() {
		printf("(%f,%f)\n", x, y);
	}
};

class Kor {
private:
	Pont kp;
	double r;
public:
	Kor():kp() {
		r = 1;
	}
	Kor(Pont _kp, double _r):kp(_kp) {
		kp = _kp;
		r = _r;
	}
	double Kerulet() {
		return 2 * pi * r;
	}
	double Terulet() {
		return pi * r * r;
	}
	Pont randomPont() {
		double fi = rand() / (2 * pi);
		double x = r * cos(fi);
		double y = r * sin(fi);
		Pont random(x+kp.getX(), y+kp.getY());
		return random;
	}
};

int main() {

	srand(time(NULL));

	Pont a;
	Pont b(2, 4);
	a.kiir();
	b.kiir();

	Kor k1;
	printf("%f\n", k1.Kerulet());
	printf("%f\n", k1.Terulet());
	k1.randomPont().kiir();

	return 0;
}