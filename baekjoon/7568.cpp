// 덩치
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int a,b;scanf("%d%d",&a,&b);
		v.push_back({a,b});
	}
	for(int i=0;i<n;i++) {
		int cnt=0;
		for(int j=0;j<n;j++) {
			if(i==j) continue;
			if(v[i].first<v[j].first&&v[i].second<v[j].second) cnt++;
		}
		printf("%d ",cnt+1);
	}
	return 0;
}