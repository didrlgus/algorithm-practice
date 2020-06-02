// 동전 2
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,k,coin[110],dp[100010];
int main() {
    scanf("%d %d",&n,&k);
    fill(dp,dp+10010,INF);
    for(int i=0;i<n;i++) {
        scanf("%d",&coin[i]);
        dp[coin[i]]=1;
    }
    for(int i=1;i<=k;i++) {
        for(int j=0;j<n;j++) {
            if(i-coin[j]>=0) dp[i]=min(dp[i],dp[i-coin[j]]+1);
        }
    }
    if(dp[k]==INF) printf("-1\n");
    else printf("%d\n",dp[k]);
    return 0;
}