//Demeter Tamas
//511
//dtim1806
//L41a

#include <iostream>

using namespace std;

 char* keres(char*x, char*y) {
	const char*c = "Nincs";

	while (*x) {

		char*start = x;
		char *mitkeres = y;

		while (*x && *y && *x == *mitkeres) {
			x++;
			mitkeres++;
		}
		if (!*mitkeres) return start;


	}
	throw c;
}

int main() {

	char*a = new char[50];
	char*b = new char[50];
	strcpy(a, "Almafa");
	strcpy(b, "Alma");
	//cout << keres(b, a);
	try {
		cout << keres(a, b);
	}
	catch (const char* c) {
		cout << c;
	}

}