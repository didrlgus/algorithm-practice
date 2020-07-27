// 폴리오미노
#include<bits/stdc++.h>
using namespace std;
int n;
string s,str;
bool check(int idx,int type) {
	for(int i=idx;i<idx+type;i++) {
		if(s[i]!='X') return false;
	}
	return true;
}
void go(int here) {
	if(here>=n) {
		cout<<str<<'\n';
		exit(0);
		return;
	}
	string tmp=str;
	if(s[here]=='.') {
		str+='.';
		go(here+1);
		str=tmp;
	} else {
		if(check(here,4)) {
			str+="AAAA";
			go(here+4);
			str=tmp;
		} else if(check(here,2)) {
			str+="BB";
			go(here+2);
			str=tmp;
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