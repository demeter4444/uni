//Demeter Tamas
//dtim1806
//511/2

#define min(x,y) ((x<y)?(x):(y))
#define max(x,y) ((x>y)?(x):(y))

#include <iostream>


using namespace std;

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