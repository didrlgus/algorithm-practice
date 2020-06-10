// 피자판매
#include<bits/stdc++.h>
using namespace std;
int k,n,m,a[1005],b[1005],pa[2005],pb[2005],ret;
vector<int> v1,v2;
int main() {
	scanf("%d %d %d",&k,&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);

	for(int i=1;i<=n;i++) pa[i]=pa[i-1]+a[i];
	for(int i=n+1;i<=2*n;i++) pa[i]=pa[n]+pa[i-n];
	for(int i=1;i<=m;i++) pb[i]=pb[i-1]+b[i];
	for(int i=m+1;i<=2*m;i++) pb[i]=pb[m]+pb[i-m];

	for(int i=n;i<=2*n-1;i++) {
		for(int j=1;j<=n-1;j++) v1.push_back(pa[i]-pa[i-j]);
	}
	for(int i=m;i<=2*m-1;i++) {
		for(int j=1;j<=m-1;j++) v2.push_back(pb[i]-pb[i-j]);
	}

	v1.push_back(0);
	v1.push_back(pa[n]);
	v2.push_back(0);
	v2.push_back(pb[m]);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int i=0;i<=k;i++) {
		int cnt1=upper_bound(v1.begin(),v1.end(),i) - lower_bound(v1.begin(),v1.end(),i);
		int cnt2=upper_bound(v2.begin(),v2.end(),k-i) - lower_bound(v2.begin(),v2.end(),k-i);
		ret+=cnt1*cnt2;
	}
	printf("%d\n",ret);
	return 0;
}