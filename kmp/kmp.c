#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1000010;
int primes[MAXN],cnt;
bool num[MAXN];
void get_primes0(int n){//������˹����,�˼Ҽ�ǧ��ǰ�������������� 
    for(int i=2;i<=n;i++)
        if(!num[i]){//�Ż�������������ɸ���������ܱ�֤ÿ����ֻ��ɸһ��
            primes[++cnt]=i;
            for(int j=2;j*i<=n;j++) num[j*i]=true;//ÿ�ҵ�һ��������ɸһ��
        }
}
void get_primes(int n){//ŷ��ɸ 
    for(int i=2;i<=n;i++){
        if(!num[i]) primes[++cnt]=i;//i�϶���prime[j]��
        for(int j=1;primes[j]*i<=n;j++){//�Ż���ÿ����ֻ��ɸһ��
            num[primes[j]*i]=true;//��֤�����еĺ������ᱻɸ������Ϊÿ������������С������
            if(i%primes[j]==0) break;//��֤��ÿ������ֻ��������С������ɸ������Ϊi���������С��������prime[j]��
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
