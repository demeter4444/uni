//Demeter Tamas
//dtim1806
//511/2

#include <iostream>
#include <math.h>

using namespace std;

double hatv(int x, int h) {
	return pow(x, h);
}

double hatv(int x) {
	return pow(x, x);
}


int main() {

	int n;
	cout << "N =";
	cin >> n;

	cout << hatv(n, 2) << endl;
	cout << hatv(n) << endl;
	

	return 0;
}