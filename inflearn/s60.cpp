// 합이 같은 부분집합
#include<bits/stdc++.h>
using namespace std;
int n,sum;
vector<int> v,vv;
bool flag=false;
void func(int here,int size) {
	if(flag) return;
	if((int)vv.size()==size) {
		int seg_sum=0;
		for(auto it:vv) seg_sum+=v[it];
		if(seg_sum*2==sum) flag=true;
		return;
	}
	for(int i=here+1;i<n;i++) {
		vv.push_back(i);
		func(i,size);
		vv.pop_back();
	}
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int val;scanf("%d",&val);
		v.push_back(val);
		sum+=val;
	}
	for(int i=1;i<=n/2;i++) {
		vv.clear();
		func(-1,i);
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}