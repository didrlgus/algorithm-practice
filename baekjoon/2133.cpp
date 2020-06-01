// 타일 채우기
#include<bits/stdc++.h>
using namespace std;
int n,dp[35]={1,0,3,0};
int main() {
    scanf("%d",&n);
    for(int i=4;i<=n;i+=2) {
        dp[i]=dp[i-2]*3;
        for(int j=i-4;j>=0;j-=2) {      // 4이상부터 새로운 조합이 2개씩 추가됨(양옆을 2*1막대로 채울경우)
            dp[i]+=dp[j]*2;
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}