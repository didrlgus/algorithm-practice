// 최소비용 구하기
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,s,e,dist[1005];
vector<pair<int,int>> adj[100005];
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
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back({c,b});
    }
    scanf("%d %d",&s,&e);
    fill(dist,dist+1005,INF);
    dijkstra(dist,adj);
    printf("%d\n",dist[e]);
    return 0;
}