// 플로이드
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,m,dist[105][105];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) dist[i][j]=(i==j)?0:INF;
    }
    for(int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        dist[a][b]=min(dist[a][b],c);
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(dist[i][j]>=INF) dist[i][j]=0;
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}