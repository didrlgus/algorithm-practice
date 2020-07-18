// 오각형, 오각형, 오각형...
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=45678;
ll n,dp[10000005],a;
int main() {
    dp[1]=5;
    a=7;
    for(ll i=2;i<=10000000;i++) {
        dp[i]=(dp[i-1]+a)%mod;
        a+=3;
    }
    scanf("%lld",&n);
    printf("%lld\n",dp[n]);
    return 0;
}