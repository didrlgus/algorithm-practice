// 회의실 배정
#include<bits/stdc++.h>
using namespace std;
int n,ret;
vector<pair<int,int>> v;
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int s,e;		
		scanf("%d %d",&s,&e);
		v.push_back({e,s});
	}
	sort(v.begin(),v.end());
	int e=v[0].first;
	ret++;
	for(int i=1;i<n;i++) {
		if(e>v[i].second) continue;
		e=v[i].first;
		ret++;
	}
	printf("%d\n",ret);
	return 0;
}