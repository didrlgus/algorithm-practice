// 1로 만들기
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,dp[1000010];
int dfs(int x) {
    if(x==1) return 0;
    int& ret=dp[x];
    if(ret!=-1) return dp[x];
    ret=INF;
    ret=dfs(x-1)+1;
    if(x%3==0) ret=min(ret,dfs(x/3)+1);
    if(x%2==0) ret=min(ret,dfs(x/2)+1);
    return ret;
}
int main() {
    scanf("%d",&n);
    fill(dp,dp+1000010,-1);
    printf("%d\n",dfs(n));
}