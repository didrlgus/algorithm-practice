// 완전제곱수
#include<bits/stdc++.h>
using namespace std;
const int INF=98765431;
int n,m,mn=INF,sum;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=n;i<=m;i++) {
        for(int j=1;j<=100;j++) {
            int a=j*j;
            if(i>a) continue;
            if(i<a) break;
            mn=min(mn,i);
            sum+=i;
        }
    }
    if(sum) printf("%d\n%d\n",sum,mn);
    else printf("-1\n");
    return 0;
}