//Demeter Tamas
//511/2
//dtim1806
//L6_2B
#include <iostream>

using namespace std;

class Intervallum {
	int i1, i2;
public:
	Intervallum(int a1, int a2);
	void ki();
	Intervallum& operator --();
	Intervallum operator --(int);
};

Intervallum::Intervallum(int a1, int a2) {
	const char* x = "Hibas intervallum";
	if (a1 > a2) {
		throw x;
	}
	i1 = a1;
	i2 = a2;
}

void Intervallum::ki() {
	printf("[%d, %d]\n", i1, i2);
}

Intervallum& Intervallum::operator --() {
	i1++;
	i2--;
	return *this;
}

Intervallum Intervallum::operator --(int) {
	Intervallum temp(i1, i2);
	i1++;
	i2--;
	return temp;
}

int main() {
	Intervallum a(1, 3);
	try {
		Intervallum b(3, 1);
	}
	catch (const char* x) {
		cout << x << endl;
	}
	a.ki();
	//b.ki();
	(--a).ki();
	(a--).ki();
	a.ki();
	
	return 0;
}