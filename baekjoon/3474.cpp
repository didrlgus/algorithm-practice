// 교수가 된 현우
#include<bits/stdc++.h>
using namespace std;
int tc,n;
int main() {
	scanf("%d",&tc);
	while(tc--) {
		scanf("%d",&n);
		int a=2,b=5,cnt2=0,cnt5=0;
		while(a<=n) {
			cnt2+=n/a;
			a*=2;
		}
		while(b<=n) {
			cnt5+=n/b;
			b*=5;
		}
		printf("%d\n",min(cnt2,cnt5));
	}
	return 0;
}