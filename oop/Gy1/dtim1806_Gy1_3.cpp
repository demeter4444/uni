//Demeter Tamas
//dtim1806

#include <iostream>

using namespace std;

int a(int b) {
	return b;
}
int a(int b, int c = 0) {
	return 2 * b;
}

int main() {

	//cout << a(2) << endl;
	cout << a(2, 1) << endl;

	return 0;
}

//a masodik valtozat helyes, az elsot nem lehet meghivni, mert a masodik parameter ondefinialt.