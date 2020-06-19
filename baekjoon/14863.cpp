// 서울에서 경산까지
#include<bits/stdc++.h>
using namespace std;
const int INF=-987654321;
int n,k,dp[105][100005];
vector<pair<int,int>> v1,v2;
int dfs(int here,int time) {
    if(here==n) return 0;
    int& ret=dp[here][time];
    if(ret!=INF) return ret;
    if(time-v1[here].first>=0) ret=max(ret,dfs(here+1,time-v1[here].first)+v1[here].second);
    if(time-v2[here].first>=0) ret=max(ret,dfs(here+1,time-v2[here].first)+v2[here].second);
    return ret;
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        v1.push_back({a,b});
        v2.push_back({c,d});
    }
    fill(&dp[0][0],&dp[0][0]+105*100005,INF);
    printf("%d\n",dfs(0,k));
    return 0;
}