// 등산
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e12;
ll n,m,d,e,arr[100005],dist[100005],dist2[100005],k,ret=-INF;
vector<pair<ll,ll>> adj[200005];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
void dijkstra(ll *dist, vector<pair<ll, ll>> *adj){
    pq.push(make_pair(0, k));   // 시작점
	dist[k]=0; 
	while(pq.size()){ 
		ll here=pq.top().second;
		ll here_dist=pq.top().first;
		pq.pop();
		if(dist[here]!=here_dist) continue;
		for(pair<ll,ll> there:adj[here]){
			ll _dist=there.first,_there=there.second;  
			if(dist[_there]>dist[here]+_dist){
				dist[_there]=dist[here]+_dist; 
				pq.push(make_pair(dist[_there],_there));  
			}  
		}
	} 
}
int main() {
    scanf("%lld %lld %lld %lld",&n,&m,&d,&e);
    for(ll i=1;i<=n;i++) scanf("%lld",&arr[i]);
    for(ll i=0;i<m;i++) {
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        if(arr[a]<arr[b]) adj[a].push_back({c,b});
        else adj[b].push_back({c,a});
    }
    fill(dist,dist+100005,INF);
    fill(dist2,dist2+100005,INF);
    k=1;dijkstra(dist,adj);
    k=n;dijkstra(dist2,adj);
    bool flag=false;
    for(ll i=2;i<=n-1;i++) {
        ll height=arr[i]*e;
        ll distance=(dist[i]+dist2[i])*d;
        ret=max(ret,height-distance);
    }
    if(ret==-INF) printf("Impossible\n");
    else printf("%lld\n",ret);
    return 0;
}