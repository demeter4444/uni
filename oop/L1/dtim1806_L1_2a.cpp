//Demeter Tamas
//511/2
//dtim1806
//L1a

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int veletlenSzam(int a, int b) {
	int temp1 = rand() % (a+1);
	int temp2 = rand() % (b+1);
	return temp2 - temp1 + a;
	//rand()%((b-a+1)+a)
}

void jatek(int generaltSzam) {
	int x;
	cin >> x;
	if (x == generaltSzam) {
		printf("gratulalok\n");
		return;
	}
	else {
		if (x > generaltSzam) {
			printf("kisebb\n");
			jatek(generaltSzam);
		}
		else {
			printf("nagyobb\n");
			jatek(generaltSzam);
		}
	}
}

int main() {
	srand(time(NULL));
	printf("Talald ki a szamot!\n");
	jatek(veletlenSzam(1,100));
}