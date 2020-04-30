// 빈도 정렬
#include<bits/stdc++.h>

using namespace std;

int n,c;
map<int,pair<int,int>> mp;      // 숫자, 개수, 순서

bool cmp(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2) {
    if(p1.second.first==p2.second.first) {
        return p1.second.second<p2.second.second;
    }
    return p1.second.first>p2.second.first;
}

int main() {
    vector<pair<int,pair<int,int>>> v;
    scanf("%d %d",&n,&c);

    int order=1;
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);

        if(mp.find(a)!=mp.end()) {      // map에 이미 존재
            mp[a].first++;
        } else {
            mp.insert({a,{1,order++}});
        }
    }

    for(auto iter:mp) {
        v.push_back({iter.first,{iter.second.first,iter.second.second}});
    }

    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v[i].second.first;j++) {
            printf("%d ",v[i].first);
        }
    }

    return 0;
}