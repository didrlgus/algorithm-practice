// 자두나무
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int t,w,arr[1005],dp[1005][35][3];
int dfs(int time,int hp,int cur_tree) {
	if(time==t) return 0;
	int& ret=dp[time][hp][cur_tree];
	if(ret!=-1) return ret;
	int next_tree=(cur_tree==1)?2:1;
	int val=(arr[time]==cur_tree)?1:0;
	if(hp>0) {
		ret=max(ret,dfs(time+1,hp-1,next_tree)+!val);
		ret=max(ret,dfs(time+1,hp,cur_tree)+val);
	} else ret=max(ret,dfs(time+1,hp,cur_tree)+val);
	return ret;
}
int main() {
	scanf("%d %d",&t,&w);
	for(int i=0;i<t;i++) scanf("%d",&arr[i]);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(0,w,1));
	return 0;
}