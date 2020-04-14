//Demeter Tamas
//dtim1806
//511/2
//Lab1


#include <stdio.h>

int main(){

FILE*f=fopen("be.txt","r");
int n;
int a[50][50]; //elso szomszedsagi
int b[50][50]; //illeszkedesi (inicializaljuk)
	for(int i=0;i<50;i++)
		for(int j=0;j<50;j++)
			b[i][j]=-1;
int c[50][50]; //masodik szomszedsagi
int d[50][50]; //harmadik szomszedsagi
int t[50][50]; //tavolsagmatrix


fscanf(f,"%d\n", &n); //beolvasas
while (!feof(f)){
	int i,j,s;
	fscanf(f,"%d %d %d\n",&i,&j,&s); //elso szomszedsagi
	a[i][j]=s;
	a[j][i]=s;
}

printf("\n Szomszedsagi matrix: \n"); 
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		printf("%d ",a[i][j]);
	}
	printf("\n");
}

int e = 0;
for(int i=1;i<=n;i++){ //szomszedsagi -> illeszkedesi
	for(int j=1;j<=n;j++){
	if(a[i][j] != 0){
		e++;
		a[j][i]=0;
		b[i][e]=a[i][j];
		b[j][e]=a[i][j];
		}
	}
}

printf("\n Illeszkedesi matrix: \n");

for(int i=1;i<=n;i++){
	for(int j=1;j<=e;j++){
		printf("%d ",b[i][j]);
	}
	printf("\n");
}


int cs1,cs2;		//illeszkedesi -> szomszedsagi
for(int i=1;i<=e;i++){
	cs1=0;
	cs2=0;
	for(int j=1;j<=n;j++){

		if ((b[j][i] > 0) && (cs1==0)) {
		cs1=j;
		for(int k=j+1;k<=n;k++)
		if (b[k][i] > 0) cs2=k;
		c[cs1][cs2]=b[j][i];
		c[cs2][cs1]=b[j][i];
		}
		
	}

}

printf("\n Szomszedsagi matrix: \n");
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		printf("%d ",c[i][j]);
	}
	printf("\n");
}

struct cspont{ //szomszedsagi -> lista
	int szomszed;
	int koltseg;
	};

struct cspont list[50][50];

e = 0;
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
	if(c[i][j] != 0){
		e++;
		c[j][i]=0;
		list[i][e].szomszed=j;
		list[i][e].koltseg=c[i][j];
		list[j][e].szomszed=i;
		list[j][e].koltseg=c[i][j];
		}
	}
}

printf("\n Lista: \n");

for(int i=1;i<=n;i++){
	for(int j=1;j<=e;j++){
		printf("%d-%d ",list[i][j].szomszed,list[i][j].koltseg);
	}
	printf("\n");
}

for(int i=1;i<=n;i++){ //lista -> szomszedsagi
	for(int j=1;j<=e;j++){
		d[i][list[i][j].szomszed]=list[i][j].koltseg;
	}
	printf("\n");
}

printf("Szomszedsagi matrix: \n");
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		printf("%d ",d[i][j]);
	}
	printf("\n");
}

/////////////////////////

int reg=1; 
int max = 0;
for(int i=1;i<=n;i++) if(d[1][i] != 0) max++; //megszamoljuk a lehetseges legnagyob regularitast (egyetlen oszlop ellenorzese)


for(int i=1;i<=n;i++){ //ha megegyezik minden, akkor jo.
	int akt = 0;
	for(int j=1;j<=n;j++){
		if (d[i][j] != 0) akt++;
	}
	if (akt != max) reg=0;

}

if (reg==1) printf("\n A graf %d regularis \n",max);
	else printf("\n A graf nem regularis \n ");

/////////////////////////

printf("\n Izolalt pontok: ");

for(int i=1;i<=n;i++){
	int iz = 1;
	for(int j=1;j<=n;j++){
		if (d[i][j] != 0) iz = 0;
	}
	if (iz != 0) printf("%d ",i);

}

printf("\n");

/////////////////////////

for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		t[i][j]=d[i][j];
		if(t[i][j]==0) t[i][j]=9999; //tavolsagmatrix inicializalasa
		}

int temp;
for (int k=1;k<=n;k++) //warshall alg.
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(t[i][j]<t[i][k]+t[k][j]) temp = t[i][j];
				else temp = t[i][k]+t[k][j];
			t[i][j]=temp;
		
		}
			

printf("\n Tavolsagi matrix: \n");
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		printf("%d ",t[i][j]);
	}
	printf("\n");
}

/////////////////////////

int osszefuggo = 1;
for (int i=1;i<=n;i++){
	int of = 0;
	for(int j=1; j<=n;j++){
		if (d[i][j] != 0) of = 1;
	}
	if (of == 0) {
	osszefuggo = 0;
	printf("\n A graf nem osszefuggo. \n");
	break;
	}
}
if (osszefuggo == 1) printf("\n A graf osszefuggo. \n");
fclose(f);
return 0;
}

