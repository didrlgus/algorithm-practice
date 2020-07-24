// 나는야 포켓몬 마스터 이다솜
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<string> v;
unordered_map<string,int> mp;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		string s;cin>>s;
		v.push_back(s);
		mp[s]=i;
	}
	while(m--) {
		string s;cin>>s;
		int a=atoi(s.c_str());
		if(a) cout<<v[a-1]<<'\n';
		else cout<<mp[s]<<'\n';
	}
	return 0;
}