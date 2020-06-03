// 1로 만들기 2
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,dp[1000010];
void dfs(int x) {
    if(x==0) return;
    printf("%d ",x);
    if(x%3==0&&dp[x]==dp[x/3]+1) dfs(x/3);
    else if(x%2==0&&dp[x]==dp[x/2]+1) dfs(x/2);
    else if(x-1>=0&&dp[x]==dp[x-1]+1) dfs(x-1);
    return;
}
int main() {
    scanf("%d",&n);
    fill(dp,dp+1000010,INF);
    dp[1]=0;
    for(int i=2;i<=n;i++) {
        if(i%3==0) dp[i]=min(dp[i],dp[i/3]+1);
        if(i%2==0) dp[i]=min(dp[i],dp[i/2]+1);
        dp[i]=min(dp[i],dp[i-1]+1);
    }
    printf("%d\n",dp[n]);
    dfs(n);
    return 0;
}