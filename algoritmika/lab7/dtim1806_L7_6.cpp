//Demeter Tamás, dtim1806, 511/2
//7. labor 6. feladat
//Adott egy n egész számot tartalmazó sorozat.
//Határozzuk meg azt a legnagyobb összeget, amelyet a tömb egymás utáni elemeinek összeadásával kaphatunk.

#include <stdio.h>
//sajnos ezzel a feladattal nem sokra jutottam.
int maxsum(int x[50], int n, int e, int v, int sum) {
	int k = (e + v) / 2;
	if (e == v) return x[e];
	else {
		/*if ((maxsum(x, n, e, k, sum)) > sum) {
			sum = sum + maxsum(x, n, e, k, sum);
			printf("%d ", x[k]);
		}
		 if ((maxsum(x, n, k + 1, v,sum)) > sum) {
			sum = sum + maxsum(x, n, k + 1, v, sum);
			printf("%d ", x[k]);
		}*/

		//if (maxsum(x, n, e, k, sum)) > maxsum(x, n, k + 1, v, sum)){  //esetleg igy?
	//}

		 if (maxsum(x, n, e, k, sum) + maxsum(x, n, k + 1, v, sum) > sum) {
			sum = sum + maxsum(x, n, e, k, sum) + maxsum(x, n, k + 1, v, sum);
			printf("%d ", x[k]);
		}
	}
}

main() {
	FILE*f = fopen("dtim1806_L7_6.txt", "r");
	int n, i;
	int v[50];
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++) fscanf(f, "%d", &v[i]);
	printf("%d", maxsum(v, n, 0, n - 1, 0));
	//int s = maxsum(v, n, 0, n - 1, 0);
}