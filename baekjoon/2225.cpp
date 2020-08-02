// 합분해
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000000;
ll n,k,dp[205][205];
int main() {
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<=n;i++) dp[i][1]=1;
    for(int t=0;t<=n;t++) {
        for(int j=2;j<=k;j++) {
            for(int i=0;i<=t;i++) dp[t][j]+=dp[i][j-1];
            dp[t][j]%=mod;
        }
    }
    printf("%lld\n",dp[n][k]);
    return 0;
}