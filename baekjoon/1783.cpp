// 병든 나이트
#include<bits/stdc++.h>
using namespace std;
int n,m,ret;
int main() {
    scanf("%d%d",&n,&m);
    if(n==1) {
        ret=1;
    } else if(n==2) {
        ret=min(4,(m+1)/2);
    } else if(n>=3) {
        if(m<=6) ret=min(4,m);
        else ret=m-2;
    }
    printf("%d\n",ret);
    return 0;
}