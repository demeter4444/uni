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
int main(int argc, char* argv[])          /* a számot a parancssorban adjuk meg */
{

   int fd, fd1;                            /* kliens- és szerverfifo */
   char s[15];
   char buffer[1024];
   azon t;
   azon v;

  sprintf(s, "fifo_%d", getpid());        /* meghat. a fifonevet a pid segítségével */
  if (mkfifo(s, S_IFIFO|0666) < 0) {perror("HIBA: mkfifo kliens"); exit(1);}               /* létrehoz egy kliensfifot */
  if( (fd = open("szerverfifo", O_WRONLY)) <0) {perror("HIBA: open kliens"); exit(1);}
  
  t.pid = getpid();  /* a küldendő adatok */
  printf("fifo_%d\n",t.pid);
  t.biro=atoi(argv[1]);
 // t.csapat=atoi(argv[1]);
 // t.keres=atoi(argv[2]);	
  char beolvas[50];
  sprintf(beolvas,"asd");  
while(strcmp(beolvas,"kilep")!=1)
{
  gets(beolvas);
  t.csapat=beolvas[0]-48;
  t.keres=beolvas[2]-48;
  if(write(fd, &t, sizeof(t)) <0) {perror("HIBA: iras a szervernek"); exit(1);}               /* küldi a szervernek */ 
  //{
	
	if( (fd1 = open(s, O_RDONLY)) <0 )
  	{
  	perror("HIBA: kliens fifo megnyitasa");
  	exit(1);
  	}

	if( read(fd1, &v, sizeof(v)) > 0)
	 {	
      		printf("valasz: %s",v.valasz);
	}
}

	  if( close(fd1) < 0)
        {
                perror("HIBA: kliens bezarasa");
                exit(1);
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
