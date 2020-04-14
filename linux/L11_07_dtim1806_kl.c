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

   int fd, fd1;                           
   char s[15];
   char buffer[1024];
   azon t;
   azon v;

  if (argc<=1){
	printf("Hasznalat: %s <allomanynevek>\n",argv[0]);
	exit(1);
	}
  sprintf(s, "fifo_%d", getpid());        
  if (mkfifo(s, S_IFIFO|0666) < 0) {perror("HIBA: mkfifo kliens"); exit(1);}           
  if( (fd = open("szerverfifo", O_WRONLY)) <0) {perror("HIBA: open kliens"); exit(1);}
  t.pid = getpid(); 
  int i=1;
  while(argv[i]!=NULL){
  strcpy(t.szoveg,argv[i]); 
  printf("%d folyamat kuldi: %s\n",getpid(),t.szoveg);
  if(write(fd, &t, sizeof(t)) <0) {perror("HIBA: iras a szervernek"); exit(1);}      	
	if( (fd1 = open(s, O_RDONLY)) <0 )
  	{
  	perror("HIBA: kliens fifo megnyitasa");
  	exit(1);
  	}

	if( read(fd1, &v, sizeof(v)) > 0)
	 {	
      		printf("%d folyamat megkapta: %s",getpid(),v.szoveg);
	}

	  if( close(fd1) < 0)
        {
                perror("HIBA: kliens bezarasa");
                exit(1);
        }
i++;
}

  	if( close(fd) < 0)
	{
		perror("HIBA: szerver bezarasa");
		exit(1);
	}
	
	  if(unlink(s) < 0)
        {
                perror("HIBA: kliens torlese");
                exit(1);
	}
}
