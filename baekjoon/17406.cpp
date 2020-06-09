// 배열 돌리기 4
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,k,arr[55][55],tmp[55][55],ret=INF;
vector<pair<pair<int,int>,int>> v;
vector<int> v2;
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};
int sy,sx,ey,ex;
vector<pair<int,int>> vv;
void go(int y,int x,int dir) {
	int ny=y+dy[dir],nx=x+dx[dir];
	if(ny==sy&&nx==ex) dir++;
	if(ny==ey&&nx==ex) dir++;
	if(ny==ey&&nx==sx) dir++;
	vv.push_back({ny,nx});
	if(ny==sy&&nx==sx) return;
	go(ny,nx,dir);
}
void func() {
	for(auto iter:v2) {
		int y=v[iter].first.first,x=v[iter].first.second,s=v[iter].second;
		for(int i=1;i<=s;i++) {
			sy=y-i;sx=x-i;ey=y+i,ex=x+i;
			vv.clear();
			go(sy,sx,0);
			vector<int> vvv;
			for(auto it:vv) vvv.push_back(tmp[it.first][it.second]);
			rotate(vvv.begin(),vvv.begin()+vvv.size()-1,vvv.end());
			for(int j=0;j<(int)vv.size();j++) tmp[vv[j].first][vv[j].second]=vvv[j];
		}
	}
	for(int i=0;i<n;i++) {
		int sum=0;
		for(int j=0;j<m;j++) sum+=tmp[i][j];
		ret=min(ret,sum);
	}
}
int main() {
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
	}
	for(int i=0;i<k;i++) {
		int y,x,s;
		scanf("%d %d %d",&y,&x,&s);
		y--;x--;
		v.push_back({{y,x},s});
		v2.push_back(i);
	}
	do {
		memcpy(tmp,arr,sizeof(arr));
		func();
	} while(next_permutation(v2.begin(),v2.end()));
	printf("%d\n",ret);
	return 0;
}