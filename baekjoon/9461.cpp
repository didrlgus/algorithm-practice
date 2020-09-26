// 파도반 수열
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tc,dp[105];
int main() {
    dp[1]=1,dp[2]=1,dp[3]=1;
    for(int i=4;i<=100;i++) dp[i]=dp[i-2]+dp[i-3];
    scanf("%d",&tc);
    while(tc--) {
        int n;scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
    return 0;
}