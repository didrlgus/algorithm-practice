// 영역 구하기
#include<bits/stdc++.h>
using namespace std;
int n,m,k,arr[105][105],dy[]={0,0,1,-1},dx[]={1,-1,0,0},ret;
bool visited[105][105];
vector<int> v;
int dfs(int y,int x) {
	visited[y][x]=true;
	int cnt=0;
	for(int i=0;i<4;i++) {
		int ny=y+dy[i],nx=x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=m) continue;
		if(!visited[ny][nx]&&!arr[ny][nx]) cnt+=dfs(ny,nx)+1;
	}
	return cnt;
}
int main() {
	scanf("%d%d%d",&m,&n,&k);
	for(int t=0;t<k;t++) {
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int i=a;i<c;i++) {
			for(int j=b;j<d;j++) arr[i][j]=1;
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(!visited[i][j]&&!arr[i][j]) {
				ret++;
				v.push_back(dfs(i,j)+1);
			}
		}
	}
	sort(v.begin(),v.end());
	printf("%d\n",ret);
	for(auto it:v) printf("%d ",it);
	return 0;
}