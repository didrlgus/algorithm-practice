// 컵라면
#include<bits/stdc++.h>
using namespace std;
int n,ret;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>> pq;
int main() {    
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int d,c;
        scanf("%d %d",&d,&c);
        v.push_back({d,c});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        pq.push(v[i].second);
        ret+=v[i].second;
        if((int)pq.size()>v[i].first) {
            ret-=pq.top();pq.pop();
        }
    }
    printf("%d\n",ret);
    return 0;
}