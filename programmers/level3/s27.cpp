// 멀리 뛰기
#include <bits/stdc++.h>

using namespace std;

long long dp[2010];
long long solution(int n) {
    long long answer = 0;

    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++) dp[i]=(dp[i-2]+dp[i-1])%1234567;
    answer=dp[n];

    return answer;
}

int main() {

    int n=5;
    long long result=solution(n);
    printf("%lld\n",result);

    return 0;
}