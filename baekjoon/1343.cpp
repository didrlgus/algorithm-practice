// 폴리오미노
#include<bits/stdc++.h>
using namespace std;
int n;
string s,ret;
bool check(int idx,int type) {
	for(int i=idx;i<idx+type;i++) if(s[i]!='X') return false;
	return true;
}
void go(int here) {
	if(here>=n) {
		cout<<ret<<'\n';
		exit(0);
		return;
	}
	if(s[here]=='.') {
		ret+='.';
		go(here+1);
	} else {
		if(check(here,4)) {
			ret+="AAAA";
			go(here+4);
		} else if(check(here,2)) {
			ret+="BB";
			go(here+2);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	n=(int)s.size();
	go(0);
	printf("-1\n");
	return 0;
}