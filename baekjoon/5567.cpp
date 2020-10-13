// 결혼식
#include<bits/stdc++.h>
using namespace std;
int n,m,ret;
vector<int> adj[505];
bool visited[10005];
queue<int> q;
int bfs(int start_node) {
    visited[start_node]=true;
    q.push(start_node);
    int level=0;
    while(!q.empty()) {
        int size=(int)q.size();
        while(size--) {
            int here=q.front();q.pop();
            for(auto there:adj[here]) {
                if(!visited[there]) {
                    visited[there]=true;
                    q.push(there);
                    ret++;
                }
            }
        }
        level++;
        if(level==2) break;
    }
    return ret;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b;scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printf("%d\n",bfs(1));
    return 0;
}