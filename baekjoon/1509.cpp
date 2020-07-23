// 팰린드롬 분할
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
string s;
int n,dp2[2505];
bool dp[2505][2505];
int dfs(int here) {
	if(here>=n) return 0;
	int& ret=dp2[here];
	if(ret!=INF) return ret;
	for(int i=here;i<n;i++) {
		if(dp[here][i]) ret=min(ret,dfs(i+1)+1);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	n=(int)s.size();
	for(int i=0;i<n;i++) dp[i][i]=true;
	for(int i=0;i<n-1;i++) if(s[i]==s[i+1]) dp[i][i+1]=true;
	for(int len=3;len<=n;len++) {
		for(int j=0;j<=n-len;j++) {
			if(s[j]==s[j+len-1]&&dp[j+1][j+len-2]) dp[j][j+len-1]=true;
		}
	}
	fill(dp2,dp2+2505,INF);
	printf("%d\n",dfs(0));
	return 0;
}