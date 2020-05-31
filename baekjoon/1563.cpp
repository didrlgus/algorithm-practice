// 개근상
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000;
int n,dp[1010][5][5];   // 현재날짜, 지각/결석 상황
int dfs(int date,int late,int absent) {
    if(date==n) return 1;
    int& ret=dp[date][late][absent];
    if(ret!=-1) return ret;
    ret=0;
    if(late+1<2) {
        ret+=dfs(date+1,late+1,0);
        ret%=mod;
    }
    if(absent+1<3) {
        ret+=dfs(date+1,late,absent+1);
        ret%=mod;
    }
    ret+=dfs(date+1,late,0);
    ret%=mod;
    return ret;
}
int main() {
    scanf("%d",&n);
    fill(&dp[0][0][0],&dp[0][0][0]+1010*5*5,-1);
    printf("%d\n",dfs(0,0,0));
    return 0;
}