// 설탕 배달
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,arr[]={3,5},dp[5005];
int main() {
    scanf("%d",&n);
    fill(dp,dp+5005,INF);
    dp[3]=1;dp[5]=1;
    for(int i=3;i<=n;i++) {
        for(int j=0;j<2;j++) if(i-arr[j]>=0) dp[i]=min(dp[i],dp[i-arr[j]]+1);
    }
    printf("%d\n",dp[n]==INF?-1:dp[n]);
    return 0;
}