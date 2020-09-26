// 포도주 시식
#include<bits/stdc++.h>
using namespace std;
int n,arr[10005],dp[10005];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    dp[1]=arr[1],dp[2]=dp[1]+arr[2];
    for(int i=3;i<=n;i++) dp[i]=max(dp[i-3]+arr[i-1]+arr[i],max(dp[i-2]+arr[i],dp[i-1]));
    printf("%d\n",dp[n]);
    return 0;
}