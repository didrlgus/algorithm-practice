// 2xn 타일링 2
#include<bits/stdc++.h>
using namespace std;
const int mod=10007;
int n;
int dp[1010];
int main() {
    scanf("%d",&n);
    dp[1]=1;
    dp[2]=3;
    for(int i=3;i<=n;i++) {
        dp[i]=(dp[i-1]+dp[i-2]*2)%mod;
    }
    printf("%d\n",dp[n]);
    return 0;
}