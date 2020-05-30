// 타일 코드
#include<bits/stdc++.h>
using namespace std;
int n,dp[35],ret;
int main() {
    scanf("%d",&n);
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=n;i++) {
        dp[i]=dp[i-1]+dp[i-2]*2;
    }
    // 중복되는 값을 직접 찾는 것이 아니라, 좌우 대칭인 경우를 이용해 중복된 값을 /2 해주는 방식으로 생각하기
    if(n&1) ret=(dp[n]+dp[(n-1)/2])/2;                  
    else ret=(dp[n]+dp[n/2]+dp[(n-2)/2]*2)/2;   // 가운데에 놓지 않거나 1*2를 2개 놓는 경우(dp[n/2]), 1*2,2*2를 놓는경우(dp[(n-2)/2]*2)
    printf("%d\n",ret);
    return 0;
}