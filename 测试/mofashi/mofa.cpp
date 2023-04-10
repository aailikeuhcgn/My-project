#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxsize 100

typedef struct {
    int x;
    int y;
    int w;
}Node;

int main(int argc, const char * argv[]) {
    int n=0,m=0,s=0;
    scanf("%d%d",&n,&m);
    Node chessboard[n][n];
    
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            scanf("%d",&s);
            chessboard[i][j].x=i;
            chessboard[i][j].y=j;
            chessboard[i][j].w=s;
        }
    
    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            chessboard[i][j].w+=chessboard[i-1][j].w>chessboard[i][j-1].w?chessboard[i-1][j].w:chessboard[i][j-1].w;
        }
    }
    
//    for (int i=0; i<n; i++){
//        for (int j=0; j<n; j++)
//            printf("%2d",chessboard[i][j].w);
//        printf("\n");
//    }
    printf("%d\n",(2*n-3)*m-chessboard[n-1][n-1].w);
    return 0;
}

