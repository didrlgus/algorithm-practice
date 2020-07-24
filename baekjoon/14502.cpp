// 연구소
#include<bits/stdc++.h>
using namespace std;
const int INF=-987654321;
int n,m,arr[15][15],tmp[15][15],ret=INF,dy[]={0,0,1,-1},dx[]={1,-1,0,0};
vector<int> v1,v2;
bool visited[15][15];
queue<pair<int,int>> q;
void bfs(int y,int x) {
	visited[y][x]=true;
	q.push({y,x});
	while(!q.empty()) {
		tie(y,x)=q.front();q.pop();
		for(int i=0;i<4;i++) {
			int ny=y+dy[i],nx=x+dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m) continue;
			if(!visited[ny][nx]&&tmp[ny][nx]==0) {
				visited[ny][nx]=true;
				tmp[ny][nx]=2;
				q.push({ny,nx});
			}
		}
	}
}
void combi(int here) {
	if((int)v2.size()==3) {
		memcpy(tmp,arr,sizeof(arr));
		fill(&visited[0][0],&visited[0][0]+15*15,false);
		for(auto it:v2) tmp[v1[it]/100][v1[it]%100]=1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(!visited[i][j]&&tmp[i][j]==2) bfs(i,j);
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) if(tmp[i][j]==0) cnt++;
		}
		ret=max(ret,cnt);
		return;
	}
	for(int i=here+1;i<(int)v1.size();i++) {
		v2.push_back(i);
		combi(i);
		v2.pop_back();
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			scanf("%d",&arr[i][j]);
			if(!arr[i][j]) v1.push_back(i*100+j);
		}
	}
	combi(-1);
	printf("%d\n",ret);
	return 0;
}