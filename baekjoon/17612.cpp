// 쇼핑몰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct p {
    int id,time,c_id;
};
struct cmp {
    bool operator()(p a, p b){
        if(a.time==b.time) return a.c_id>b.c_id;
        return a.time>b.time;
    }
};
bool cmp2(p a, p b) {
    if(a.time==b.time) return a.c_id>b.c_id;
    return a.time<b.time;
}
int n,k;
ll ret;
priority_queue<p,vector<p>,cmp> pq;
vector<p> v;
int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        if(i<k) {
            pq.push({a,b,i+1});
            continue;
        }
        p t=pq.top();pq.pop();
        pq.push({a,t.time+b,t.c_id});
        v.push_back(t);
    }
    while(!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
    }
    sort(v.begin(),v.end(),cmp2);
    for(int i=0;i<(int)v.size();i++) ret+=1LL*(i+1)*v[i].id;
    printf("%lld\n",ret);
    return 0;
}