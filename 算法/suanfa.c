#include <stdio.h>
#include <math.h>
 int IsTheNumber ( const int N ); 
 int main()
  {
      int n1, n2, i, cnt;
                 
     scanf("%d %d", &n1, &n2);
     cnt = 0;
     for ( i=n1; i<=n2; i++ ) {
        if (IsTheNumber(i))
             cnt++;
    }
     printf("cnt = %d\n", cnt);
 
    return 0;
 }
 int IsTheNumber ( const int N ){
     int a=N;
    int i;
     int count=0;
     int j=0;
     int arr[10]={0};
     int b;
    if((int)sqrt(N*0.1)*(int)sqrt(N*0.1) == N)
     { 
     j=1;
    }    
     while(a>0&&count<=10&&j==1)
    {
         arr[a%10]++;
         count++;
         a=a/10;
        for(i=0;i<10;i++)
        {
             if(arr[i]==2)
                 return 1;
        }
     }
     return 0;
 }

