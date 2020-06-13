// 숨바꼭질 5
#include<bits/stdc++.h>
using namespace std;
int n,k,dm[]={1,1,2},dx[]={-1,1,0};
bool visited[3][500010];
queue<int> q;
int bfs(int x) {
	int time=0;
	visited[time][x]=true;
	q.push(x);
	while(!q.empty()) {
		int size=(int)q.size();
		time++;
		while(size--) {
			x=q.front();q.pop();
			for(int i=0;i<3;i++) {
				int nx=x*dm[i]+dx[i];
				if(nx<0||nx>500000) continue;
				if(!visited[time%2][nx]) {
					visited[time%2][nx]=true;
					q.push(nx);
				}
			}
		}
		k+=time;
		if(k>500000) break;
		if(visited[time%2][k]) return time;
	}
	return -1;
}
int main() {
	scanf("%d %d",&n,&k);
	if(n==k) {
		printf("0\n");
		return 0;
	}
	printf("%d\n",bfs(n));
	return 0;
}