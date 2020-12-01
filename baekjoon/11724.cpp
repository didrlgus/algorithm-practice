// 연결 요소의 개수
#include<bits/stdc++.h>
using namespace std;
int n,m,ret;
vector<int> adj[1005];
bool visited[1005];
void dfs(int x) {
    visited[x]=true;
    for(auto it:adj[x]) {
        if(!visited[it]) dfs(it);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b;scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            dfs(i);
            ret++;
        }
    }
    printf("%d\n",ret);
    return 0;
}