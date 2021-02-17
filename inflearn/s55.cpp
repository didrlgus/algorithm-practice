// 기차운행
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
stack<int> stk;
string ret;
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int val;scanf("%d",&val);
		v.push_back(val);
	}
	int i=0,j=1;
	while(true) {
		if(i==n) break;
		stk.push(v[i]);
		ret+="P";
		while(!stk.empty()) {
			if(stk.top()==j) {
				ret+="O";
				stk.pop();
				j++;
			} else break;
		}
		i++;
	}
	if(!stk.empty()) cout<<"impossible"<<'\n';
	else cout<<ret<<'\n';
	return 0;
}