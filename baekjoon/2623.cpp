// 음악프로그램
#include<bits/stdc++.h>
using namespace std;
int n,m,tmp[1005],in[1005];
vector<int> adj[1005];
vector<int> ret;
queue<int> q;
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        int k;
        scanf("%d",&k);
        for(int i=0;i<k;i++) scanf("%d",&tmp[i]);
        for(int i=0;i<k-1;i++) {
            int a=tmp[i],b=tmp[i+1];
            adj[a].push_back(b);
            in[b]++;
        }
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
    if((int)ret.size()!=n) printf("0\n");
    else for(auto it:ret) printf("%d\n",it);
    return 0;
}