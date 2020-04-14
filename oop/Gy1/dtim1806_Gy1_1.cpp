//Demeter Tamas
//dtim1806
//511/2

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int &kihuz(int &fek, int &feh){
	if (rand() % 2 == 1) {
		return fek;
	}
	else return feh;
}


int main() {
	int fekete = 0;
	int feher = 0;
	int n;
	srand(time(NULL));

	cout << "N = ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		kihuz(fekete, feher)++;
	}

	cout << "feketek: " << fekete << "feherek:" << feher;
	return 0;
}