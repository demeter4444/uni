//Demeter Tamás
//511/2
//dtim1806

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RMIN -999
#define RMAX 999
#define swap(a,b,t) { t c=a;a=b;b=c;}
#define NCHAR 256


int main()
{
    FILE *f = fopen("input_L3.txt","r");
    FILE *g = fopen("output_L3.txt","w");
    if(!f)
    {
        printf("ERROR opening input_L3.txt\n");
        exit(1);
    }
    int n;
    int i,j;
   
    srand(time(NULL));
    fscanf(f,"%d\n", &n);
    int *T = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
       T[i] = rand()%(abs(RMIN)+RMAX+1)-abs(RMIN);

    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(T[i]>T[j])
            {
                swap(T[i],T[j],int);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        fprintf(g,"%d ",T[i]);
    }
    fprintf(g,"\n");
    fprintf(g,"-----------------------------------\n");
    free(T);
    //////////////////////////////////////////////////////
    int length = 1;
    char c;
    int sp=0;
    char *S=(char *)malloc(length *sizeof(char));
    int *stat=(int *)calloc(NCHAR,sizeof(int));
    do
    {
        fscanf(f,"%c", &c);
        S[length-1]=c;
        if(c==' ')
        {
            sp++;

        }
        if(c != '\n')
        {
            stat[c]++;
            length++;
            S = (char *)realloc(S, length * sizeof(char));
        }
    }
    while(c != '\n');
    S[length-1] = '\0';
    fprintf(g,"%s\n",S);
    fprintf(g,"Length: %d\n",length);
    fprintf(g,"Length (w/o spaces): %d\n",length-sp);
    for(i=0;i<NCHAR;i++)
    {
        if(stat[i]!=0)
        {
            fprintf(g,"%c-%d\n",i,stat[i]);
        }
    }
    fprintf(g,"-----------------------------------\n");
    free(S);
    free(stat);
    ///////////////////////////////////////////////////
    int r1,c1,r2,c2;
    fscanf(f,"%d%d", &r1, &c1);
    int **M1 = (int**)malloc(r1*sizeof(int *));
    for(i=0;i<r1;i++)
    {
        M1[i]= (int*)malloc(c1*sizeof(int));
    }
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            fscanf(f,"%d", &M1[i][j]);
        }
    }
	int m1x = i;
	int m1y = j;
	int x = i;


    fscanf(f,"%d%d", &r2, &c2);
    int **M2 = (int**)malloc(r2*sizeof(int *));
    for(i=0;i<r2;i++)
    {
        M2[i]= (int*)malloc(c2*sizeof(int));
    }
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            fscanf(f,"%d", &M2[i][j]);
        }
    }
	int m2x = i;
	int m2y = j;
	int y = j;
    if(c1!=r2)
    {
        fprintf(g,"Error in multiplication of the matrices\n");
    }
    else
    {
		int sum = 0;
		int** M3 = (int**)malloc(x * sizeof(int*));
		for (i = 0; i < x; i++) {
			M3[i] = (int*)malloc(y * sizeof(int));
		}
		int k;
		for (i = 0; i < x; i++) {
			
			for (j = 0; j < y; j++) {
				sum = 0;
				for (k = 0; k < m1x; k++) {
					sum = sum + M1[i][k] * M2[k][j];
				
				}
				fprintf(g,"%d ", sum);
			
			}
			fprintf(g,"\n");
	}

	
    }
    for(i=0;i<r1;i++)
    {
        free(M1[i]);
    }
    free(M1);
    for(i=0;i<r2;i++)
    {
        free(M2[i]);
    }
    free(M2);
    fclose(f);
    fclose(g);

    return 0;
}
