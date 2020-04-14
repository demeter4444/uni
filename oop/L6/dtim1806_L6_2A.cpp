//Demeter Tamas
//511/2
//dtim1806
//L6_2A

#include <iostream>

using namespace std;

class KMatrix{
	double a11, a12, a21, a22;
public:
	KMatrix(double b11,double b12,double b21,double b22);
	KMatrix operator +(KMatrix M2);
	KMatrix& operator +=(KMatrix M2);
	KMatrix operator *(KMatrix M2);
	KMatrix& operator *=(KMatrix M2);
	double operator ~();
	void ki();
};

KMatrix::KMatrix(double b11, double b12, double b21, double b22) {
	a11 = b11;
	a12 = b12;
	a21 = b21;
	a22 = b22;
}

KMatrix KMatrix::operator +(KMatrix M2) {
	KMatrix temp(a11, a12, a21, a22);
	temp.a11 += M2.a11;
	temp.a12 += M2.a12;
	temp.a21 += M2.a21;
	temp.a22 += M2.a22;
	return temp;
}

KMatrix& KMatrix::operator +=(KMatrix M2) {
	KMatrix temp(a11, a12, a21, a22);
	this->a11 += M2.a11;
	this->a12 += M2.a12;
	this->a21 += M2.a21;
	this->a22 += M2.a22;
	return *this;
}

KMatrix KMatrix::operator *(KMatrix M2) {
	KMatrix temp(a11, a12, a21, a22);
	temp.a11 = temp.a11*M2.a11 + temp.a12*M2.a21;
	temp.a12 = temp.a11*M2.a12 + temp.a12*M2.a22;
	temp.a21 = temp.a21*M2.a11 + temp.a22*M2.a21;
	temp.a22 = temp.a21*M2.a12 + temp.a22*M2.a22;
	return temp;
}

KMatrix& KMatrix::operator *=(KMatrix M2) {
	KMatrix temp(a11, a12, a21, a22);
	this->a11 = temp.a11*M2.a11 + temp.a12*M2.a21;
	this->a12 = temp.a11*M2.a12 + temp.a12*M2.a22;
	this->a21 = temp.a21*M2.a11 + temp.a22*M2.a21;
	this->a22 = temp.a21*M2.a12 + temp.a22*M2.a22;
	return *this;
}

double KMatrix::operator ~() {
	KMatrix temp(a11, a12, a21, a22);
	return temp.a11*temp.a22 - temp.a12*temp.a21;
}

void KMatrix::ki() {
	printf("%f %f\n%f %f\n", a11, a12, a21, a22);
}


int main() {

	KMatrix a(1.1, 2.2, 3.3, 4.4);
	KMatrix b(5.5, 6.6, 7.7, 8.8);
	a.ki();
	printf("\n");
	b.ki();
	printf("\n");
	printf("%f", ~a);
	cout << endl;
	(a + b).ki();
	cout << endl;
	(a*b).ki();
	cout << endl;
	(a += b).ki();
	cout << endl;
	(a *= b).ki();
	return 0;
}