//Demeter Tamás
//511/2
/*Egy mezőn n ló és m szekér található.  Az i. ló ereje pi, az i. szekér súlya gi.
Egy ló legtöbb egy szekeret húzhat, de ennek a súlya kisebb vagy egyenlő a ló erejével.
Határozzátok meg a lehetséges legnagyobb ló-szekér párt úgy, hogy a párban szereplő ló legyen képes húzni a megfelelő szekeret.*/
#include <stdio.h>

main() {
	int n = 5;
	int m = 5;
	int p[100] = { 6,6,7,10,4,5,2,1,3 };
	int q[100] = { 4,7,8,4,3,3,20,99 };
	int i, j;

	int temp;
	for (i = 1 ; i<=n-1 ; i++)
		for (j = i+1 ; j<=n ; j++)
			if (p[i] < p[j]) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}					//rendezzuk mindket tombot csokkeno sorrendbe
	for (i = 1; i <= n - 1; i++)
		for (j = i + 1; j <= n; j++)
			if (q[i] < q[j]) {
				temp = q[i];
				q[i] = q[j];
				q[j] = temp;
			}
	i = 1;
	j = 1;
	int s = 0;
	while (i <= n, j <= m) {
		if (p[i] >= q[j]) {		//1-1 valtozoval vegigjarjuk mindkettot es szamoljuk a lehetseges megfelelteteseket
			s++;
			i++;
			j++;
		}
		else j++;
	}
	printf("\n Parok szama: %d ", s);
	system("PAUSE>>VOID");
}