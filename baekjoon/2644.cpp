// 촌수계산
#include<bits/stdc++.h>
using namespace std;
int n,a,b,m;
vector<int> adj[105];
queue<int> q;
int visited[105];
int bfs(int x) {
    visited[x]=1;
    q.push(x);
    while(!q.empty()) {
        x=q.front();q.pop();
        if(x==b) return visited[x];
        for(auto there:adj[x]) {
            if(!visited[there]) {
                visited[there]=visited[x]+1;
                q.push(there);
            }
        }
    }
    return -1;
}
int main() {
    scanf("%d %d %d %d",&n,&a,&b,&m);
    for(int i=0;i<m;i++) {
        int c,d;
        scanf("%d %d",&c,&d);
        adj[c].push_back(d);
        adj[d].push_back(c);
    }
    int ret=bfs(a);
    if(ret==-1) printf("%d\n",ret);
    else printf("%d\n",ret-1);
    return 0;
}