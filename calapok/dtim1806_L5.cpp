//Demeter Tamás
//dtim1806
//511/2

#include <stdio.h>
#include <string.h>
#define SMAX 256

struct gyerekek {
	char nev[SMAX];
	int kor;
	char jovagyrossz[10];
};

int main() {
	FILE*f;
	FILE*g;
	FILE*h;
	f = fopen("input_L5.txt", "r");
	g = fopen("config.txt", "r");
	h = fopen("output_L5.txt", "w");
	if (!f) {
		printf("ERROR : Fajl nem nyilt meg");
		exit(1);
	}
	if (!g) {
		printf("ERROR : Fajl nem nyilt meg");
		exit(1);
	}
	if (!h) {
		printf("ERROR : Fajl nem nyilt meg");
		exit(1);
	}
	int n,r;
	int length = 1;
	struct gyerekek *gyerek = (struct gyerekek*)malloc(length * sizeof(struct gyerekek));
	do {
		r = fscanf(f, "%s %d %s", &gyerek[length-1].nev, &gyerek[length-1].kor, &gyerek[length-1].jovagyrossz);
		if ((r != 3) && !feof(f)) {
			printf("ERROR: Beolvasas sikertelen");
			exit(2);
		}
		length++;
		 gyerek = (struct gyerekek*)realloc(gyerek, length * sizeof(struct gyerekek));
		
	} while (!feof(f));
	n = length - 1;
	//////////////////////////////////
	int config;
	r = fscanf(g, "%d", &config);
	struct gyerekek temp;
	int i,j,e,v;

	switch (config){
	case  1 :
		for (i = 0; i < n-1; i++) {
			for (j = i + 1; j < n; j++) {
				if (strcmp(gyerek[i].nev, gyerek[j].nev) >= 0) {
					temp = gyerek[j];
					gyerek[j] = gyerek[i];
					gyerek[i] = temp;
				}
			}
		}
		for (i = 0; i < n; i++) {
			fprintf(h, "%s %d\n", gyerek[i].nev, gyerek[i].kor);
		}
		break;

	case 2:
		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n; j++) {
				if (gyerek[i].kor > gyerek[j].kor) {
					temp = gyerek[j];
					gyerek[j] = gyerek[i];
					gyerek[i] = temp;
				}
			}
		}
		for (i = 0; i < n; i++) {
			fprintf(h, "%s %d\n", gyerek[i].nev, gyerek[i].kor);
		}
		break;

	case 3:
		for (i = 0; i < n; i++) {
			if (strcmp(gyerek[i].jovagyrossz, "jo") == 0) fprintf(h, "%s %d\n", gyerek[i].nev, gyerek[i].kor);
		}
		break;

	case 4:
		for (i = 0; i < n; i++) {
			if (strcmp(gyerek[i].jovagyrossz, "rossz") == 0) fprintf(h, "%s %d\n", gyerek[i].nev, gyerek[i].kor);
		}
		break;

	case 5:
		r = fscanf(g, "%d %d", &e, &v);
		if ((r != 2) && (!feof(g))) {
			printf("ERROR : Beolvasas sikertelen!");
			exit(2);
		}
		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n; j++) {
				if (strcmp(gyerek[i].nev, gyerek[j].nev) >= 0) {
					temp = gyerek[j];
					gyerek[j] = gyerek[i];
					gyerek[i] = temp;
				}
			}
		}
			for (i = 0; i < n; i++) {
				if ((gyerek[i].kor >= e) && (gyerek[i].kor <= v) && (strcmp(gyerek[i].jovagyrossz,"jo")==0)) {
					fprintf(h, "%s %d\n", gyerek[i].nev, gyerek[i].kor);
				}
			}
		break;
	default:
		printf("ERROR: Helytelen config!");
		exit(3);
	}

	free(gyerek);
	fclose(f);
	fclose(g);
	fclose(h);
	return 0;
}