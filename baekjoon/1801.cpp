// 직사각형 만들기
#include<bits/stdc++.h>
using namespace std;
int n,arr[20],dp[75][75][75][75],ret;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    dp[0][0][0][0]=1;
    for(int i=0;i<n;i++) {
        for(int a=70;a>=0;a--) {
            for(int b=70;b>=0;b--) {
                for(int c=70;c>=0;c--) {
                    for(int d=70;d>=0;d--) {
                        if(a-arr[i]>=0) dp[a][b][c][d]|=dp[a-arr[i]][b][c][d];
                        if(b-arr[i]>=0) dp[a][b][c][d]|=dp[a][b-arr[i]][c][d];
                        if(c-arr[i]>=0) dp[a][b][c][d]|=dp[a][b][c-arr[i]][d];
                        if(d-arr[i]>=0) dp[a][b][c][d]|=dp[a][b][c][d-arr[i]];
                    }
                }
            }
        }
    }
    for(int i=1;i<=70;i++) {
        for(int j=1;j<=70;j++) if(dp[i][i][j][j]) ret=max(ret,i*j);
    }
    if(ret==0) printf("-1\n");
    else printf("%d\n",ret);
    return 0;
}