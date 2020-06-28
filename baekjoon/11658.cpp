// 구간 합 구하기 3
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[1030][1030],sum[1030][1030];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d",&arr[i][j]);
            sum[i][j]=sum[i][j-1]+arr[i][j];
        }
    }
    for(int i=0;i<m;i++) {
        int w,ret=0;
        scanf("%d",&w);
        if(w) {
            int y1,x1,y2,x2;
            scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
            for(int i=y1;i<=y2;i++) ret+=sum[i][x2]-sum[i][x1-1];
            printf("%d\n",ret);
        } else {
            int y,x,v;
            scanf("%d %d %d",&y,&x,&v);
            int nv=v-(sum[y][x]-sum[y][x-1]);
            for(int j=x;j<=n;j++) sum[y][j]+=nv;
        }
    }
    return 0;
}