// 토너먼트
#include<bits/stdc++.h>
using namespace std;

int n,a,b;
int main() {
    scanf("%d %d %d",&n,&a,&b);
    if(a>b) {
        int tmp=a;
        a=b;
        b=tmp;
    }
    int ret=1;
    while(true) {
        if(b%2==0&&b-a==1) break;
        if(a%2==0) a/=2;
        else a=a/2+1;
        if(b%2==0) b/=2;
        else b=b/2+1;
        ret++;
    }
    printf("%d\n",ret);
    return 0;
}