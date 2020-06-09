// 강의실 배정
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>> pq;
int main() {
    scanf("%d",&n);
    while(n--) {
        int s,e;
        scanf("%d %d",&s,&e);
        v.push_back({s,e});
    }
    sort(v.begin(),v.end());
    pq.push(v[0].second);
    for(int i=1;i<(int)v.size();i++) {
        if(pq.top()>v[i].first) pq.push(v[i].second);
        else {
            pq.pop();
            pq.push(v[i].second);
        }
    }
    printf("%d\n",pq.size());
    return 0;
}