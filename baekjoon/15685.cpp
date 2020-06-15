// 드래곤 커브
#include<bits/stdc++.h>
using namespace std;
int n,ret,dy[]={0,-1,0,1},dx[]={1,0,-1,0};
struct p {
	int y,x,d,g;
};
vector<p> dc;
vector<int> v[5][15];
bool visited[105][105];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		dc.push_back({b,a,c,d});
		visited[b][a]=true;
	}
	for(int i=0;i<4;i++) v[i][0].push_back(i);
	for(int i=0;i<4;i++) {
		for(int j=1;j<=10;j++) {
			vector<int> vv=v[i][j-1];
			for(int k=(int)vv.size()-1;k>=0;k--) vv.push_back((vv[k]+1)%4);
			v[i][j]=vv;
		}
	}
	for(auto iter:dc) {
		int y=iter.y,x=iter.x,d=iter.d,g=iter.g;
		int ny=y,nx=x;
		for(auto dir:v[d][g]) {
			ny+=dy[dir],nx+=dx[dir];
			if(ny<0||nx<0||ny>100||nx>100) continue;
			if(!visited[ny][nx]) visited[ny][nx]=true;
		}		
	}
	for(int i=0;i<100;i++) {
		for(int j=0;j<100;j++) {
			if(visited[i][j]&&visited[i][j+1]&&visited[i+1][j]&&visited[i+1][j+1]) ret++;
		}
	}
	printf("%d\n",ret);
	return 0;
}