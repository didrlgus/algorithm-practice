#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,arr[]={2,5},dp[100010];
int main() {
	scanf("%d",&n);
	fill(dp,dp+100010,INF);
	dp[2]=1;dp[5]=1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<2;j++) {
			if(i-arr[j]>=0) dp[i]=min(dp[i],dp[i-arr[j]]+1);
		}
	}
	printf("%d\n",dp[n]==INF?-1:dp[n]);
	return 0;
}