#include<bits/stdc++.h>
using namespace std;
int n;
double arr[10010],dp[10010],ret;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    dp[0]=arr[0];
    for(int i=1;i<n;i++) {
        dp[i]=max(dp[i-1],1.0)*arr[i];
        ret=max(ret,dp[i]);
    }
    printf("%.3lf\n",ret);
    return 0;
}