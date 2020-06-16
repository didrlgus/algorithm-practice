// 미네크래프트
#include<bits/stdc++.h>
using namespace std;
const int INF=-987654321;
int n,t,p,sum,ret=INF;
priority_queue<int> pq;
int main() {
	scanf("%d %d %d",&n,&t,&p);
	for(int i=0;i<n;i++) {
		if(i*p>t) break;
		int a;
		scanf("%d",&a);
		sum+=a;
		pq.push(a);
		while(sum+i*p>t) {
			sum-=pq.top();
			pq.pop();
		}
		ret=max(ret,(int)pq.size());
	}
	printf("%d\n",ret);
	return 0;
}