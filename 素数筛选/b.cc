#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1000010;
int primes[MAXN],cnt;
bool num[MAXN];
void get_primes0(int n){//埃拉托斯特尼,人家几千年前玩的玩意儿。。。 
    for(int i=2;i<=n;i++)
        if(!num[i]){//优化：遇到质数才筛，不过不能保证每个数只被筛一次
            primes[++cnt]=i;
            for(int j=2;j*i<=n;j++) num[j*i]=true;//每找到一个质数就筛一次
        }
}
void get_primes(int n){//欧拉筛 
    for(int i=2;i<=n;i++){
        if(!num[i]) primes[++cnt]=i;//i肯定比prime[j]大
        for(int j=1;primes[j]*i<=n;j++){//优化：每个数只被筛一次
            num[primes[j]*i]=true;//保证了所有的合数都会被筛掉，因为每个合数都有最小质因子
            if(i%primes[j]==0) break;//保证了每个合数只被它的最小质因子筛掉，因为i这个数的最小质因数是prime[j]；
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    get_primes(n);
    printf("%d",cnt);
    return 0;
}
