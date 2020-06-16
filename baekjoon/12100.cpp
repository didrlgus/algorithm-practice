// 2048 (Easy)
#include<bits/stdc++.h>
using namespace std;
const int INF=-987654321;
int n,arr[25][25],tmp[25][25],ret=INF;
vector<int> v;
void go(int type) {
	queue<int> q;
	if(type==0) {
		for(int j=0;j<n;j++) {
			for(int i=0;i<n;i++) {
				if(tmp[i][j]!=0) {
					q.push(tmp[i][j]);
					tmp[i][j]=0;
				}
			}
			int idx=0;
			while(!q.empty()) {
				int f=q.front();q.pop();
				if(tmp[idx][j]==0) {
					tmp[idx][j]=f;
					ret=max(ret,f);
				} else if(tmp[idx][j]==f) {
					tmp[idx++][j]=2*f;
					ret=max(ret,2*f);
				} else {
					tmp[++idx][j]=f;
					ret=max(ret,f);
				}
			}
		}
	} else if(type==1) {
		for(int j=0;j<n;j++) {
			for(int i=n-1;i>=0;i--) {
				if(tmp[i][j]!=0) {
					q.push(tmp[i][j]);
					tmp[i][j]=0;
				}
			}
			int idx=n-1;
			while(!q.empty()) {
				int f=q.front();q.pop();
				if(tmp[idx][j]==0) {
					tmp[idx][j]=f;
					ret=max(ret,f);
				} else if(tmp[idx][j]==f) {
					tmp[idx--][j]=2*f;
					ret=max(ret,2*f);
				} else {
					tmp[--idx][j]=f;
					ret=max(ret,f);
				}
			}
		}
	} else if(type==2) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(tmp[i][j]!=0) {
					q.push(tmp[i][j]);
					tmp[i][j]=0;
				}
			}
			int idx=0;
			while(!q.empty()) {
				int f=q.front();q.pop();
				if(tmp[i][idx]==0) {
					tmp[i][idx]=f;
					ret=max(ret,f);
				} else if(tmp[i][idx]==f) {
					tmp[i][idx++]=2*f;
					ret=max(ret,2*f);
				} else {
					tmp[i][++idx]=f;
					ret=max(ret,f);
				}
			}
		}
	} else {
		for(int i=0;i<n;i++) {
			for(int j=n-1;j>=0;j--) {
				if(tmp[i][j]!=0) {
					q.push(tmp[i][j]);
					tmp[i][j]=0;
				}
			}
			int idx=n-1;
			while(!q.empty()) {
				int f=q.front();q.pop();
				if(tmp[i][idx]==0) {
					tmp[i][idx]=f;
					ret=max(ret,f);
				} else if(tmp[i][idx]==f) {
					tmp[i][idx--]=2*f;
					ret=max(ret,2*f);
				} else {
					tmp[i][--idx]=f;
					ret=max(ret,f);
				}
			}
		}
	}
}
void permu(vector<int>& v) {
	if((int)v.size()==5) {
		memcpy(tmp,arr,sizeof(arr));
		for(auto iter:v) go(iter);
		return;
	}
	for(int i=0;i<4;i++) {
		v.push_back(i);
		permu(v);
		v.pop_back();
	}
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
	}
	permu(v);
	printf("%d\n",ret);
	return 0;
}