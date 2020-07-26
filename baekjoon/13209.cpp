#include <bits/stdc++.h>
using namespace std;  
typedef long long ll;   
const int max_n = 100004;
vector<ll> adj[max_n]; 
ll t, n, k, person[max_n], visited[max_n], from, to, cnt, lo, hi, ret, mid;
ll go(ll here){
    visited[here] = 1; 
    priority_queue<ll> pq; 
    ll sum = 0; 
    for(ll there : adj[here]){
        if(visited[there]) continue; 
        ll ret = go(there); 
        sum += ret;
        pq.push(ret);
    }
    while(pq.size() && sum + person[here] > mid){
        cnt++; 
        sum -= pq.top();
        pq.pop();
    } 
    return sum + person[here];
}
bool check(){
    cnt = 0; 
    memset(visited, 0, sizeof(visited)); 
    go(1); 
    return cnt <= k;
} 
int main(){   
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	cin >> t;  
    while(t--){  
		cin >> n >> k;  
        memset(person, 0, sizeof(person)); 
        lo = 0, hi = 0, ret = 0;
        for(int i = 1; i <= n; i++){
			cin >> person[i];
			adj[i].clear(); 
			lo = max(lo, person[i]), hi += person[i];
        }
        for(int i = 0; i < n - 1; i++){
			cin >> from >> to;  
            adj[from].push_back(to);
            adj[to].push_back(from);
        }   
        while(lo <= hi){
            mid = (lo + hi) / 2;   
            if(check()){
                hi = mid - 1; 
                ret = mid;
            }else lo = mid + 1; 
        }
		cout << ret << '\n'; 
    }   
    return 0;
} 