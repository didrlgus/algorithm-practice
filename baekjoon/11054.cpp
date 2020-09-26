// 가장 긴 바이토닉 부분 수열
#include<bits/stdc++.h>
using namespace std;
int n,arr[1005],dp[1005],dp2[1005],ret=1;
int main() {
    scanf("%d",&n);
    fill(dp,dp+1005,-1);
    fill(dp2,dp2+1005,-1);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        dp[i]=1;dp2[i]=1;
    }
    for(int i=1;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            if(arr[j]<arr[i]) dp[i]=max(dp[i],dp[j]+1);
        }
    }
    for(int i=n-1;i>=1;i--) {
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[i]) dp2[i]=max(dp2[i],dp2[j]+1);
        }
    }
    for(int i=0;i<n;i++) ret=max(ret,dp[i]+dp2[i]);
    printf("%d\n",ret-1);
    return 0;
}