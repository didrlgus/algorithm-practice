// 전깃줄
#include<bits/stdc++.h>
using namespace std;
int n,dp[105],ret;
vector<pair<int,int>> v;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a,b;scanf("%d%d",&a,&b);
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    fill(dp,dp+105,-1);
    for(int i=0;i<(int)v.size();i++) dp[i]=1;
    for(int i=1;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            if(v[i].second>v[j].second) {
                dp[i]=max(dp[i],dp[j]+1);
                if(ret<dp[i]) ret=dp[i];
            }
        }
    }
    printf("%d\n",n-ret);
    return 0;
}