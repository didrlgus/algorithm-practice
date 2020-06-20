// ACM Craft
#include<bits/stdc++.h>
using namespace std;
int tc,n,k,d,arr[1005],ret[1005],in[1005];
int main() {
    scanf("%d",&tc);
    while(tc--) {
        fill(arr,arr+1005,0);fill(ret,ret+1005,0);fill(in,in+1005,0);
        vector<int> adj[1005];
        queue<int> q;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
        for(int i=0;i<k;i++) {
            int a,b;
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
            in[b]++;
        } 
        scanf("%d",&d);
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
        printf("%d\n",ret[d]);
    }
    return 0;
}