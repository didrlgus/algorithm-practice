// 특정한 최단 경로
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,e,dist[805],dist2[805],s,A,B,ret;
vector<pair<int,int>> adj[200005],adj2[200005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void dijkstra(int *dist, vector<pair<int, int>> *adj){
    pq.push(make_pair(0, s));   // 시작점
	dist[s]=0; 
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
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
        adj2[a].push_back({c,b});
        adj2[b].push_back({c,a});
    }
    fill(dist,dist+805,INF);
    fill(dist2,dist2+805,INF);
    scanf("%d %d",&A,&B);
    s=A;
    dijkstra(dist,adj);
    s=B;
    dijkstra(dist2,adj2);
    int AB=dist[B];
    ret=min(dist[1]+AB+dist2[n],dist2[1]+AB+dist[n]);
    printf("%d\n",ret>=INF||ret<0?-1:ret);  // 오버플로우 발생 (ret<0)
    return 0;
}