// 거의 최단 경로
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int k,dist[505],n,m,s,d,cost[505][505];
vector<pair<int,int>> adj[505];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void dijkstra(int *dist, vector<pair<int, int>> *adj){
    pq.push(make_pair(0, k));   // 시작점
	dist[k]=0; 
	while(pq.size()){ 
		int here=pq.top().second;
		int here_dist=pq.top().first;
		pq.pop();
		if(dist[here]!=here_dist) continue;
		for(pair<int,int> there:adj[here]){
            if(cost[here][there.second]==-1) continue;
			int _dist=there.first,_there=there.second;  
			if(dist[_there]>dist[here]+_dist) {
				dist[_there]=dist[here]+_dist; 
				pq.push(make_pair(dist[_there],_there));  
			}  
		}
	} 
}
void go() {
    queue<int> q;
    q.push(d);
    while(q.size()) {
        int end=q.front();q.pop();
        for(int i=0;i<n;i++) {      // 모든 정점 탐색
            if(dist[end]==dist[i]+cost[i][end]&&cost[i][end]!=-1) {
                cost[i][end]=-1;
                q.push(i);
            }
        }
    }
}
int main() {
    while(true) {
        scanf("%d %d",&n,&m);
        if(n==0&&m==0) break;
        scanf("%d %d",&s,&d);
        memset(cost,-1,sizeof(cost));
        for(int i=0;i<n;i++) adj[i].clear();
        for(int i=0;i<m;i++) {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            adj[a].push_back({c,b});
            cost[a][b]=c;
        }
        fill(dist,dist+505,INF);
        k=s;
        dijkstra(dist,adj);
        go();   // 최단거리 간선 지우기 (가중치 값을 -1로 세팅)
        fill(dist,dist+505,INF);
        dijkstra(dist,adj);
        printf("%d\n",dist[d]==INF?-1:dist[d]);
    }
    return 0;
}