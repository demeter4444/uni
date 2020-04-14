//Demeter Tamas
//dtim1806
//511/2

#include <iostream>
#include <math.h>

using namespace std;

double &negyzet(double x) {
	double temp = x * x;
	return temp;
}

double &negyzetgyok(double x) {
	double temp = sqrt(x);
	return temp;
}

double &reciprok(double x) {
	double temp = 1 / x;
	return temp;
}

void vegrehajt(double &ertek, double &func(double ertek)) {
	cout << func(ertek);
}

int main() {
	double n;

	cout << "ertek = ";
	cin >> n;

	vegrehajt(n, negyzet);
	cout << endl;
	vegrehajt(n, negyzetgyok);
	cout << endl;
	vegrehajt(n, reciprok);

	return 0;
}