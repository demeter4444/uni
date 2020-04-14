//Demeter Tamas
//dtim1806
//511/2
//fifo lab 7. feladat

/*A kliens információt kér állományokról. A szerver ellenőrzi, hogy létezik-e az adott állomány, és válaszként visszaküldi az állomány típusát, méretét, hány különböző néven hivatkoznak rá, szöveges állományok esetében pedig az állomány sorainak és szavainak számát is. A kliens az állományneveket paraméterként kapja.*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include "struktura.h"                    
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
  int fd,fd1;                          
  char s[15];     
  FILE* pf;
  char buf[1024];  
  azon t;    
  azon v;         
  char valami[1024];
  if (mkfifo("szerverfifo",S_IFIFO|0666)<0) {perror("HIBA mkfifo!"); exit(1);}
  if ((fd=open("szerverfifo",O_RDONLY))<0){perror("Open HIBA!");exit(1);} 

  while(1) 
  {
   if(read(fd, &t, sizeof(t))>0)
     {	 
      sprintf(s,"fifo_%d",t.pid);
      if ((fd1=open(s,O_WRONLY))<0) {perror("Open HIBA irasra!");exit(1);}
      sprintf(valami,"./L11_07_dtim1806.sh %s",t.szoveg);
      if ((pf=popen(valami,"r"))==NULL){
	      perror("popen hiba");
	      exit(1);
      }
	strcpy(v.szoveg,"");
	while(fgets(buf,sizeof(buf),pf)!=NULL){
        strcat(v.szoveg,buf);
	}
      if (write(fd1,&v,sizeof(v))<0){perror("Kuldes hiba!");exit(1);}
      	
      }
   if(strcmp(t.szoveg,"0")==0)break;
   }
  	if (pclose(pf)==-1){
		perror("pclose hiba");
		exit(1);
	}
      if (close(fd1)<0){perror("Bezaras HIBA!");exit(1);}
     
	
  
  if (close(fd)<0) {perror("Bezaras HIBA szerver_fifo");exit(1);}
  printf("Befejezodott a szerver\n");
  if (unlink("szerverfifo")<0){perror("SZERVER bezaras HIBA!");exit(1);}
  exit(0);
}
