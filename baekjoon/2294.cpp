// 동전 2
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,k,coin[105],dp[100005];
int main() {
	scanf("%d %d",&n,&k);
	fill(dp,dp+100005,INF);
	for(int i=0;i<n;i++) {
		scanf("%d",&coin[i]);
		dp[coin[i]]=1;
	}
	for(int i=0;i<=k;i++) {
		for(int j=0;j<n;j++) if(i-coin[j]>=0) dp[i]=min(dp[i],dp[i-coin[j]]+1);
	}
	printf("%d\n",dp[k]==INF?-1:dp[k]);
	return 0;
}