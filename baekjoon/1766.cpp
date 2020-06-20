// 문제집
#include<bits/stdc++.h>
using namespace std;
int n,m,in[32005];
vector<int> adj[32005];
vector<int> ret;
priority_queue<int,vector<int>,greater<int>> pq;
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        in[b]++;    
    }
    for(int i=1;i<=n;i++) if(!in[i]) pq.push(i);
    while(!pq.empty()) {
        int here=pq.top();pq.pop();
        ret.push_back(here);
        for(auto there:adj[here]) {
            in[there]--;
            if(!in[there]) pq.push(there);
        }
    }
    for(auto it:ret) printf("%d ",it);
    return 0;
}