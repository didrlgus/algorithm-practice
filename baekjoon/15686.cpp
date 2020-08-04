// 치킨 배달
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,arr[55][55],ret=INF;
vector<int> v,v2,home;
int getDist(int sy,int sx,int ey,int ex) {
    return abs(sy-ey)+abs(sx-ex);
}
void combi(int here) {
    if((int)v2.size()==m) {
        int tot_dist=0;
        for(auto it:home) {
            int dist=INF;
            int sy=it/100,sx=it%100;
            for(auto it2:v2) dist=min(dist,getDist(sy,sx,v[it2]/100,v[it2]%100));
            tot_dist+=dist;
        }
        ret=min(ret,tot_dist);
        return;
    }
    for(int i=here+1;i<(int)v.size();i++) {
        v2.push_back(i);
        combi(i);
        v2.pop_back();
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==1) home.push_back(i*100+j);
            if(arr[i][j]==2) v.push_back(i*100+j);
        }
    }
    combi(-1);
    printf("%d\n",ret);
    return 0;
}