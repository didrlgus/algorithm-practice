// 빈도 정렬
#include<bits/stdc++.h>
using namespace std;
int n,m,order;
map<int,pair<int,int>> mp;
struct p {
    int y,x,z;
};
vector<p> v;
bool cmp(p p1, p p2) {
    if(p1.x==p2.x) {
        return p1.z<p2.z;
    }
    return p1.x>p2.x;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        int a;scanf("%d",&a);
        if(mp.find(a)==mp.end()) {
            mp[a]={1,order++};
        } else mp[a].first++;
    }
    for(auto it:mp) v.push_back({it.first,it.second.first,it.second.second});
    sort(v.begin(),v.end(),cmp);
    for(auto it:v) {
        for(int i=0;i<it.x;i++) printf("%d ",it.y);
    }
    return 0;
}