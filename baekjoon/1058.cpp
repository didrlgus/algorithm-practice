// 친구
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,dist[55][55],ret;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    fill(&dist[0][0],&dist[0][0]+55*55,INF);
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s;cin>>s;
        for(int j=1;j<=(int)s.size();j++) {
            if(s.at(j-1)=='Y') dist[i][j]=1;
        }
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
    for(int i=1;i<=n;i++) {
        int cnt=0;
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            if(dist[i][j]==1||dist[i][j]==2) cnt++;
        }
        ret=max(ret,cnt);
    }
    printf("%d\n",ret);
    return 0;
}