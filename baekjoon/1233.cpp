// 주사위
#include<bits/stdc++.h>
using namespace std;
int a,b,c;
map<int,int> mp;
vector<pair<int,int>> v;
bool cmp(pair<int,int> p1, pair<int,int> p2) {
    if(p1.second==p2.second) return p1.first<p2.first;
    return p1.second>p2.second;
}
int main() {
    scanf("%d %d %d",&a,&b,&c);
    for(int i=1;i<=a;i++) {
        for(int j=1;j<=b;j++) {
            for(int k=1;k<=c;k++) mp[i+j+k]++;
        }
    }
    for(auto it:mp) v.push_back({it.first,it.second});
    sort(v.begin(),v.end(),cmp);
    printf("%d\n",v.front().first);
    return 0;
}