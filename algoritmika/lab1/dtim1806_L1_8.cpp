//Demeter Tamás
//511/2
//Számítsuk ki, hány napot éltünk a mai nappal bezárólag!


#include <stdio.h>

//elso megoldas
//hasznaljuk azt az informaciot,hogy szokoeveket ertelmezve egy ev 365.242199 nap-bol al --> egy honap 30.4368499 nap, atlagosan
//nem egy teljesen tokeletes megoldas, de sokkal tobb olyan parameter letezik ami ezt megakadalyozza
//pl szuletesi ora,perc,masodperc viszonyitasa az aktualisokkal, bizonyos esetekben eleg hogy a "nap"-ot megtolja 1-el
//(y2*365.242199 + m2*30.4368499 + d2) - (y1*365.242199 + m1*30.4368499 + d1)

 void avg() {

	int y1, m1, d1;

	printf("1.year? \n"); scanf_s("%d", &y1);
	printf("1.month? (1-12) \n");  scanf_s("%d", &m1);  //elso datum y/m/d 
	printf("1.day? (1-31) \n "); scanf_s("%d", &d1);

	int y2, m2, d2;

	printf("\n 2.year? \n"); scanf_s("%d", &y2);
	printf("2.month? (1-12) \n");  scanf_s("%d", &m2);  //masodik(jelen) datum y/m/d 
	printf("2.day? (1-31) \n"); scanf_s("%d", &d2);

	double s = (y2*365.242199 + m2 * 30.4368499 + d2) - (y1*365.242199 + m1 * 30.4368499 + d1);
	printf("\n %f", s);
	system("PAUSE>>VOID");
} 
 int szamol(int y, int m, int d) {


	 int i;
	 long int s = 0;

	 for (i = 1; i < y; i++) {
		 if (i % 4 != 0) { s = s + 365; }
		 else if (i % 100 != 0) { s = s + 366; }
		 else if (i % 400 != 0) { s = s + 365; }
		 else { s = s + 366; }
	 }
	 for (i = 1; i < m; i++) {
		 if (i <= 7) {
			 if (i == 2) {
				 if (y % 4 != 0) s = s + 28;
				 else if (y % 100 != 0) s = s + 29;
				 else if (y % 400 != 0) s = s + 28;
				 else s = s + 29;
			 }
			 else if (i % 2 == 0) s = s + 30;
			 else s = s + 31;
		 }
		 else if (i % 2 == 0) s = s + 31;
		 else s = s + 30;
	 }
	 s = s + d;
	 return s;
 }
 //masodik megoldas
 //ertelmezzuk algoritmus szerint a szokoeveket, es szamoljuk a napokat
 void alg() {

	int y1, m1, d1;
	printf("1.year? \n"); scanf_s("%d", &y1);
	printf("1.month? (1-12) \n");  scanf_s("%d", &m1);  //elso datum y/m/d 
	printf("1.day? (1-31) \n "); scanf_s("%d", &d1);

	int y2, m2, d2;
	printf("\n 2.year? \n"); scanf_s("%d", &y2);
	printf("2.month? (1-12) \n");  scanf_s("%d", &m2);  //masodik(jelen) datum y/m/d 
	printf("2.day? (1-31) \n"); scanf_s("%d", &d2);

	printf("\n eredmeny: %d nap", szamol(y2,m2,d2)-szamol(y1,m1,d1));
	system("PAUSE>>VOID");
}

main() {
	//avg();
	alg();
}