//Demeter Tamás
//511/2
//Adott egy szam. Adjuk meg a szamjegyeibol kepezheto lehetseges legnagyobb palindromszamot. (greedy)
#include <stdio.h>

main() {
	int x;
	int v[50];
	int s[10] = { 0,0,0,0,0,0,0,0,0,0 }; //statisztika
	printf("x=");
	scanf("%d", &x);
	int i = 0;
	while (x != 0) {
		s[x % 10]++;
		v[i] = 0;
		i++;
		x = x / 10;
	}
	int n = i;

	i = 0;
	int j = n - 1;

	for (int k = 9; k >= 0; k--) {  //eleje + vege egyszerre
		while ((s[k] > 1)) {
			v[i] = k;
			v[j] = k;
			i++;
			j--;
			s[k] = s[k] - 2;
		}
	}

	for (int k = 9; k >= 0; k--) {  //kozepe (ha van)
		if (s[k] == 1) {
			v[i] = k;
			break;
		}
	}

	int pal = 1;  //ellenorzes
	for (i = 0; i < n; i++) {
		if (v[i] != v[n - i -1]) pal = 0;
	}
	if (v[0] == 0) pal = 0;
	
	//if (pal == 0) printf("nem lehet");
	/*else*/ for (i = 0; i < n; i++) if (v[i] != 0) printf("%d ", v[i]);


}