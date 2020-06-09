// 캠핑
#include<bits/stdc++.h>
using namespace std;
int l,p,v;
int main() {
	int idx=1;
	while(true) {
		scanf("%d %d %d",&l,&p,&v);
		if(l==0&&p==0&&v==0) break;
		int ret=v/p*l+min(l,v%p);
		printf("Case %d: %d\n",idx++,ret);
	}
	return 0;
}