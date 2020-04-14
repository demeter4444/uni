//Demeter Tamás
//dtim1806
//511/2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

#define SMAX 256

int main() {
	FILE*f;
	FILE*g;
	f = fopen("input_L4.txt", "r");
	g = fopen("output_L4.txt", "w");
	if (!f) {
		printf("ERROR : Fajl nem nyilt meg");
		exit(1);
	}
	if (!g) {
		printf("ERROR : Fajl nem nyilt meg");
		exit(1);
	}

	int n,r,i,j;
	r = fscanf(f, "%d", &n);

	if (r != 1) {
		printf("ERROR: Beolvasas sikertelen");
		exit(2);
	}
	//1
	char **s = (char**)malloc(n * sizeof(char*));

	for (i = 0; i < n; i++) {
		s[i] = (char*)malloc(SMAX * sizeof(char));
	}

	for (i = 0; i < n; i++) {
		fscanf(f, "%s", s[i]);
	}
	

	char temp[SMAX];
	for (i = 0; i < n-1; i++) {
		for (j = i + 1; j < n; j++) {
			if (strcmp(s[i], s[j])>0) {
				strcpy(temp, s[i]);
				strcpy(s[i], s[j]);
				strcpy(s[j], temp);
			}
		}
	}
	for (i = 0; i < n; i++) fprintf(g,"%s\n", s[i]);

	/////////////////////////////////////////////////////////////////////////////////

	int length = 1;
	char* m1 = (char*)malloc(length*sizeof(char)) ;
	char c;
	fscanf(f, "%c", &c);

	do {
		fscanf(f, "%c", &c);
		if (c == '1') {
			m1[length - 1] = 'e';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'g';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'y';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
		}

		else if (c == '2') {
			m1[length - 1] = 'k';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'e';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 't';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 't';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'o';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
		}
		else if (c == '3') {
			m1[length - 1] = 'h';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'a';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'r';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'o';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'm';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
		}
		else if (c == '4') {
			m1[length - 1] = 'n';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'e';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'g';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'y';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
		}
		else if (c == '5') {
			m1[length - 1] = 'o';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 't';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
		}
		else if (c == '6') {
			m1[length - 1] = 'h';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'a';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 't';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
		}
		else if (c == '7') {
			m1[length - 1] = 'h';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'e';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 't';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
		}
		else if (c == '8') {
			m1[length - 1] = 'n';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'y';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'o';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'l';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
			m1[length - 1] = 'c';
			length++;
			m1 = (char*)realloc(m1, length * sizeof(char));
		}
		else if (c == '9') {
		m1[length - 1] = 'k';
		length++;
		m1 = (char*)realloc(m1, length * sizeof(char));
		m1[length - 1] = 'i';
		length++;
		m1 = (char*)realloc(m1, length * sizeof(char));
		m1[length - 1] = 'l';
		length++;
		m1 = (char*)realloc(m1, length * sizeof(char));
		m1[length - 1] = 'e';
		length++;
		m1 = (char*)realloc(m1, length * sizeof(char));
		m1[length - 1] = 'n';
		length++;
		m1 = (char*)realloc(m1, length * sizeof(char));
		m1[length - 1] = 'c';
		length++;
		m1 = (char*)realloc(m1, length * sizeof(char));
		}
		else if (c == '0') {
		m1[length - 1] = 'n';
		length++;
		m1 = (char*)realloc(m1, length * sizeof(char));
		m1[length - 1] = 'u';
		length++;
		m1 = (char*)realloc(m1, length * sizeof(char));
		m1[length - 1] = 'l';
		length++;
		m1 = (char*)realloc(m1, length * sizeof(char));
		m1[length - 1] = 'l';
		length++;
		m1 = (char*)realloc(m1, length * sizeof(char));
		m1[length - 1] = 'a';
		length++;
		m1 = (char*)realloc(m1, length * sizeof(char));
		}
		else {
			m1[length - 1] = c;

			if (c != '\n') {
				length++;
				m1 = (char*)realloc(m1, length * sizeof(char));
			}
		}
	} while (c != '\n');
	m1[length - 1] = 0;
	fprintf(g,"%s\n", m1);
	
	///////////////////////////////////////////////////////////////////////
	char m2[50];
	char* split;
	fgets(m2, 50, f);
	split = strtok(m2, " ");
	while (split != NULL)
	{
		int i = 0;
		int j = strlen(split)-1;
		char temp;
		while (i != strlen(split)/2) {
			temp = split[i];
			split[i] = split[j];
			split[j] = temp;
			i++;
			j--;
		}
		fprintf(g,"%s ", split);
		split = strtok(NULL, " ");
	}


	for (i = 0; i < n; i++) {
		free(s[i]);
	}
	free(s);
	free(m1);
	fclose(f);
	fclose(g);
	return 0;
}