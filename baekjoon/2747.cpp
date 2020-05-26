// 피보나치 수
#include<bits/stdc++.h>

using namespace std;

int n;
int dp[50];
int dfs(int n) {
    if(n==1||n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    int& ret=dp[n];
    ret=dfs(n-2)+dfs(n-1);
    return ret;
}

int main() {
    scanf("%d",&n);
    fill(&dp[0],&dp[0]+50,-1);
    printf("%d\n",dfs(n));
    return 0;
}