//Demeter Tamás
//511/2
//dtim1806
//1. feladat : szamrendszerek
#include <stdio.h>
#include <string.h>
#include <math.h>

FILE*g; //az output globalis, az egyszeruseg kedveert

int to10(int fr, char s[255],int n) { //atalakitunk tetszoleges szamrendszerbol tizesbe, hatvanyok szorzasaval, egesz szamra (pozitiv hatvanyok)
	int i;
	int h = 0;
	int szam = 0;
	for (i = n - 1; i >= 0; i--) {
		if (s[i] <= '9') {
			szam = szam + (s[i] - '0')*pow(fr, h);
			h++;
		}
		else {
			szam = szam + (s[i] - 'A' + 10)*pow(fr, h);
			h++;
		}

	}
	return szam;
}

void from10(int to, int s) {	//atalakitunk, s egyszerre ki is irunk 10es szamrendszerbol tetszoleges szamrendszerbe osztassal
	int m;
	int v[255]; //a helyes sorrendben valo kiiras erdekeben elobb felepitjunk egy tombot a maradekokbol, majd forditva bejarjuk
	int i = 0;
	if (s == 0) fprintf(g, "%c", '0');
	while (s != 0) {
		m = s % to;
		s = s / to;
		v[i] = m;
		i++;

	}
	int n = i - 1;
	for (i=n;i>=0;i--) if (v[i] <= 9) {

		fprintf(g, "%c", v[i] + '0');
	}
	else {
		fprintf(g, "%c", v[i] + 'A' - 10);
	}	
}

float to10t(int fr, char s[255], int n) {  //atalakitunk tetszoleges szamrendszerbol tizesbe, hatvanyok szorzasaval tortekre (negativ hatvanyokkal szorzunk)
	int i;
	int h = -1;
	float szam = 0.0;
	for (i = 0; i <= n; i++) {
		if (s[i] <= '9') {
			szam = szam + (s[i] - '0')*pow(fr, h);
			h--;
		}
		else {
			szam = szam + (float)((float)s[i] - (float)'A' + (float)10)*(float)pow((float)fr, (float)h); //lehet talan kevesebb (float) is de biztosra mentem :)
			h--;
		}

	}
	return szam;
}

void from10t(int to, float s) {	 //atalakitunk tizes szamrendszerbol tetszolegesbe, es ki is irjuk. szorzunk az alappal amig a egesz szamot kapunk, vagy ha szakasz lep fel, 30 tizedes pontossagig
	int m;
	int i = 0;
	if (s == (float)0) fprintf(g, "%c", '0');
	while ((s - trunc(s) != 0) && (i <= 30)) {
		s = s * (float)to;
		m = (int)trunc(s) % to;
		if (m <= 9) fprintf(g, "%c", m + '0');
		else fprintf(g, "%c", m + 'A' - 10);
		i++;
		
	}
}

main() {
	FILE*f;
	f = fopen("input.dat", "r");
	g = fopen("output.dat", "w");
	int fr, to, i,j,pozvesszo,l;
	char s[255];
	char se[255];	//s a teljes szam, karakterlanckent beolvasva. tizedesvesszo szerint ezt meg kettebontjuk egeszreszre es tortreszre.(ha egyaltalan van tizedesvesszo)
	char st[255];
	while (!feof(f)) {
		 pozvesszo = -1;
		fscanf(f, "%d %d %s", &fr, &to, &s);
		int hiba = 0;
		for (i = 0; i < strlen(s); i++) {
			if ((s[i] < '0') && (s[i] != ',')) hiba = 1;
			if ((fr <= 10) && (s[i] > (char)(fr + '0'))) hiba = 1;
			if ((fr > 10) && (s[i] > '9') && (s[i] > (char)(fr + 'A' - 10))) hiba = 1;
		}
		if ((fr < 2) || (to < 2)) fprintf(g, "%s", "hibas alap\n");
		else if (hiba == 1) fprintf(g, "%s", "hibas szam az alaphoz kepest\n"); //hibakezelesek
		else {
			fprintf(g, "%d %s %d ", fr, s, to);
			for (i = 0; i < strlen(s); i++) if (s[i] == ',')  pozvesszo = i;
			if (pozvesszo != -1) {
				for (i = 0; i < pozvesszo; i++) se[i] = s[i];
				j = 0;
				for (i = pozvesszo + 1; i < strlen(s); i++) {
					st[j] = s[i];
					j++;
				}
				l = j - 1;
				from10(to, to10(fr, se, pozvesszo));
				fprintf(g, ",");
				from10t(to, to10t(fr, st, l));
				fprintf(g, "\n");
			}
			else {
				from10(to, to10(fr, s, strlen(s)));
				fprintf(g, "\n");
			}
		}

	}
	fclose(f);
	fclose(g);
}