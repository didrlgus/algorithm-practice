// 감시
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,arr[10][10],tmp[10][10],ret=INF;
vector<pair<pair<int,int>,int>> cctv;
vector<int> v;
void right(int y,int x) {
	for(int j=x+1;j<m;j++) {
		if(tmp[y][j]==6) break;
		tmp[y][j]=1;
	}
}
void down(int y,int x) {
	for(int i=y+1;i<n;i++) {
		if(tmp[i][x]==6) break;
		tmp[i][x]=1;
	}
}
void left(int y,int x) {
	for(int j=x-1;j>=0;j--) {
		if(tmp[y][j]==6) break;
		tmp[y][j]=1;
	}
}
void up(int y,int x) {
	for(int i=y-1;i>=0;i--) {
		if(tmp[i][x]==6) break;
		tmp[i][x]=1;
	}
}
void go(int idx,int type) {
	int y=cctv[idx].first.first,x=cctv[idx].first.second,num=cctv[idx].second;
	if(num==1) {
		if(type==0) right(y,x);
		else if(type==1) down(y,x);
		else if(type==2) left(y,x);
		else up(y,x);
	} else if(num==2) {
		if(type==0||type==2) {
			right(y,x);left(y,x);
		} else {
			up(y,x);down(y,x);
		}
	} else if(num==3) {
		if(type==0) {
			up(y,x);right(y,x);
		} else if(type==1) {
			right(y,x);down(y,x);
		} else if(type==2) {
			left(y,x);down(y,x);
		} else {
			left(y,x);up(y,x);
		}
	} else if(num==4) {
		if(type==0) {
			up(y,x);right(y,x);left(y,x);
		} else if(type==1) {
			up(y,x);right(y,x);down(y,x);
		} else if(type==2) {
			left(y,x);right(y,x);down(y,x);
		} else {
			left(y,x);up(y,x);down(y,x);
		}
	} else {
		up(y,x);right(y,x);down(y,x);left(y,x);
	}
}
void permu(vector<int>& v) {
	if((int)v.size()==(int)cctv.size()) {
		memcpy(tmp,arr,sizeof(arr));
		for(int i=0;i<(int)v.size();i++) go(i,v[i]);
		int cnt=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) if(!tmp[i][j]) cnt++;
		}
		ret=min(ret,cnt);
		return;
	}
	for(int i=0;i<4;i++) {
		v.push_back(i);
		permu(v);
		v.pop_back();
	}
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			scanf("%d",&arr[i][j]);
			if(arr[i][j]>=1&&arr[i][j]<=5) {
				cctv.push_back({{i,j},arr[i][j]});
				arr[i][j]=1;
			}
		}
	}
	permu(v);
	printf("%d\n",ret);
	return 0;
}