// 최단경로
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
vector<pair<int,int>> adj[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int V,e,k,dist[20005];
void dijkstra(int *dist, vector<pair<int, int>> *adj){
    pq.push(make_pair(0, k));   // 시작점
	dist[k]=0; 
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
    scanf("%d %d %d",&V,&e,&k);
    for(int i=0;i<e;i++) {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back({w,v});
    }
    fill(dist,dist+20005,INF);
    dijkstra(dist,adj);
    for(int i=1;i<=V;i++) {
        if(dist[i]==INF) printf("INF\n");
        else printf("%d\n",dist[i]);
    }
    return 0;
}