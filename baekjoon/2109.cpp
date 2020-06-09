// 순회강연
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>> pq;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int p,d;
        scanf("%d %d",&p,&d);
        v.push_back({d,p});
    }
    sort(v.begin(),v.end());
    int ret=0;
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