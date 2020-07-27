// 안전 영역
#include<bits/stdc++.h>
using namespace std;
const int INF=-987654321;
int n,arr[105][105],dy[]={0,0,1,-1},dx[]={1,-1,0,0},ret,mx_h=INF;
bool visited[105][105];
void dfs(int y,int x,int h) {
	visited[y][x]=true;
	for(int i=0;i<4;i++) {
		int ny=y+dy[i],nx=x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n) continue;
		if(!visited[ny][nx]&&arr[ny][nx]>h) dfs(ny,nx,h);
	}
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf("%d",&arr[i][j]);
			mx_h=max(mx_h,arr[i][j]);
		}
	}
	for(int h=0;h<=mx_h;h++) {
		int cnt=0;
		fill(&visited[0][0],&visited[0][0]+105*105,false);
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(!visited[i][j]&&arr[i][j]>h) {
					cnt++;
					dfs(i,j,h);
				}
			}
		}
		ret=max(ret,cnt);
	}
	printf("%d\n",ret);
	return 0;
}