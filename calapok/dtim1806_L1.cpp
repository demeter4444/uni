//Demeter Tamás
//511/2
//dtim1806
#include <stdio.h>

int szamE(char c) {
	if ((c >= '0') && (c <= '9')) return 1;
	return 0;
}

int main() {
	FILE *fp;
	char c[4];
	int n;
	fp = fopen("input_L1.txt", "r");
	if (!fp) printf("nemjo batya(1)"); //ellenorzes h megnyitotta -> if(!f)
	n = fscanf(fp, "%c %c %c %c", &c[0], &c[1], &c[2], &c[3]); //ellenorzes h valami be lett olvasva -> n=fscanf(f,"%c",&valami)
	if (n != 4) printf("nemjo batya(2)");
	fclose(fp);

	int s[3];
	char k;
	int i,j;
	j = 0;
	for (i = 0; i < 4; i++) {
		if (szamE(c[i])) {
			s[j] = c[i] - '0';
			j++;
		}
		else k = c[i];
	}

	fp = fopen("output_L1_1.txt", "w");
	fprintf(fp, "Szamok: %d %d %d \nKarakter: %c", s[0], s[1], s[2], k);
	if ((k >= 'a') && (k <= 'z')) fprintf(fp, "\n A karakter kicsi");
	else fprintf(fp, "A karakter nagy");
	fclose(fp);

	fp = fopen("output_L1_2.txt", "w");
	if ((s[0] <= s[1] + s[2]) && (s[1] <= s[0] + s[2]) && (s[2] <= s[0] + s[1])) fprintf(fp, "A 3 szam megfelelo hosszusagu szakaszai alkothatnak haromszoget");
	else fprintf(fp, "A 3 szam megfelelo hosszusagu szakaszai NEM alkothatnak haromszoget");
	fclose(fp);

	fp = fopen("output_L1_3.txt", "w");
	fprintf(fp, "elso + masodik: %d \nmasodik - harmadik: %d \nharmadik * elso: %d \nelso/harmadik: %d", s[0] + s[1], s[1] - s[2], s[2] * s[0], s[0] / s[2]);
	fclose(fp);

	fp = fopen("output_L1_4.txt", "w");
	for (i = s[1]; i > 0; i--) {
		for (j = s[0]; j <= i * s[2]; j = j + s[2]) fprintf(fp, "%d ", j);
		fprintf(fp, "\n");
	}
	fclose(fp);

	fp = fopen("output_L1_5.txt", "w");
	for (i = s[1]; i > 0; i--) {
		for (j = s[0]; j <= i * s[2]; j = j + s[2]) fprintf(fp, "%c ", j+k-s[0]);
		fprintf(fp, "\n");
	}
	fclose(fp);


	return 0;
}

