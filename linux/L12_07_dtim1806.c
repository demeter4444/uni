//Demeter Tamas
//dtim1806
//511/2
//lock hazi 7. feladat

/*Írjunk olyan programot, amely egy n2 db. egész számot tartalmazó állománnyal dolgozik. Az állomány bejegyzései egy n elemű M négyzetes mátrix elemei. Egy program ismételten kiszámolja egy sor vagy egy oszlop elemeinek összegét (a sor vagy oszlopszámot véletlenszerűen generáljuk). Az összeget a sor vagy oszlop utolsó elemében tároljuk. Mikor egy számot felhasználtunk az összeg kiszámításánál lenullázzuk azt, elkerülve így azt, hogy kétszer is összeszámoljuk. Számoljuk ki M[n,n]-ben a mátrix elemeinek összegét több ilyen program párhuzamos indításával. Azt a részt az állományból, amit a program az összegszámolásnál használ mindig zárolni kell. A folyamatok akkor állnak le, amikor kiszámoltuk a végső összeget. Az munkaállomány a matrix.bin nevet viseli, amelyet a matrix.dat állományból állítunk elő.*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(){
	FILE* g;
	int b,i,cim,sum;
	int tempn;
        int* tempv;
	struct flock warlock;
	warlock.l_type=F_RDLCK;
	warlock.l_whence=SEEK_SET;
	warlock.l_start=0;
	warlock.l_len=sizeof(int);

	srand(time(NULL)+getpid());

        if ((b=open("matrix.bin",O_RDWR))<0){
                printf("Hiba megnyitasban//fajl nem letezik");
                exit(1);
        }
	
        if(read(b,&tempn,sizeof(int))<0){
                printf("Hiba elemszam kiolvasasaban");
                exit(1);
        }
	
	printf("A program elindult. Please wait.\n");	
	int* matrix;
while(1){
	//megallasi feltetel ellenorzese
	lseek(b,sizeof(int),SEEK_SET);
	matrix=(int*)malloc(tempn*tempn*sizeof(int));
	warlock.l_type=F_RDLCK;
	warlock.l_whence=SEEK_SET;
	warlock.l_start=sizeof(int);
	warlock.l_len=tempn*tempn*sizeof(int);
	if(fcntl(b,F_SETLKW,&warlock)<0){printf("0. lock hiba 1");exit(1);}
	for(i=0;i<tempn*tempn;i++)
	if(read(b,&matrix[i],sizeof(int))<0){printf("matrix read hiba");exit(1);}
	int checksum=0;
//	g=fopen("log.dat","a");
//	fprintf(g,"%d: Jelenleg a matrix: ",getpid());
//	for(i=0;i<tempn*tempn;i++) fprintf(g, "%d ",matrix[i]);//matrix kiiratasa
//	fprintf(g,"\n");
//	fclose(g);
	for(i=0;i<tempn*tempn-1;i++) checksum+=matrix[i];
	warlock.l_type=F_UNLCK;
	if(fcntl(b,F_SETLKW,&warlock)<0){printf("0. lock hiba 2"); exit(1);}
	if (checksum==0) break;
	//

        tempv=(int*)malloc(tempn*sizeof(int));
	
	//kiszamolando resz generalasa
	int so=rand()%2; //sor/oszlop
	int x=rand()%tempn; //index

	if (so==0){ //sor
	cim=x*tempn*sizeof(int)+sizeof(int);
	lseek(b,cim,SEEK_SET);

	warlock.l_type=F_WRLCK;
	warlock.l_whence=SEEK_SET;
	warlock.l_start=cim;
	warlock.l_len=tempn*sizeof(int);
	
	g=fopen("log.dat","a");
	fprintf(g,"%d: Zarolom a(z) %d. sort \n",getpid(),x);
	fclose(g);

	if(fcntl(b,F_SETLKW,&warlock)<0){printf("sor lock hiba"); exit(1);}
	sum=0;
	int nulla=0;
        for(i=0;i<tempn;i++){
                if(read(b,&tempv[i],sizeof(int))<0){
                        printf("Hiba sor olvasasban");
                        exit(1);
                }
	}
	lseek(b,cim,SEEK_SET);
	for(i=0;i<tempn-1;i++){
		sum+=tempv[i];
		if(write(b,&nulla,sizeof(int))<0) {printf("hiba sor irasban 1"); exit(1);}
	}
	sum+=tempv[tempn-1];
        if(write(b,&sum,sizeof(int))<0){printf("hiba sor irasban 2"); exit(1);}
	warlock.l_type=F_UNLCK;
	g=fopen("log.dat","a");
	fprintf(g,"%d: Menyitom a(z) %d. sort\n",getpid(),x);
	fclose(g);
	if(fcntl(b,F_SETLKW,&warlock)<0){printf("sor unlock hiba");exit(1);}

	

	}else{  //oszlop
	cim=x*sizeof(int)+sizeof(int);
	lseek(b,cim,SEEK_SET);

	warlock.l_whence=SEEK_SET;
	warlock.l_len=sizeof(int);
	warlock.l_type=F_WRLCK;
	warlock.l_start=cim;

	g=fopen("log.dat","a");
	fprintf(g,"%d: Zarolom a(z) %d. oszlopot\n",getpid(),x);
	fclose(g);

	for(i=0;i<tempn;i++){	
		if(fcntl(b,F_SETLKW,&warlock)<0){printf("oszlop lock hiba");exit(1);}
		warlock.l_start=cim+(i+1)*tempn*sizeof(int);
	}

	for(i=0;i<tempn;i++){
		if(read(b,&tempv[i],sizeof(int))<0){
			printf("Hiba oszlop olvasasban");
			exit(1);
		}
		lseek(b,cim+(i+1)*tempn*sizeof(int),SEEK_SET);
	}
	
	sum=0;
	int nulla=0;
	lseek(b,cim,SEEK_SET);
	for(i=0;i<tempn-1;i++){
		sum+=tempv[i];
		if (write(b,&nulla,sizeof(int))<0){printf("oszlop iras hiba 1");exit(1);}
		lseek(b,cim+(i+1)*tempn*sizeof(int),SEEK_SET);
	}
	sum+=tempv[tempn-1];
	if(write(b,&sum,sizeof(int))<0){printf("oszlop iras hiba 2");exit(1);}

	cim=x*sizeof(int)+sizeof(int);
	warlock.l_type=F_UNLCK;
	warlock.l_start=cim;
	g=fopen("log.dat","a");
        fprintf(g,"%d: Megnyitom a(z) %d. oszlopot\n",getpid(),x);
        fclose(g);

	for(i=0;i<tempn;i++){
        	if(fcntl(b,F_SETLKW,&warlock)<0){printf("oszlop unlock hiba");exit(1);}
		warlock.l_start=cim+(i+1)*tempn*sizeof(int);
        }
        }
   
	g=fopen("log.dat","a");
	fprintf(g,"%d: Az eredeti sor/oszlop: ",getpid());
	for(i=0;i<tempn;i++) fprintf(g,"%d ",tempv[i]);
	fprintf(g,"\n");
	fprintf(g,"%d: A megvaltoztatott sor/oszlop: ",getpid());
	for(i=0;i<tempn-1;i++) fprintf(g,"0 ");
	fprintf(g,"%d\n",sum);
	fclose(g);
	free(tempv);
	sleep(1);
}	
	free(matrix);
	printf("A program befejezodott, log.dat frissitve.\n");
	fflush(stdout);
	exit(0);
}
