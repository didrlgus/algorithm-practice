// 피보나치 수 5
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[25];
ll dfs(int n) {
    if(n==0) return 0;
    if(n==1||n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    ll& ret=dp[n];
    ret=dfs(n-2)+dfs(n-1);
    return ret;
}
int main() {
    scanf("%d",&n);
    fill(&dp[0],&dp[0]+25,-1);
    printf("%lld\n",dfs(n));
    return 0;
}