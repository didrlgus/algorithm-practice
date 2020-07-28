// 종이자르기
#include<bits/stdc++.h>
using namespace std;
const int INF=-987654321;
int n,m,k,r_cnt,c_cnt,ret=INF,dy[]={0,0,1,-1},dx[]={1,-1,0,0};
bool arr[205][205],visited[205][205];
vector<pair<int,int>> v;
int dfs(int y,int x) {
	visited[y][x]=true;
	int ret=0;
	for(int i=0;i<4;i++) {
		int ny=y+dy[i],nx=x+dx[i];
		if(ny<0||nx<0||ny>=n+r_cnt||nx>=m+c_cnt) continue;
		if(!visited[ny][nx]&&!arr[ny][nx]) ret+=dfs(ny,nx)+1;
	}
	return ret;
}
int main() {
	scanf("%d%d%d",&m,&n,&k);
	for(int i=0;i<k;i++) {
		int a,b;scanf("%d%d",&a,&b);
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	for(auto it:v) {
		if(!it.first) {
			for(int j=0;j<205;j++) arr[it.second+r_cnt][j]=true;
			r_cnt++;
		} else {
			for(int i=0;i<205;i++) arr[i][it.second+c_cnt]=true;
			c_cnt++;
		}
	}
	for(int i=0;i<n+r_cnt;i++) {
		for(int j=0;j<m+c_cnt;j++) {
			if(!visited[i][j]&&!arr[i][j]) {
				ret=max(ret,dfs(i,j)+1);
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}