// 타일 채우기
#include<bits/stdc++.h>
using namespace std;
int tc;
int main() {
    scanf("%d",&tc);
    while(tc--) {
        int n;
        scanf("%d",&n);
        int dp[n+1];
        fill(dp,dp+n+1,0);
        dp[0]=1;dp[1]=1;dp[2]=5;
        for(int i=3;i<=n;i++) {
            dp[i]=dp[i-1]+dp[i-2]*4;
            for(int j=i-3;j>=0;j--) {
                if((i-j)&1) dp[i]+=dp[j]*2;     // 차이가 홀수일 경우 새로운 조합이 2개 생김
                else dp[i]+=dp[j]*3;            // 차이가 짝수일 경우 새로운 조합이 3개 생김
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}