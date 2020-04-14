//Demeter Tamas
//dtim1806
//511/2
//10. labor 7. feladat c program

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[]){
        FILE* f;
	FILE* pf;
        int p[2],p2[2];
        char buf[1024];
	char str[1024];
        int id;

        //pipe
        if (pipe(p)<0) perror("pipe hiba");
	if (pipe(p2)<0) perror("pipe hiba");

        //fork
        id = fork();
        if (id < 0) perror("fork hiba");
        //gyerek - szerver
        if (id==0){
        close(p[1]);
	close(p2[0]);
        read(p[0],&buf,sizeof(buf));
        strtok(buf,"\n");
	sprintf(str,"find %s -type f -name \"*.c\" -exec basename {} \\;",buf);
	if((pf=popen(str,"r"))==NULL){
		perror("popen hiba");
		exit(1);
	}

	while(fgets(buf,1024,pf)){
		//printf("%s",buf);
		write(p2[1],&buf,sizeof(buf));
	}
	pclose(pf);	
        exit(0);
        }
        //szulo - kliens
        else{
        close(p[0]);
	close(p2[1]);
        if ((f=fopen("input.dat","r"))==NULL) {
                printf("fajl megnyitas sikertelen");
                exit(1);
                }
        fgets(buf,1024,f);
        write(p[1],&buf,sizeof(buf));
        wait(NULL);
	while(read(p2[0],&buf,sizeof(buf))){
		printf("%s",buf);
	}
        exit(0);
        }
}


