#include <iostream>

using namespace std;

class rac {
protected:
	int sz;
	int n;
public:
	rac(int szamlalo = 0, int nevezo = 1) {
		sz = szamlalo;
		n = nevezo;
	}
	void kiir() {
		cout << sz << "/" << n << endl;
	}
	virtual rac operator/(const rac& r) {
		rac temp(sz, n);
		temp.sz *= r.n;
		temp.n *= r.sz;
		return temp;
	}
	virtual rac operator/=(const rac& r) {
		*this = *this / r;
		return *this;
	}
	int getsz() const {
		return sz;
	}
	int getn() const {
		return n;
	}
};

class rackiir : public rac {
public:
	rackiir(int szamlalo = 0, int nevezo = 1) {
		sz = szamlalo;
		n = nevezo;
	}
	rac operator/(const rac& r) {
	rac temp(sz*r.getn(), n*r.getsz());
	cout << "(" << this->sz << "/" << this->n << ")/(" << r.getsz() << "/" << r.getn() << ") =" << temp.getsz() << "/" << temp.getn() << endl;
	return temp;
	}

};

void main() {

	rac p(3, 4), q(5, 2), r;

	r = p /= q;

	p.kiir();

	r.kiir();

	rackiir p1(3, 4), q1(5, 2);

	rac r1, r2;

	r1 = p1 / q1;

	r2 = p1 /= q1;

	p1.kiir();

	r1.kiir();

	r2.kiir();

}