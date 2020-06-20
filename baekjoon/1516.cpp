// 게임 개발
#include<bits/stdc++.h>
using namespace std;
int n,in[505],arr[505],ret[505];
vector<int> adj[505];
queue<int> q;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&arr[i]);
        while(true) {
            int prev;
            scanf("%d",&prev);
            if(prev==-1) break;
            adj[prev].push_back(i);
            in[i]++;
        }
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
    for(int i=1;i<=n;i++) printf("%d\n",ret[i]);
    return 0;
}