// 거스름돈
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,dp[100010],coin[]={2,5};
int main() {
    scanf("%d",&n);
    fill(dp,dp+100010,INF);
    dp[2]=1;dp[5]=1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<2;j++) {
            if(i-coin[j]>=0) dp[i]=min(dp[i],dp[i-coin[j]]+1);
        }
    }
    if(dp[n]==INF) printf("-1\n");
    else printf("%d\n",dp[n]);
    return 0;
}