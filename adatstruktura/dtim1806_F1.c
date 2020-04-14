//Demeter Tamas
//dtim1806
//511/2
//F1

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

// SEGEDFUGGVENYEK ES KONSTANSOK

float count(char* x, int n, char* y, int m){ //megszamolja az y karakterlanc elemeinek elofordulasainak szamat x karakterlancban ugy, hogy nem veszi figyelembe az egymast koveto elofordulasokat
	int amount = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++){
			if(x[i]==y[j]){
				int jo = 1;
				for(int k=0;k<=m;k++){
					if (x[i-1] == y[k]) jo = 0;

				}
			if (jo==1) {
			amount++;
			break;
			}
			}
		}
	}
	return amount+1;
	
}


char* szo_elvalaszto = " ,:;.?!-";
char* mondat_elvalaszto = ".?!";
char* maganhangzo = "aeiouAEIOU";

//------------------------------------------------------

// KARAKTERLANC ADATSZERKEZET

//adattagok
char* s;
int n;

//felhasznalo fuggvenyek

//inicializțlja a karakterlancot a parameterkent kapott adatokkal
//itt kap erteket az s es az n (ne feledkezzetek meg a helyfoglalasrol)
void init(){
	FILE*f=fopen("in.txt","r");
	s=(char *)malloc(sizeof(char));
	char c;
	n=0;
	while(!feof(f)){
		fscanf(f,"%c",&c);
		s[n]=c;
		n++;
		s = (char *)realloc(s, (n+1) * sizeof(char));
	}
	n++;
	fclose(f);
}

//kiirja a karakterlancot
void kiir(){
	printf("%s",s);
}

//meghatarozza a szavak szamat a karakterlancban
float szavak_szama(){
	return count(s,n,szo_elvalaszto,7);	
}

//meghatarozza a mondatok szamat a karakterlancban
float mondatok_szama(){
	return count(s,n,mondat_elvalaszto,2);
}

//meghatarozza a szotagok szamat a karakterlancban
float szotagok_szama(){
	int szotagok=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<=9;j++){
			if(s[i] == maganhangzo[j]) szotagok++;
		}
	}
	return szotagok;
}

//meghatarozza az olvashatosagi indexet
// keplet: 206.835 - 1.015*(#szavak/#mondatok) - 84.6* (#szotagok/#szavak)
float flesch_index(){
	float temp1 = szavak_szama()/mondatok_szama();
	float temp2 = szotagok_szama()/szavak_szama();
	float temp = 206.835 - 1.015*temp1 - 84.6*temp2;
	return temp;

}

//------------------------------------------------------

//FELHASZNALO PROGRAM

int main()
{
	init();
	kiir();
	printf("\n szavak : %f \n",szavak_szama());
	printf("\n mondatok : %f \n",mondatok_szama());
	printf("\n szotagok : %f \n",szotagok_szama());
	printf("\n felsch :  %f \n",flesch_index());
    return 0;
}
