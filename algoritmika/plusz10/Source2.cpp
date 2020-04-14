//Demeter Tamás
//511/2
//paronkenti osszefesulesek minimalis szama (nem jo)
#include <stdio.h>
int feloszt(int *v, int n,int sum) {
	int w[50];
	if (n == 1) return sum;
	else {
		int k = 0;
		int i = 0;
		int j = n - 1;
		while (i <= j) { 
			w[k] = v[i] + v[j];
			sum = sum + w[k];
			k++;
			i++;
			j--;
		}

		int m =k;
		for (i = 0; i < m - 1; i++) { 
			for (j = i + 1; j < m; j++) {
				if (w[i] > w[j]) {
					int csere = w[i];
					w[i] = w[j];
					w[j] = csere;
				}
			}
		}

		if (n % 2 == 0) return feloszt(w, (n / 2),sum);
		else return  feloszt(w, (n / 2) + 1,sum);

	}
}
main() {
	int n = 7;
	int v[7] = { 5,3,9,4,8,10,1 };

	int i, j;
	for (i = 0; i < n-1; i++) {
		for (j = i + 1; j < n; j++) {
			if (v[i] > v[j]) {
				int csere = v[i];
				v[i] = v[j];
				v[j] = csere;
			}
		}
	}

	printf("%d", feloszt(v, n,0));

}