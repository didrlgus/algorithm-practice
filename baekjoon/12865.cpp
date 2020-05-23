// 평범한 배낭
#include<bits/stdc++.h>

using namespace std;

int n,k,w[110],v[110];
vector<int> dp1;
vector<int> dp2;
int main() {
    scanf("%d %d",&n,&k);
    dp1.resize(k+1);
    dp2.resize(k+1);
    for(int i=1;i<=n;i++) {
        scanf("%d %d",&w[i],&v[i]);
    }
    // dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i])
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            if(j>=w[i]) dp2[j]=max(dp1[j],dp1[j-w[i]]+v[i]);
            else dp2[j]=dp1[j];
        }
        dp1=dp2;
    }
    printf("%d\n",dp1[k]);
    return 0;
}