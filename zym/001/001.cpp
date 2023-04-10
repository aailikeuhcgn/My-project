#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define MAXSIZE 1000
#define H 8							
#define L 12						
typedef struct{
	int i,j;
	int v;
}triple;

typedef struct{
	triple data[MAXSIZE];
	int m,n,t;
}tripletable;

void print_array1(tripletable a)									
{
	int i,j,b[100][100];
	for(i=0;i<a.m;i++)										
		for(j=0;j<a.n;j++)
			b[i][j]=0;
	for(i=0;i<a.t;i++)										
		b[a.data[i].i-1][a.data[i].j-1]=a.data[i].v;
	for(i=0;i<a.m;i++)											
	{	for(j=0;j<a.n;j++)
			printf("%4d",b[i][j]);
		printf("\n");

	}
}


tripletable fasttranstri(tripletable a)			
{
	 tripletable b;
	 int p,q,col,k;
	 int num[L+1],pot[L+1];
	 b.m=a.n;
	 b.n=a.m;
	 b.t=a.t;
	 if(b.t)
	 {
		 for(col=1;col<=a.n;++col)
			 num[col]=0;
		 for(k=0;k<a.t;++k)
			 ++num[a.data[k].j];
		 pot[1]=0;
		 for(col=2;col<=a.n;++col)
			 pot[col]=pot[col-1]+num[col-1];
		 for(p=0;p<a.t;++p)
		 {
			 col=a.data[p].j;
			 q=pot[col];
			 b.data[q].i=a.data[p].j;
			 b.data[q].j=a.data[p].i;
			 b.data[q].v=a.data[p].v;
			 ++pot[col];
		 }
	 }
	 return b;
}
int main ()
{
	tripletable a,a2;
	int r=0,i,j,b[H][L],n,sum=H*L,c=-1;
	int p;
	srand((unsigned)time(NULL));
	n=rand()%(H*L-H*L/2)+H*L/2;
	for(i=0;i<H;i++)                 
		for(j=0;j<L;j++)
		{
			p=rand()%2;
			if(p<(float)n/sum)
			{
				b[i][j]=0;
				n--;
			}
			else
				b[i][j]=rand()%100;
			sum--;
		}
	for(i=0;i<H;i++)				 
		for(j=0;j<L;j++)
			if(b[i][j]!=0)
			{
				c++;
				a.data[c].i=i+1;
				a.data[c].j=j+1;
				a.data[c].v=b[i][j];
			}
	a.m=H;
	a.n=L;
	a.t=c+1;
	print_array1(a);
	printf("\n");
	a2=fasttranstri(a);
	print_array1(a2);

}