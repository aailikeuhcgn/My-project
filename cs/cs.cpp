#include<stdio.h>
#include<math.h>
int F(int n)            //任意进制转化为十进制
{
	int i=0,j=0,y,d,c=-1;
    int v=0,r=0,sum=0;
	char  t[20];
    printf("请输入您要转化的数:");
    scanf("%s",&t);
    printf("\n"); 
	fflush(stdin);
	while(t[j]!='\0')
		{j++;}
    for(i=0;t[i]!='\0';i++)
	{   if((int)(t[i])>=48&&(int)(t[i])<=57||(t[i])>='A'&&(int)(t[i])<='J');
                      
	    else { 
		       printf("输入有误! 请输入数字: \n");
		       printf("请输入您要转化的数:");
               scanf("%s",&t);
	         }
	              c++;
	              y=j-i-1;       
	  if(t[i]<='9');
	    else
		{
		 d=t[i];
	     t[i]=d-7;
		}
     r=(int)(t[i]-48)*pow( n,y);
	 sum=sum+r;
	}
	return sum;
}
void main()
{
	int a;
	a=F(2);
	printf("%d",a);
}