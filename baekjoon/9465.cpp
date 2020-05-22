// 스티커
#include<bits/stdc++.h>

using namespace std;

int t,M;
int arr[2][100010];
int dp[100010][10];
// 이전 current 열에서 status에 맞는 스티커를 떼어냈을때 최대값 반환, status(0->스티커 안땜, 1->current열 위, 2->current열 아래)
int dfs(int current,int status) {
    if(current==M) return 0;
    if(dp[current][status]!=-1) return dp[current][status];

    int& ret=dp[current][status];
    int zero=dfs(current+1,0);
    if(status!=1) zero=max(zero,dfs(current+1,1)+arr[0][current]);      // 이전 열에서 위쪽 스티커를 안땐 경우
    if(status!=2) zero=max(zero,dfs(current+1,2)+arr[1][current]);           // 이전 열에서 아래쪽 스티커를 안땐 경우
    ret=zero;
    return ret;
}
int main() {

    scanf("%d",&t);
    while(t--) {
        int m;
        scanf("%d",&m);
        M=m;
        fill(&dp[0][0],&dp[0][0]+100010*10,-1);
        fill(&arr[0][0],&arr[0][0]+2*100010,0);
        for(int i=0;i<2;i++) {
            for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
        }
        printf("%d\n",dfs(0,0));
    }

    return 0;
}