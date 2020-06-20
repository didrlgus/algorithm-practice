// 줄 세우기
#include<bits/stdc++.h>
using namespace std;
int n,m,in[32005];
vector<int> adj[32005];
vector<int> ret;
queue<int> q;
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        in[b]++;
    }
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
    while(!q.empty()) {
        int here=q.front();q.pop();
        ret.push_back(here);
        for(auto there:adj[here]) {
            in[there]--;
            if(!in[there]) q.push(there);
        }
    }
    for(auto it:ret) printf("%d ",it);
    return 0;
}