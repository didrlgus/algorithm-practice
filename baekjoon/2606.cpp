// 바이러스
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[105];
bool visited[105];
int dfs(int x) {
    visited[x]=true;
    int ret=0;
    for(auto there:adj[x]) {
        if(!visited[there]) ret+=dfs(there)+1;
    }
    return ret;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printf("%d\n",dfs(1));
    return 0;
}