// 고층 빌딩
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,l,r;
long long dp[110][110][110];
int main() {
    scanf("%d %d %d",&n,&l,&r);
    dp[1][1][1]=1;
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=l;j++) {
            for(int k=1;k<=r;k++) {
                dp[i][j][k]=dp[i-1][j-1][k]+dp[i-1][j][k-1]+dp[i-1][j][k]*(i-2);
                dp[i][j][k]%=mod;
            }
        }
    }
    printf("%lld\n",dp[n][l][r]);
    return 0;
}