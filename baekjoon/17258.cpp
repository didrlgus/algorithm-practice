// 인기가 넘쳐흘러
#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,arr[305],dp[305][305];
vector<pair<int,int>> v;
int dfs(int here,int num,int prev) {
    if(here==(int)v.size()) return 0;
    int& ret=dp[here][num];
    if(ret!=-1) return ret;
    int cost=max(0,t-v[here].second);
    int real_cost=(prev>=cost)?0:cost;
    if(num-real_cost>=0) ret=max(dfs(here+1,num-real_cost,real_cost)+v[here].first,dfs(here+1,num,0));
    else ret=dfs(here+1,num,0);
    return ret;
}
int main() {
    scanf("%d %d %d %d",&n,&m,&k,&t);
    for(int i=0;i<m;i++) {
        int s,e;
        scanf("%d %d",&s,&e);
        for(int j=s;j<e;j++) arr[j]=min(t,++arr[j]);
    }
    int cnt=1,tmp=arr[1];
    for(int i=2;i<=n;i++) {
        if(tmp!=arr[i]) {
            v.push_back({cnt,tmp});
            cnt=0;
            tmp=arr[i];
        }
        cnt++;
    }
    v.push_back({cnt,tmp});
    fill(&dp[0][0],&dp[0][0]+305*305,-1);
    printf("%d\n",dfs(0,k,0));
    return 0;
}