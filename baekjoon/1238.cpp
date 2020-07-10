// 파티
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,x,dist[1005],dist2[1005],ret=-INF;
vector<pair<int,int>> adj[1005],adj2[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void dijkstra(int *dist, vector<pair<int, int>> *adj){
    pq.push(make_pair(0, x));   // 시작점
	dist[x]=0; 
	while(pq.size()){ 
		int here=pq.top().second;
		int here_dist=pq.top().first;
		pq.pop();
		if(dist[here]!=here_dist) continue;
		for(pair<int,int> there:adj[here]){
			int _dist=there.first,_there=there.second;  
			if(dist[_there]>dist[here]+_dist){
				dist[_there]=dist[here]+_dist; 
				pq.push(make_pair(dist[_there],_there));  
			}  
		}
	} 
}
int main() {
    scanf("%d %d %d",&n,&m,&x);
    for(int i=0;i<m;i++) {
        int a,b,t;
        scanf("%d %d %d",&a,&b,&t);
        adj[b].push_back({t,a});
        adj2[a].push_back({t,b});
    }
    fill(dist,dist+1005,INF);
    fill(dist2,dist2+1005,INF);
    dijkstra(dist,adj);
    dijkstra(dist2,adj2);
    for(int i=1;i<=n;i++) {
        if(i==x) continue;
        ret=max(ret,dist[i]+dist2[i]);
    }
    printf("%d\n",ret);
    return 0;
}