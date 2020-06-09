// 보석 도둑
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll ret;
vector<pair<int,int>> v;
vector<int> vv;
priority_queue<ll> pq;
int main() {    
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        int weight,price;
        scanf("%d %d",&weight,&price);
        v.push_back({weight,price});
    }
    for(int i=0;i<k;i++) {
        int c;
        scanf("%d",&c);
        vv.push_back(c);
    }
    sort(v.begin(),v.end());
    sort(vv.begin(),vv.end());
    int idx=0;
    for(int i=0;i<k;i++) {
        while(idx<n&&vv[i]>=v[idx].first) pq.push(v[idx++].second);
        if(!pq.empty()) {
            ret+=pq.top();pq.pop();
        }
    }
    printf("%lld\n",ret);
    return 0;
}