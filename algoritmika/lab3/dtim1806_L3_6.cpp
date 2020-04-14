//Demeter Tamás
//511/2
//Egy adott szöveg szavakat tartalmaz, ismeretlen számú szóközzel elválasztva. Írjunk programot, amely törli a szöveg leghosszabb szavát! Több azonos hosszúságú szó esetén töröljük mindegyiket! A kimeneti szövegben a szavak egy-egy szóközzel legyenek elválasztva!
#include <stdio.h>
#include <string.h>
void spacek(char s[255]) {	//alprogram amely torli egy stringbe a spaceket a memmove fuggveny segitsegevel(2 egymasutani space talaltakor az elsore huzza a masodikat) megj: ez csakis azonos egymastkoveto karakterekkel mukodik.
	int i = 0;
	while (s[i - 1] != '\0') {

		if ((s[i] == ' ') && (s[i + 1] == ' ')) {
			memmove(&s[i], &s[i + 1], strlen(s));
			i--;
		}
		i++;
	}
}

int szamol(char s[255]) {  //alprogram amely megadja egy string leghoszabb szavanak hosszat
	int i = 0;
	int sum = 0;
	int max = 0;
	while (s[i - 1] != '\0') {
		if (s[i] == ' ') {
			if (sum > max) max = sum;
			sum = 0;
		}
		else sum++;
		i++;
	}
	return max;
}

void torol(char s[255], int max) {  //alprogram mely torli egy stringbol a megadott hosszusagu szavakat (elobb kicsereli spacere, utana meghivja a spacetorlo alprogramot)
	int i = 0;
	int sum = 0;
	while (s[i - 1] != '\0') {
		if (s[i] == ' ') {
			sum = 0;
		}
		else sum++;
		if (sum == max) {
			int j;
			for (j = 0 ; j <= max; j++) {
				s[j+i-max]=' ';
			}
			sum = 0;
		}
		i++;
	}
	spacek(s);

}

main() {
	FILE*f;
	int max = 0;
	f = fopen("dtim1806_L3_6.txt", "r");
	char s[255];
	while (!feof(f)) {
		fgets(s, 255, f);		
		spacek(s);								//eloszor bejarjuk a fajlt, megkeresve a leghosszabb szo hosszusagat
		if (szamol(s) > max) max = szamol(s);
	}
	fclose(f);
	f = fopen("dtim1806_L3_6.txt", "r");
	while (!feof(f)) {				//masodszor bejarjuk a fajlt,s kitoroljuk a max hosszusagu szavakat, soronkent, stringekben. a spacek torleset is alkalmazzuk, mind2 bejarasnal
		fgets(s, 255, f);
			spacek(s);
			torol(s, max);
			printf("%s", s);
	}
	//az eredmenyt egyszerubb kulon kimeneti fajlba megjeleniteni, de ugy irtam hogy konzolba is jo legyen
	fclose(f);
	system("PAUSE>>VOID");
}