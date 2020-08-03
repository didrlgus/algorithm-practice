// 줄세우기
#include<bits/stdc++.h>
using namespace std;
int n,arr[205],dp[205],ret=1;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        dp[i]=1;
    }
    for(int i=1;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            if(arr[j]<arr[i]&&dp[j]+1>dp[i]) {
                dp[i]=dp[j]+1;
                ret=max(ret,dp[i]);
            }
        }
    }
    printf("%d\n",n-ret);
    return 0;
}