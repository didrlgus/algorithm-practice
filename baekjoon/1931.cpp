// 회의실 배정
#include<bits/stdc++.h>
using namespace std;
int n,e,ret;
vector<pair<int,int>> v;
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back({b,a});
	}
	sort(v.begin(),v.end());
	for(auto it:v) {
		if(e<=it.second) {
			e=it.first;
			ret++;
		}
	}
	printf("%d\n",ret);
	return 0;
}