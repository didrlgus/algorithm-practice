// 멀티태스킹(카카오 먹방 문제 변형)
#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v;
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int val;scanf("%d",&val);
		v.push_back(val);
	}
	scanf("%d",&k);
	int idx=0;
	for(int i=1;i<=k;i++) {
		if(idx==n) {
			idx=0;
			i--;
			continue;
		}
		if(v[idx]>0) v[idx]--;
		else i--;
		idx++;
	}
	bool flag=false;
	for(auto it:v) {
		if(it>0) flag=true;
	}
	if(!flag) {
		printf("-1\n");
		return 0;
	}
	while(true) {
		if(idx==n) {
			idx=0;
			continue;
		}
		if(v[idx]>0) break;
		idx++;
	}
	printf("%d\n",idx+1);
	return 0;
}