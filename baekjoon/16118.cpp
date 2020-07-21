// 달빛 여우
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
typedef tuple<int,int,bool> tp;
int n,m,k,dist[4005],dist2[4005][3],ret;
vector<pair<int,int>> adj[100005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<tp,vector<tp>,greater<tp>> pq2;
void dijkstra() {
    pq.push(make_pair(0,k));   // 시작점
	dist[k]=0; 
	while(pq.size()) { 
		int here=pq.top().second;
		int here_dist=pq.top().first;
		pq.pop();
		if(dist[here]!=here_dist) continue;
		for(pair<int,int> there:adj[here]){
			int _dist=there.first,_there=there.second;  
			if(dist[_there]>dist[here]+_dist) {
				dist[_there]=dist[here]+_dist; 
				pq.push(make_pair(dist[_there],_there));  
			}  
		}
	} 
}
void dijkstra2() {
	pq2.push(make_tuple(0,k,0));
	dist2[k][0]=0;
	while(pq2.size()) {
		int here_dist,here;
		bool cnt;
		tie(here_dist,here,cnt)=pq2.top();
		pq2.pop();
		if(dist2[here][cnt]!=here_dist) continue;
		for(pair<int,int> there:adj[here]) {
			int _dist=there.first,_there=there.second;
			int d=!cnt?there.first/2:there.first*2;					// cnt가 0이면 2배 빠르게(길이/2), 1이면 2배 느리게(길이*2)
			if(dist2[_there][!cnt]>dist2[here][cnt]+d) {
				dist2[_there][!cnt]=dist2[here][cnt]+d;
				pq2.push(make_tuple(dist2[_there][!cnt],_there,!cnt));
			}
		}
	}
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back({c*2,b});									// 모든 가중치를 짝수로 만들기 위해 *2 수행
        adj[b].push_back({c*2,a});
    }
    k=1;
    fill(dist,dist+4005,INF);
	fill(&dist2[0][0],&dist2[0][0]+4005*3,INF);
    dijkstra();
	dijkstra2();
	for(int i=2;i<=n;i++) {
		if(dist[i]<dist2[i][0]&&dist[i]<dist2[i][1]) ret++;			// 여우가 늑대가 갈 수 있는 모든 2가지 경우보다 더 빠를 경우 +1
	}
	printf("%d\n",ret);
    return 0;
}