#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include "struktura.h"                    /* a fenti fejlécállomány */
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
  int fd,fd1;                            /* szerver- és kliensfifo */
  char s[15];                             /* kliensfifo neve; pl. fifo_143 */
  azon t;    /* küldendő "csomag" */
  azon v;         
  char buffer[1024];
  int maxjatek=3;
  int i;
  int golok1=0;
  int golok2=0;
  int sarga1=0;
  int sarga2=0;
  int szabad1=0;
  int szabad2=0;
  int szoglet1=0;
  int szoglet2=0;
  int count=0;
  int ido=0;
  if (mkfifo("szerverfifo",S_IFIFO|0666)<0) {perror("HIBA mkfifo!"); exit(1);}    /* a szerver létrehozza a saját fifo-ját */
  if ((fd=open("szerverfifo",O_RDONLY))<0){perror("Open HIBA!");exit(1);}     /* megnyitja olvasásra; jöhetnek a számok */
 int birok[3];
  //srand(time(NULL));
  //int r=rand() % (100-1+1);
  //printf("A szam= %d",r); 
  
  while(ido!=2)                                      /* addig megy, míg 0-t nem küld egy kliens */
  {
   if(read(fd, &t, sizeof(t))>0)
     {	   /* szám kiolvasása */
      printf("szerver megkapta %d %d",t.csapat,t.keres);	
      if(t.biro==1) count++;
            if(count > maxjatek) t.biro=0;
	if (birok[0]==0) birok[0]=t.pid;
	else if (birok[1]==0) birok[1]=t.pid;
	else if (birok[2]==0) birok[2]=t.pid;
	else if ((t.pid!=birok[0])||(t.pid!=birok[1])||(t.pid!=birok[2]))t.biro=0;
      sprintf(s,"fifo_%d",t.pid);
      if ((fd1=open(s,O_WRONLY))<0) {perror("Open HIBA irasra!");exit(1);}

	if (t.biro==1){
	strcpy(v.valasz,"Elfogadtam");
		if (t.keres==1){	
			if (t.csapat==1)golok1++;
			else golok2++;
		}
		if (t.keres==2){
			if (t.csapat==1)sarga1++;
			else sarga2++;
		}
		if(t.keres==3){
			if(t.csapat==1)szabad1++;
			else szabad2++;
		}
		if (t.keres==4){
			if(t.csapat==1)szoglet1++;
		 	else szoglet2++;
		}
		if (t.keres==5){
			ido++;
			if (ido>=2){
			strcpy(v.valasz,"Match vege!");
			}
		}
	}
	else{
		if(t.keres==1){
 		char vl[50];
		sprintf(vl,"Golok: %d:%d",golok1,golok2);
		strcpy(v.valasz,vl);
		}
		if(t.keres==2){
		char vl[50];
		sprintf(vl,"Sargalapok: %d:%d",sarga1,sarga2);
		}
		if(t.keres==3){
		char vl[50];
		sprintf(vl,"Szabadrugasok: %d:%d",szabad1,szabad2);
		}
		if(t.keres==4){
		char vl[50];
		sprintf(vl,"Szogletek: %d:%d",szoglet1,szoglet2);
		}
		if(t.keres==5){
		char vl[50];
		sprintf(vl,"Ido: %d",ido);
		}
	
	}
		

      if (write(fd1,&v,sizeof(v))<0){perror("Kuldes hiba!");exit(1);}
	
		    
	}
   }
      if (close(fd1)<0){perror("Bezaras HIBA!");exit(1);}
     
	
   
 // if (close(fd1<0)){perror("bezaras hiba");exit(1);}
  if (close(fd)<0) {perror("Bezaras HIBA szerver_fifo");exit(1);}
  printf("Befejezodott a szerver\n");
  if (unlink("szerverfifo")<0){perror("SZERVER bezaras HIBA!");exit(1);}
  exit(0);
}
