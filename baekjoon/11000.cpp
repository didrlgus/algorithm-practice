// 강의실 배정
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<>> pq;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int s,e;scanf("%d%d",&s,&e);
        v.push_back({s,e});
    }
    sort(v.begin(),v.end());
    pq.push(v[0].second);
    for(int i=1;i<(int)v.size();i++) {
        if(pq.top()<=v[i].first) pq.pop();
        pq.push(v[i].second);
    }
    printf("%d\n",(int)pq.size());
    return 0;
}