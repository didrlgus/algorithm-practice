// 안녕
#include<bits/stdc++.h>
using namespace std;
int n,L[110],J[110],dp[110];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&L[i]);
    for(int i=0;i<n;i++) scanf("%d",&J[i]);
    for(int i=0;i<n;i++) {
        for(int j=99;j>=L[i];j--) dp[j]=max(dp[j],dp[j-L[i]]+J[i]);
    }
    printf("%d\n",dp[99]);
    return 0;
}