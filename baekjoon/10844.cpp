// 쉬운 계단 수
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9;
ll n,dp[105][15],ret;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=9;i++) dp[1][i]=1;
    for(int i=2;i<=n;i++) {
        dp[i][0]=dp[i-1][1];
        for(int j=1;j<=9;j++) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
    }
    for(int i=0;i<=9;i++) ret+=dp[n][i];
    printf("%lld\n",ret%mod);
    return 0;
}