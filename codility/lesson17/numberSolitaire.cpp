#include<bits/stdc++.h>
using namespace std;
const int INF=-2e9;
int n,dp[100005];
int solution(vector<int> &A) {
    n=(int)A.size();
    if(n==2) return A[0]+A[1];
    fill(dp,dp+100005,INF);
    dp[0]=A[0];
    for(int i=1;i<n;i++) {
        for(int j=1;j<=6;j++) {
            if(j>i) break;
            dp[i]=max(dp[i],dp[i-j]+A[i]);
        }
    }
    return dp[n-1];
}