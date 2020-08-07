// 회장뽑기
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,mn=INF;
bool visited[55];
vector<int> adj[55],ret;
map<int,vector<int>> mp;
queue<int> q;
int bfs(int cur) {
    visited[cur]=true;
    q.push(cur);
    int level=0;
    while(!q.empty()) {
        int size=(int)q.size();
        while(size--) {
            cur=q.front();q.pop();
            for(auto next:adj[cur]) {
                if(!visited[next]) {
                    visited[next]=true;
                    q.push(next);
                }
            }
        }
        level++;
    }
    return level-1;
}
int main() {
    scanf("%d",&n);
    while(true) {
        int a,b;scanf("%d%d",&a,&b);
        if(a==-1&&b==-1) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++) {
        memset(visited,0,sizeof(visited));
        int val=bfs(i);
        mp[val].push_back(i);
        mn=min(mn,val);
    }
    ret=mp[mn];
    sort(ret.begin(),ret.end());
    printf("%d %d\n",mn,(int)ret.size());
    for(auto it:ret) printf("%d ",it);
    return 0;
}