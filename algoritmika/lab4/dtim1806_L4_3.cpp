//Demeter Tamás
//511/2
//Ismerjük egy osztály tanulóinak neveit és év végi átlagait. Állapítsuk meg, hogy egy adott nevű tanuló az első három díjazott között van-e?

#include <stdio.h>
#include <string.h>

main() {
	FILE*f;
	f = fopen("dtim1806_L4_3.txt", "r");
	int n, i,j;
	float m[100];
	char vn[30][100];
	char kn[30][100];
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(f, "%s %s %f", &vn[i],&kn[i],&m[i]); //beolvassuk %s %s %f formatumban
		strcat(kn[i], " ");		//osszerakjuk a nevet 1 stringbe
		strcat(kn[i], vn[i]);
	}

	float cseref;
	char cserec[30];
	for(i=0;i<n-1;i++)
		for (j = i + 1; j < n; j++) if (m[i] < m[j]) {
			cseref = m[i];
			m[i] = m[j];
			m[j] = cseref;						//a media szerint rendezzuk a neveket is
			strcpy(cserec, kn[i]);
			strcpy(kn[i], kn[j]);
			strcpy(kn[j], cserec);
		}

	char csavovn[30];
	char csavokn[30];			
	int van = 0;
	fscanf(f, "%s %s", &csavovn,&csavokn);
	strcat(csavokn, " ");					//ugyanugy beolvassuk a keresett emberket
	strcat(csavokn, csavovn);
	for (i = 0; i < 3; i++) {
		if (strstr(kn[i], csavokn) != NULL) van = 1;	//ha benne van akkor jo, ha nem, nem
	}

	if (van == 1) printf("igen");
	else printf("nem");

	fclose(f);
}