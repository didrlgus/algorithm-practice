// 과제
#include<bits/stdc++.h>
using namespace std;
int n,ret;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>> pq;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int d,w;
        scanf("%d %d",&d,&w);
        v.push_back({d,w});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        ret+=v[i].second;
        pq.push(v[i].second);
        if((int)pq.size()>v[i].first) {
            ret-=pq.top();
            pq.pop();
        }
    }
    printf("%d\n",ret);
    return 0;
}