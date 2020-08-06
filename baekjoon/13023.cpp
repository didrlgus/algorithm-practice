// ABCDE
#include<bits/stdc++.h>
using namespace std;
int n,m,ret;
vector<int> adj[2005];
bool visited[2005],flag;
void dfs(int cur,int cnt) {
    if(flag) return;
    if(cnt==5) flag=true;
    visited[cur]=true;
    for(auto next:adj[cur]) {
        if(!visited[next]) dfs(next,cnt+1);
    }
    visited[cur]=false;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b;scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++) {
        memset(visited,0,sizeof(visited));
        dfs(i,1);
        if(flag) break;
    }
    printf("%d\n",flag);
    return 0;
}