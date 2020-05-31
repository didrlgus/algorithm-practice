// 막대 배치
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tc;
ll dp[25][25][25];
int main() {
    scanf("%d",&tc);
    // dp[n][l][r] -> 왼쪽에서 볼 때 l개, 오른쪽에서 볼 때 r개가 보이도록 n개의 막대를 세우는 경우의 수
    dp[1][1][1]=1;
    for(int i=2;i<=20;i++) {
        for(int j=1;j<=i;j++) {
            for(int k=1;k<=i;k++) {
                // 1이 가장 왼쪽, 오른쪽, 2~i-1 위치에 있을 경우
                dp[i][j][k]=dp[i-1][j-1][k]+dp[i-1][j][k-1]+dp[i-1][j][k]*(i-2);
            }
        }
    }
    while(tc--) {
        int n,l,r;
        scanf("%d %d %d",&n,&l,&r);
        printf("%lld\n",dp[n][l][r]);
    }
    return 0;
}