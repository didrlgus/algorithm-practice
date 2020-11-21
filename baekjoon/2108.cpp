// 통계학
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,sum,cnt;
map<int,int> mp;
vector<int> v;
vector<pair<int,int>> vv;
bool cmp(pair<int,int> p1,pair<int,int> p2) {
    if(p1.second==p2.second) return p1.first<p2.first;
    return p1.second>p2.second;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int val;scanf("%d",&val);
        sum+=val;
        mp[val]++;
        v.push_back(val);
    }
    for(auto it:mp) {
        vv.push_back({it.first,it.second});
    }
    sort(v.begin(),v.end());
    sort(vv.begin(),vv.end(),cmp);
    double ret=sum/(double)n;
    int a=round(ret);
    if((int)vv.size()==1) cnt=vv[0].first;
    else if(vv[0].second==vv[1].second) cnt=vv[1].first;
    else cnt=vv[0].first;
    printf("%d\n",a);
    printf("%d\n",v[n/2]);
    printf("%d\n",cnt);
    printf("%d\n",v[n-1]-v[0]);
    return 0;
}