// 동전 1
#include <bits/stdc++.h>

using namespace std;

// dp[i][j]->i번째 수를 선택하여 j를 만들 수 있는 모든 경우의 수
// dp[i][j]=dp[i-1][j]+dp[i][j-arr[i]]
vector<int> dp1;     // 벡터가 값을 복사하기 쉬우므로 벡터로 선언
vector<int> dp2;
int arr[110];
int n,k;
int main() {
    scanf("%d %d",&n,&k);
    dp1.resize(k+1); dp2.resize(k+1);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    for(int j=0;j<=k;j+=arr[0]) dp1[j]=1;    // base
    
    for(int i=1;i<n;i++) {
        fill(dp2.begin(),dp2.end(),0);
        for(int j=0;j<=k;j++) {
            if(arr[i]<=j) dp2[j]=dp1[j]+dp2[j-arr[i]];
            else dp2[j]=dp1[j];
        }
        dp1=dp2;
    }

    printf("%d\n",dp1[k]);

    return 0;
}