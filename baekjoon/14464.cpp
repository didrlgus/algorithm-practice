// 소가 길을 건너간 이유 4
#include<bits/stdc++.h>
using namespace std;
int c,n,ret;
vector<int> v1;
vector<pair<int,int>> v2;
bool cmp(pair<int,int> p1,pair<int,int> p2) {
    if(p1.second==p2.second) return p1.first<p2.first;
    return p1.second<p2.second;
}
int main() {
    scanf("%d %d",&c,&n);
    for(int i=0;i<c;i++) {
        int a;
        scanf("%d",&a);
        v1.push_back(a);
    }
    for(int i=0;i<n;i++) {
        int s,e;
        scanf("%d %d",&s,&e);
        v2.push_back({s,e});
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),cmp);
    for(auto it:v2) {
        auto it2=lower_bound(v1.begin(),v1.end(),it.first);
        if(it2!=v1.end()&&*it2<=it.second) {
            ret++;
            v1.erase(it2);
        }
    }
    printf("%d\n",ret);
    return 0;
}