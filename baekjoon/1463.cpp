// 1로 만들기
#include<bits/stdc++.h>

using namespace std;

int n;
int dp[1000010];
int dfs(int x) {
    if(x==1) return 0;
    if(dp[x]!=-1) return dp[x];

    int& ret=dp[x];
    int one=dfs(x-1)+1;
    if(x%2==0) one=min(one,dfs(x/2)+1);
    if(x%3==0) one=min(one,dfs(x/3)+1);
    ret=one;
    return ret;
}

int main() {
    scanf("%d",&n);

    fill(&dp[0],&dp[0]+1000010,-1);
    printf("%d\n",dfs(n));

    return 0;
}