//Demeter Tamas
//dtim1806
//511/2
//L5_2a

#include <iostream>

using namespace std;

template <class Type>
Type Fibonacci(int index, Type elso, Type masodik) {
	Type f1 = elso;
	Type f2 = masodik;
	Type f3 = f1 + f2;
	if (index <= 1) return 1;
	for (int i = 2; i < index; i++) {
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}
	return f3;
}

int main() {
	int x = 1;
	float y = 1.0;
	double z = 1.0;
	cout << Fibonacci(1, x, x) << endl;
	cout << Fibonacci(2, y, y) << endl;
	cout << Fibonacci(3, z, z) << endl;
	return 0;
}