// 팰린드롬 만들기
#include<bits/stdc++.h>
using namespace std;
string s,ret;
int cnt[100];
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	for(auto c:s) cnt[c]++;
	bool flag=false;
	for(int i='Z';i>='A';i--) {
		if(cnt[i]&1) {
			if(flag) {
				cout<<"I'm Sorry Hansoo"<<'\n';
				return 0;
			}
			cnt[i]--;
			ret.insert(ret.begin()+(int)ret.size()/2,char(i));
			flag=true;
		}
		for(int j=0;j<cnt[i];j+=2) {
			ret=char(i)+ret;
			ret+=char(i);
		}	
	}
	cout<<ret<<'\n';
	return 0;
}