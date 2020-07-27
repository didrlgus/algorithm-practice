// 미로 탐색
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[105][105],dy[]={0,0,1,-1},dx[]={1,-1,0,0},visited[105][105];
queue<pair<int,int>> q;
int bfs(int y,int x) {
	visited[y][x]=1;
	q.push({y,x});
	while(!q.empty()) {
		tie(y,x)=q.front();q.pop();
		for(int i=0;i<4;i++) {
			int ny=y+dy[i],nx=x+dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m) continue;
			if(!visited[ny][nx]&&arr[ny][nx]) {
				visited[ny][nx]=visited[y][x]+1;
				q.push({ny,nx});
			}
		}
	}
	return visited[n-1][m-1];
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) scanf("%1d",&arr[i][j]);
	}
	printf("%d\n",bfs(0,0));
	return 0;
}