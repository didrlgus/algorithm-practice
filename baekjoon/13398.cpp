// 연속합 2
#include<bits/stdc++.h>
using namespace std;
int n,arr[100005],dp[100005][3],ret;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    dp[0][0]=arr[0],dp[0][1]=arr[0];            // 안고르는 것 없으므로 dp[0][1]=arr[0]
    ret=dp[0][0];
    for(int i=1;i<n;i++) {
        dp[i][0]=max(dp[i-1][0]+arr[i],arr[i]);
        dp[i][1]=max(dp[i-1][1]+arr[i],dp[i-1][0]);
        ret=max(ret,max(dp[i][0],dp[i][1]));
    }
    printf("%d\n",ret);
    return 0;
}