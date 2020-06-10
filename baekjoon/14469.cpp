// 소가 길을 건너간 이유 3
#include<bits/stdc++.h>
using namespace std;
int n,ret;
vector<pair<int,int>> v;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int s,t;
        scanf("%d %d",&s,&t);
        v.push_back({s,t});
    }
    sort(v.begin(),v.end());
    ret=v[0].first+v[0].second;
    for(int i=1;i<(int)v.size();i++) {
        if(v[i].first>ret) ret=v[i].first;
        ret+=v[i].second;
    }
    printf("%d\n",ret);
    return 0;
}