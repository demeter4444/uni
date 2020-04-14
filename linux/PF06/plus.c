#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{

        int ksz[2], szk[2], users[2];
        pipe(ksz);
        pipe(szk);
        pipe(users);
        int pid;
        switch (pid = fork()){
                case -1:{
                perror("fork hiba");
                exit(1);
                }
                case 0:{ // szerver - gyerek
                FILE *ps;
                char shellcmd[100];
                char c;
                int i,nr;
			
	//		while(1==1){	
                        close(szk[1]);
                        close(ksz[0]);
                        close(users[0]);
                        strcpy(shellcmd, "./plu.sh ");
                        i = strlen(shellcmd) - 1;
                        do{
                              read(szk[0], &c, sizeof(char)); 
                                if (i < 100) i++;
                                shellcmd[i] = c;
                        } while (c != 0);

                        printf("szerver:\n");
                        nr = 0;
                        ps = popen(shellcmd, "r"); 
                        do{
                                c = fgetc(ps);
                                if (c == '\n')
                                        nr++;
                                write(ksz[1], &c, sizeof(char));
                        } while (c != EOF);
                        write(users[1], &nr, sizeof(int));
            //            }
           	exit(0);
            }
               default:{ // kliens - szulo
			
                        close(szk[0]);
                        close(ksz[1]);
                        close(users[1]);
                        printf("kliens: ");  
                        char c;
                        char buf[3];
                        scanf("%s", buf);
                        if (atoi(buf) < 1 || atoi(buf) > 31){ 
                                printf("hasznalat: dd\n");
                                exit(1);
			}
			 write(szk[1], buf, strlen(buf)+1);
                        int nr;
                        read(users[0], &nr, sizeof(int));
                        printf("darabszam:", nr);
                        int wc = 0;
                        do{
                                read(ksz[0], &c, sizeof(char));
                                if (c != EOF){
                                        wc++;
                                        printf("%c", c);
                                }
                        } while (c != EOF);

                        if (wc == 0)  printf("senki.\n");			
			

                }
        }

        return 0;
}

                        
