// 01타일
#include<bits/stdc++.h>
using namespace std;
const int mod=15746;
int n,dp[1000005];
int main() {
    scanf("%d",&n);
    dp[1]=1,dp[2]=2;
    for(int i=3;i<=n;i++) dp[i]=(dp[i-1]+dp[i-2])%mod;
    printf("%d\n",dp[n]);
    return 0;
}