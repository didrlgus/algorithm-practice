// 가장 긴 증가하는 부분 수열
#include<bits/stdc++.h>
using namespace std;
int n,arr[1010],dp[1010],ret=1;
int main() {
    scanf("%d",&n);
    fill(dp,dp+1010,-1);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        dp[i]=1;
    }
    for(int i=1;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            if(arr[j]<arr[i]) {
                dp[i]=max(dp[i],dp[j]+1);
                if(ret<dp[i]) ret=dp[i];
            }
        }
    }
    printf("%d\n",ret);
    return 0;
}