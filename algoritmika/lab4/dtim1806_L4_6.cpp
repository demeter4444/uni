//Demeter Tamás
//511/2
//Adottak az elsőéves egyetemisták névsorai (abc sorrendben), csoportonként. Állítsunk elő ezekből egyetlen névsort, mely szintén abc sorrendben van!

#include <stdio.h>
#include <string.h>

main() {
	FILE*f;
	f = fopen("dtim1806_L4_6.txt", "r");
	int n = 0;
	char s[30][100];
	char temp[30];
	while (!feof(f)) {
		fgets(temp, 30, f);
		if (temp[0] > '9') {	//beolvasunk mindent soronkent, ami nem egy szam(feltetelezzuk hogy egy ember nevebe nem lehetnek szamok) azt eltaroljuk, a tobbit hagyjuk.
			strcpy(s[n], temp);
			n++;
		}
	}
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++) if (strcmp(s[i], s[j]) > 0) {	//kozvetlencseres rendezes stringekre
			strcpy(temp, s[i]);
			strcpy(s[i], s[j]);
			strcpy(s[j], temp);
		}
	strcat(s[n - 2], "\n"); //az utolso elotti valamiert nem tor sort magatol, mig a tobbi igen
	for (i = 0; i < n; i++) printf("%s", s[i]);
	fclose(f);
}