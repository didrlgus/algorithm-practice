// 알약
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,dp[35][35];
// 현재 알약의 whole,half 상태에 해당하는 경우의 수 반환하는 함수
ll dfs(int whole,int half) {
    if(whole==0&&half==0) return 1;
    if(dp[whole][half]!=-1) return dp[whole][half];

    ll& ret=dp[whole][half];
    ret=0;

    if(whole>0) ret+=dfs(whole-1,half+1);
    if(half>0) ret+=dfs(whole,half-1);
    return ret;
}

int main() {
    while(true) {
        int n;
        scanf("%d",&n);
        if(n==0) break;
        fill(&dp[0][0],&dp[0][0]+35*35,-1);
        printf("%lld\n",dfs(n,0));      // whole, half
    }
    return 0;
}