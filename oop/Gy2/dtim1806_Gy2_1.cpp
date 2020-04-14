//Demeter Tamas
//dtim1806
//511/2
//Gy2_1

#include <iostream>
#include <cmath>

using namespace std;

class Buvos {
protected:
	int count = 1;
	int a[3][3];
	int x[10];
public:
	Buvos() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				a[i][j] = 0;
			}
		}
	}
	
	void ki(int a[3][3]) {
		cout << count << endl;
		count++;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	virtual bool isOk(int a[3][3]) {
		for (int i = 0; i < 3; i++) {
			int sum1 = 0;
			int sum2 = 0;
			for (int j = 0; j < 3; j++) {
				sum1 += a[i][j];
				sum2 += a[j][i];
			}
			if ((sum1 != 15) || (sum2 != 15)) return false;
		}

		return true;
	}

	void kiir(int i) { //egy permutacio kiirasa
		a[0][0] = x[1];
		a[0][1] = x[2];
		a[0][2] = x[3];
		a[1][0] = x[4];
		a[1][1] = x[5];
		a[1][2] = x[6];
		a[2][0] = x[7];
		a[2][1] = x[8];
		a[2][2] = x[9];

		if (isOk(a)) {
			ki(a);
		}

	}

	int jo(int i) {
		int j;
		int k = 1;
		for (j = i - 1; j >= 1; j--) {
			if (x[j] == x[i]) k = 0; //a permutacio akkor jo, ha ugyanaz az elem nem fordul elo tobbszor
		}
		return k;
	}

	void back(int i) {
		int j;
		for (j = 1; j <= 9; j++) {
			x[i] = j;
			if (jo(i) == 1) {
				if (i == 9) kiir(i);
				else back(i + 1);
			}
		}
	}

};

class BuvosA : public Buvos {
public:
	bool isOk(int a[3][3]){
		int fo = 0;
		int mellek = 0;
		for (int i = 0; i < 3; i++) {
			int sum1 = 0;
			int sum2 = 0;
			for (int j = 0; j < 3; j++) {
				sum1 += a[i][j];
				sum2 += a[j][i];
				if (i == j) {
					fo += a[i][j];
				}
				if ((i + j) == 2) {
					mellek += a[i][j];
				}
			}
			if ((sum1 != 15) || (sum2 != 15)) return false;
		}
		if ((fo != 15) || (mellek != 15)) return false;
		return true;
	}
};

class BuvosB : public Buvos {
	bool isOk(int a[3][3]) {
		int fo = 0;
		int mellek = 0;
		for (int i = 0; i < 3; i++) {
			int sum1 = 0;
			int sum2 = 0;
			for (int j = 0; j < 3; j++) {
				sum1 += a[i][j];
				sum2 += a[j][i];
				if (i == j) {
					fo += a[i][j];
				}
				if ((i + j) == 2) {
					mellek += a[i][j];
				}
			}
			if ((sum1 != 15) || (sum2 != 15)) return false;
		}
		if (abs(fo-mellek)!=3) return false;
		return true;
	}
};

int main() {
	BuvosB a;
	a.back(1);
	return 0;
}