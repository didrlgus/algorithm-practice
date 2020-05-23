// 사탕가게
#include<bits/stdc++.h>

using namespace std;

int n,m,m1,m2,p1,p2;
int c[5010],p[10010];
int dp[10010];
int main() {
    // dp[j] j원으로 살 수 있는 최대 칼로리
    // dp[j]=max(dp[j],dp[j-p[i]]+c[i])
    while(true) {
        scanf("%d %d.%d",&n,&m1,&m2);
        if(n==0&&m1==0&&m2==0) break;
        m=m1*100+m2;
        fill(&c[0],&c[0]+5010,0);
        fill(&p[0],&p[0]+10010,0);
        fill(&dp[0],&dp[0]+10010,0);
        for(int i=1;i<=n;i++) {
            scanf("%d %d.%d",&c[i],&p1,&p2);
            p[i]=p1*100+p2;
        }
        for(int i=1;i<=n;i++) {
            for(int j=p[i];j<=m;j++) {
                dp[j]=max(dp[j],dp[j-p[i]]+c[i]);
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}