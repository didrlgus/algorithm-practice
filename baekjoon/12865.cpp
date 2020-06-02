// 평범한 배낭
#include<bits/stdc++.h>
using namespace std;
int n,k,w[110],v[110],dp[100010]; 
int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d %d",&w[i],&v[i]);
    for(int i=0;i<n;i++) {
        for(int j=k;j>=w[i];j--) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }
    printf("%d\n",dp[k]);
    return 0;
}