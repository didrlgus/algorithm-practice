// 작업
#include<bits/stdc++.h>
using namespace std;
int n,arr[10005],ret[10005],in[10005];
vector<int> adj[10005];
queue<int> q;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&arr[i]);
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++) {
            int b;
            scanf("%d",&b);
            adj[b].push_back(i);
            in[i]++;
        }
    }
    for(int i=1;i<=n;i++) {
        if(!in[i]) {
            q.push(i);
            ret[i]=arr[i];
        }
    }
    while(!q.empty()) {
        int here=q.front();q.pop();
        for(auto there:adj[here]) {
            ret[there]=max(ret[there],ret[here]+arr[there]);
            in[there]--;
            if(!in[there]) q.push(there);
        }
    }
    sort(ret,ret+n+1);
    printf("%d\n",ret[n]);
    return 0;
}