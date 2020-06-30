// 스티커 수집
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,k,money,ret=INF;
vector<int> cost,value;
map<int,int> mp[2];
void dfs(int here,bool flag,int c,int v) {
    if(here==(flag?n:n/2)) {
        auto it=mp[flag].find(v);
        if(it==mp[flag].end()) mp[flag][v]=c;
        else it->second=min(it->second,c);
        return;
    }
    dfs(here+1,flag,c+cost[here],v+value[here]);
    dfs(here+1,flag,c,v);
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        cost.push_back(a);
    }
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        value.push_back(a);
    }
    scanf("%d %d",&k,&m);
    for(int i=0;i<m;i++) {
        int a;
        scanf("%d",&a);
        money+=cost[a];
    }
    dfs(0,false,0,0);
    dfs(n/2,true,0,0);
    auto it2=mp[1].end();
    int r=(--it2)->second;
    for(auto it1=mp[0].begin();it1!=mp[0].end();it1++) {
        while(it1->first+it2->first>=k) {
            r=min(r,it2->second);
            ret=min(ret,it1->second+r);
            if(it2==mp[1].begin()) break;
            else if(it1->first+(--it2)->first<k) {
                it2++;
                break;
            }
        }
    }
    printf("%d\n",ret==INF?-1:max(0,ret-money));
    return 0;
}