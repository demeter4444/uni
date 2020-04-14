//Demeter Tamas
//511/2
//dtim1806
//L12b


#include <iostream>

using namespace std;

void spiralSorrend(const int* matrix, int n, int*spiral) {
	const int m = (int)sqrt(n);
	int ** temp = new int*[m];
	for (int i = 0; i < m; i++) temp[i] = new int[m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = matrix[i*m + j];
		}
	}

	int i = 0;
	int j = 0;
	int startr = 0;
	int endr = m;
	int startc = 0;
	int endc = m;
	
	while ((startr < endr) && (startc < endc)) {

		//elso sor a megmaradt sorokbol
		for (i = endc-1; i >= startc; --i) {
			spiral[j] = temp[startr][i];
			j++;
			}
		startr++;

		//elso oszlop a megmaradt oszlopokbol
		for (i = startr; i < endr; ++i) {
			spiral[j] = temp[i][startc];
			j++;
		}
		startc++;

		//utolso sor a megmaradt sorokbol
		if (startr < endr) {
			for (i = startc; i < endc; ++i) {
				
				spiral[j] = temp[endr - 1][i];
				j++;
			}
			endr--;
		}

		//utolso oszlop a megmaradt oszlopokbol
		if (startc < endc) {
			for (i = endr; i > startr; --i) {
				
				spiral[j] = temp[i-1][endc-1];
				j++;
			}
			endc--;
		}
	}
	
}

int main() {
	const int a[9] = { 1,2,3,4,5,6,7,8,9 };
	int n = 9;
	int v[9];
	spiralSorrend(a, n, v);
	for (int i = 0; i < n; i++) printf("%d ", v[i]);
	return 0;
}