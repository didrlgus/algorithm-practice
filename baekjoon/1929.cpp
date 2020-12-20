// 소수 구하기
#include<bits/stdc++.h>
using namespace std;
int n,m;
bool isPrime[1000005];
int main() {
    scanf("%d%d",&n,&m);
    fill(isPrime,isPrime+1000000,true);
    isPrime[0]=false;isPrime[1]=false;  
    for(int i=2;i<=1000000;i++) { 
        for(int j=i+i;j<=1000000;j+=i) {
            isPrime[j]=false; 
        }
    }
    for(int i=n;i<=m;i++) {
        if(isPrime[i]) printf("%d\n",i);
    }
    return 0;
}