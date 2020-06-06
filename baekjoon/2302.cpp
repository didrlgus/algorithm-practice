// 극장 좌석
#include<bits/stdc++.h>
using namespace std;
int n,m,dp[45],ret=1;
vector<int> v;
int main() {
	scanf("%d %d",&n,&m);
	dp[0]=1;dp[1]=1;
	for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
	v.push_back(0);
	for(int i=0;i<m;i++) {
		int a;
		scanf("%d",&a);
		v.push_back(a);
	}
	for(int i=m;i>=1;i--) {
		ret*=dp[v[i]-v[i-1]-1];
	}
	ret*=dp[n-v.back()];
	printf("%d\n",ret);
	return 0;
}