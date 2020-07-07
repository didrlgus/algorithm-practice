// 보석 상자
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[300005],s=1,e,ret;
bool check(int mid) {
	int cnt=0;
	for(int i=0;i<m;i++) {
		cnt+=arr[i]/mid;
		if(arr[i]%mid!=0) cnt++;
	}
	if(cnt==n) return true;
	else if(cnt>n) return false;
	else return true;
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++) {
		scanf("%d",&arr[i]);
		e=max(e,arr[i]);
	}
	while(s<=e) {
		int mid=(s+e)/2;
		if(check(mid)) {
			e=mid-1;
			ret=mid;
		} else s=mid+1;
	}
	printf("%d\n",ret);
	return 0;
}