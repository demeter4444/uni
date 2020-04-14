//Demeter Tamas
//511/2
//dtim1806
//9. labor 7. feladat(fork)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

FILE* g; //output
FILE* h; //log

//osszefesul ket adott meretu sorozatot egy harmadikba
//standard algoritmus
void osszefesul(int nbal, int* bal, int njobb, int* jobb, int* veg){
	int i=0;
	int b=0;
	int j=0;
	while((j<njobb)&&(b<nbal)){
		if (bal[b]<jobb[j]){
			veg[i]=bal[b];
			b+=1;
		} else{
			veg[i]=jobb[j];
			j+=1;
	}
	i+=1;
	}
	while (b<nbal){
		veg[i]=bal[b];
		i+=1;
		b+=1;
	}
	while (j<njobb){
		veg[i]=jobb[j];
		i+=1;
		j+=1;
	}

}

//kiir egy n elemu v sorozatot(int)
void kiir(int n, int* v){
        int i;
        fprintf(g,"\n");
        for(i=0;i<n;++i){
                fprintf(g,"%d ",v[i]);
        }
        fprintf(g,"\n");
}


//divide et impera rendezes
void rendez(int n, int* v){
	//ha csak egy elemunk maradt, megallunk
	if (n <= 1) return;
	//deklaraciok
	int nbal=n/2;
	int njobb=n/2;
	if (n%2==1) njobb+=1;
	int i,b,j,id1,id2;

	//2 pipe?
	int p1[2],p2[2],p3[2],p4[2];
	
	//sorozat felbontasa	
	//dinamikus?
	int bal[nbal]; 
	int jobb[njobb];


	b=0;
	for(i=0;i<nbal;++i){
		bal[b]=v[i];
		b+=1;
	}
	j=0;
	for(i=nbal;i<n;++i){
		jobb[j]=v[i];
		j+=1;
	}

	//pipe
	if (pipe(p1)<0) perror("pipe hiba p1-ben");
	if (pipe(p2)<0) perror("pipe hiba p2-ben");
	if (pipe(p3)<0) perror("pipe hiba p3-ban");
	if (pipe(p4)<0) perror("pipe hiba p4-ben");

	//fork bal
	id1=fork();
	if(id1<0) perror("fork hiba (bal)");
	//gyerek
	if(id1==0){
		close(p1[1]);
		close(p2[0]);
		//a gyerek olvassa a bal felet a sorozatnak a szulotol(olvas amig van mit), majd rekurzivan meghivja a rendezest
		while(read(p1[0],&bal,nbal*sizeof(int))!=0) rendez(nbal,bal);
		//rendezes utan megirja a sorozatot a szulonek es lognak
		fprintf(h,"%d gyerekfolyamat kiszamolta:",getpid());
		for(i=0;i<nbal;++i){
			fprintf(h,"%d ",bal[i]);
		}
		fprintf(h,"\n");
		fflush(h);
		write(p2[1],&bal,nbal*sizeof(int));
		close(p2[1]);
		//bezarjuk a gyereket, miutan elvegezte a dolgat
		exit(0);
	}
	//szulo
	else{
		close(p1[0]);
		close(p2[1]);
		//a szulo megirja a gyereknek a rendezendo sorozatot
		write(p1[1],&bal,nbal*sizeof(int));
		close(p1[1]);

		//a szulo olvassa a gyerektol visszakapott sorozatot. addig olvas amig van mit, s megvarja a gyereket.
		while(read(p2[0],&bal,nbal*sizeof(int))!=0) wait(NULL);
		close(p2[0]);

		//fork jobb
		//a bal reszsorozat visszaszerzese utan dolgozzuk fel a jobbat egy ujabb gyerekkel.
		id2=fork();
		if(id2<0) perror("fork hiba (jobb)");
		//gyerek, ugyanaz mint fennebb, csak jobb(oldal)
		if (id2==0){
			close(p3[1]);
			close(p4[0]);
			while(read(p3[0],jobb,njobb*sizeof(int))!=0) rendez(njobb, jobb);
			fprintf(h,"%d gyerekfolyamat kiszamolta:",getpid());
			for(i=0;i<njobb;++i){
				fprintf(h,"%d ",jobb[i]);
			}
			fprintf(h,"\n");
			fflush(h);
			write(p4[1],jobb,njobb*sizeof(int));
			close(p4[1]);
		//fontos: befejezzuk a gyerekfolyamatot, mert mar nincs ra szuksegunk.
			exit(0);
		//szulo, ugyanaz
		}else{
			close(p3[0]);
			close(p4[1]);
			write(p3[1],&jobb,njobb*sizeof(int));
			close(p3[1]);
			while(read(p4[0],&jobb,njobb*sizeof(int))!=0) wait(NULL);
			close(p4[0]);
			//mindket reszsor miutan megvan, osszefesuljuk.
			osszefesul(nbal,bal,njobb,jobb,v);
		}
	}
}

int main(){

	FILE* f;
        f=fopen("input.dat","r");
        g=fopen("output.dat","w");
	h=fopen("log.dat","w");
        int n;
        fscanf(f,"%d",&n);
        int* v=(int*)malloc(n*sizeof(int));
        int i;
        for(i=0;i<n;i++){
                fscanf(f,"%d",&v[i]);
        }
        fprintf(g,"\n Rendezes elott \n");
	fflush(g);
	kiir(n,v);
	fflush(g);
	rendez(n,v);
	fprintf(g,"\n Rendezes utan \n");
	kiir(n,v);
	free(v);
        fclose(f);
        fclose(g);
	fclose(h);
        return 0;
}



