// 더하기 사이클
#include<bits/stdc++.h>
using namespace std;
int n,ret,a;
int main() {
    scanf("%d",&n);
    a=n;
    do {
        int d=a/10,m=a%10;
        a=m*10+(d+m)%10;    
        ret++;
    } while(a!=n);
    printf("%d\n",ret);
    return 0;
}