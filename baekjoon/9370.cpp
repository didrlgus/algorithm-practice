// 미확인 도착지
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int tc,k,dist[2005];
vector<pair<int,int>> adj[2005];
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
			int _dist=there.first,_there=there.second;  
			if(dist[_there]>dist[here]+_dist){
				dist[_there]=dist[here]+_dist; 
				pq.push(make_pair(dist[_there],_there));  
			}  
		}
	} 
}
int main() {
    scanf("%d",&tc);
    while(tc--) {
        int n,m,t,s,g,h;
        vector<int> dest;
        scanf("%d %d %d %d %d %d",&n,&m,&t,&s,&g,&h);
        for(int i=0;i<2005;i++) adj[i].clear();
        for(int i=0;i<m;i++) {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if((a==g&&b==h)||(a==h&&b==g)) {
                adj[a].push_back({c*2-1,b});        // 홀수일때(꼭 지나는 간선의 가중치) *2-1해도 최단거리에 영향x
                adj[b].push_back({c*2-1,a});  
            } else {
                adj[a].push_back({c*2,b});          // *2하면 무조건 짝수로 만듬
                adj[b].push_back({c*2,a});
            }
        }
        for(int i=0;i<t;i++) {
            int a;scanf("%d",&a);
            dest.push_back(a);
        }
        sort(dest.begin(),dest.end());
        fill(dist,dist+2005,INF);
        k=s;
        dijkstra(dist,adj);
        for(auto it:dest) if(dist[it]&1) printf("%d ",it);
        printf("\n");
    }
    return 0;
}