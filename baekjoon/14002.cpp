// 가장 긴 증가하는 부분 수열 4
#include<bits/stdc++.h>
using namespace std;
int n,arr[1010],dp[1010],ret=1,tmp[1010];
void dfs(int idx) {
    if(idx==-1) return;
    dfs(tmp[idx]);
    printf("%d ",arr[idx]);
}
int main() {
    scanf("%d",&n);
    fill(dp,dp+1010,-1);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        dp[i]=1;
    }
    fill(tmp,tmp+1010,-1);
    int idx=0;
    for(int i=1;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            if(arr[j]<arr[i]&&dp[i]<dp[j]+1) {
                dp[i]=dp[j]+1;
                tmp[i]=j;
                if(ret<dp[i]) {
                    ret=dp[i];
                    idx=i;
                }
            }
        }
    }
    printf("%d\n",ret);
    dfs(idx);
    return 0;
}