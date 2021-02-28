// 공주 구하기
#include<bits/stdc++.h>
using namespace std;
int n,m;
queue<int> q,tmp_q,empty_q;
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) q.push(i);
	int idx=0;
	while(true) {
		if(q.empty()) {
			if((int)tmp_q.size()>1) {
				q=tmp_q;
				tmp_q=empty_q;
			} else break;
		} else {
			int f=(int)q.front();q.pop();
			idx++;
			if(idx==m) {
				idx=0;
				continue;
			}
			tmp_q.push(f);
		}
	}
	printf("%d\n",(int)tmp_q.front());
	return 0;
}