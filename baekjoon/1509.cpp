// 팰린드롬 분할
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
string s;
int dp[2510][2510],dp2[2510],n;
int dfs(int here) {
    if(here>=n) return 0;
    int& ret=dp2[here];
    if(ret!=INF) return ret;
    for(int i=1;i<=n-here;i++) {
        if(dp[here][i]) ret=min(ret,dfs(here+i)+1);
    }
    return ret;
}   
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>s;
    n=(int)s.size();
    for(int i=0;i<n;i++) dp[i][1]=1;
    for(int i=0;i<n-1;i++) if(s[i]==s[i+1]) dp[i][2]=1;
    for(int size=3;size<=n;size++) {
        for(int i=0;i<=n-size;i++) if(s[i]==s[i+size-1]&&dp[i+1][size-2]) dp[i][size]=1;
    }
    fill(dp2,dp2+2510,INF);
    printf("%d\n",dfs(0));
    return 0;
}