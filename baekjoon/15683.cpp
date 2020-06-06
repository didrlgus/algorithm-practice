// 감시
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,arr[15][15],tmp[15][15],ret=INF;
vector<pair<pair<int,int>,int>> v;
vector<int> v2;
void right(int y,int x) {
	for(int j=x;j<m;j++) {
		if(tmp[y][j]==6) break;
		if(tmp[y][j]==0) tmp[y][j]=1;
	}
}
void down(int y,int x) {
	for(int i=y;i<n;i++) {
		if(tmp[i][x]==6) break;
		if(tmp[i][x]==0) tmp[i][x]=1;
	}
}
void left(int y,int x) {
	for(int j=x;j>=0;j--) {
		if(tmp[y][j]==6) break;
		if(tmp[y][j]==0) tmp[y][j]=1;
	}
}
void up(int y,int x) {
	for(int i=y;i>=0;i--) {
		if(tmp[i][x]==6) break;
		if(tmp[i][x]==0) tmp[i][x]=1;
	}
}
void dfs(vector<int>& v2) {
	if((int)v2.size()==(int)v.size()) {
		memcpy(tmp,arr,sizeof(arr));
		for(int i=0;i<(int)v.size();i++) {
			int y=v[i].first.first,x=v[i].first.second,camera=v[i].second;
			if(camera==1) {
				if(v2[i]==0) right(y,x);
				else if(v2[i]==1) down(y,x);
				else if(v2[i]==2) left(y,x);
				else up(y,x);
			} else if(camera==2) {
				if(v2[i]==0||v2[i]==2) {
					right(y,x);left(y,x);
				} else {
					up(y,x);down(y,x);
				}
			} else if(camera==3) {
				if(v2[i]==0) {
					up(y,x);right(y,x);
				} else if(v2[i]==1) {
					right(y,x);down(y,x);
				} else if(v2[i]==2) {
					left(y,x);down(y,x);
				} else {
					left(y,x);up(y,x);
				}
			} else if(camera==4) {
				if(v2[i]==0) {
					up(y,x);right(y,x);left(y,x);
				} else if(v2[i]==1) {
					up(y,x);right(y,x);down(y,x);
				} else if(v2[i]==2) {
					left(y,x);right(y,x);down(y,x);
				} else {
					left(y,x);up(y,x);down(y,x);
				}
			} else {
				up(y,x);right(y,x);down(y,x);left(y,x);
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) if(tmp[i][j]==0) cnt++;
		}
		ret=min(ret,cnt);
		return;
	}
	for(int i=0;i<4;i++) {
		v2.push_back(i);
		dfs(v2);
		v2.pop_back();
	}
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			scanf("%d",&arr[i][j]);
			if(arr[i][j]>=1&&arr[i][j]<=5) {
				v.push_back({{i,j},arr[i][j]});
				arr[i][j]=0;
			}
		}
	}
	dfs(v2);
	printf("%d\n",ret);
	return 0;
}