// 게리맨더링
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,arr[15],team[15],ret=INF;
bool visited[15];
vector<int> adj[15];
pair<int,int> dfs(int here,int val) {
    visited[here]=true;
    pair<int,int> ret={1,arr[here]};
    for(auto there:adj[here]) {
        if(visited[there]) continue;
        if(team[there]!=val) continue;
        pair<int,int> p=dfs(there,val);
        ret.first+=p.first;
        ret.second+=p.second;
    }
    return ret;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++) {
        int a; 
        scanf("%d",&a);
        for(int j=0;j<a;j++) {
            int b;
            scanf("%d",&b);
            adj[i].push_back(b);
        }
    }
    for(int i=1;i<(1<<n)-1;i++) {
        fill(&visited[0],&visited[0]+15,false);
        fill(&team[0],&team[0]+15,0);
        int idx1=0,idx2=0;
        for(int j=0;j<n;j++) {
            if(i&(1<<j)) {
                team[j+1]=1;
                idx1=j+1;
            } else idx2=j+1;
        }
        pair<int,int> p1=dfs(idx1,1);
        pair<int,int> p2=dfs(idx2,0);
        if(p1.first+p2.first==n) ret=min(ret,abs(p1.second-p2.second));
    }
    if(ret==INF) printf("-1\n");
    else printf("%d\n",ret);
    return 0;
}