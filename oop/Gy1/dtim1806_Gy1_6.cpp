//Demeter Tamas
//dtim1806
//511/2

#include <iostream>

using namespace std;

inline int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

inline int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	int a, b;
	cout << "a =";
	cin >> a;
	cout << "b =";
	cin >> b;
	cout << min(a, b) << endl;
	cout << max(a, b) << endl;
	return 0;
}