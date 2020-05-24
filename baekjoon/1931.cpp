// 회의실 배정
#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> v;
bool cmp(pair<int,int> p1,pair<int,int> p2) {
    if(p1.second==p2.second) return p1.first<p2.first;
    return p1.second<p2.second;
}

int main() {

    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    int e=v[0].second;
    int cnt=1;
    for(int i=1;i<n;i++) {
        if(e<=v[i].first) {
            e=v[i].second;
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}