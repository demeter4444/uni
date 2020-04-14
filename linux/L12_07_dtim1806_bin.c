//Demeter Tamas
//dtim1806
//511/2
//lock hazi 7. feladat

/*Írjunk olyan programot, amely egy n2 db. egész számot tartalmazó állománnyal dolgozik. Az állomány bejegyzései egy n elemű M négyzetes mátrix elemei. Egy program ismételten kiszámolja egy sor vagy egy oszlop elemeinek összegét (a sor vagy oszlopszámot véletlenszerűen generáljuk). Az összeget a sor vagy oszlop utolsó elemében tároljuk. Mikor egy számot felhasználtunk az összeg kiszámításánál lenullázzuk azt, elkerülve így azt, hogy kétszer is összeszámoljuk. Számoljuk ki M[n,n]-ben a mátrix elemeinek összegét több ilyen program párhuzamos indításával. Azt a részt az állományból, amit a program az összegszámolásnál használ mindig zárolni kell. A folyamatok akkor állnak le, amikor kiszámoltuk a végső összeget. Az munkaállomány a matrix.bin nevet viseli, amelyet a matrix.dat állományból állítunk elő.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	FILE*f;
	int b,n,i;
	int* v;
	f=fopen("matrix.dat","r");
	if(!f){
		printf("Fajl megnyitas sikertelen");
		exit(1);
	}
	fscanf(f,"%d",&n);
	v=(int*)malloc(n*n*sizeof(int));
	for(i=0;i<n*n;i++){
		fscanf(f,"%d",&v[i]);
	}

	printf("\nKozonseges allomanybol beolvastam:\n");
	for(i=0;i<n*n;i++) printf("%d ",v[i]);
	printf("\n");
	
	if(mknod("matrix.bin",S_IFREG|0666,0)<0){
		printf("Hiba az allomany letrehozasaban");
		exit(1);
	}
	if((b=open("matrix.bin",O_TRUNC|O_WRONLY))<0){
		printf("Hiba az allomany megnyitasaban");
		exit(1);
	}

	if(write(b,&n,sizeof(int))<0){
		printf("Hiba elso irasban");
		exit(1);
	}
	for(i=0;i<n*n;i++){
		if(write(b,&v[i],sizeof(int))<0){
			printf("Hiba masodik irasban");
			exit(1);
		}
	}

	if(close(b)<0){
		printf("Hiba az allomany bezarasanal");
		exit(1);
	}

/*	

	int tempn;
	int* tempv;
	if ((b=open("matrix.bin",O_RDONLY))<0){
		printf("Hiba masodik megnyitasban");
		exit(1);
	}

	if(read(b,&n,sizeof(int))<0){
		printf("Hiba elso bin olvasasban");
		exit(1);
	}
	tempv=(int*)malloc(tempn*tempn*sizeof(int));
	for(i=0;i<tempn*tempn;i++){
		if(read(b,&tempv[i],sizeof(int))<0){
			printf("Hiba masodik bin olvasasban");
			exit(1);
		}
	}

	printf("\nBinaris allomanybol kiolvastam:\n");
	for(i=0;i<tempn*tempn;i++)printf("%d ",tempv[i]);
	printf("\n");
	printf("%d",tempn);
*/
	free(v);
	return 0;
}
