// 패션왕 신해빈
#include<bits/stdc++.h>
using namespace std;
int tc,n;
map<string, int> mp;
set<string> st;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>tc;
	while(tc--) {
		mp.clear();st.clear();
		cin>>n;
		int ret=1;
		for(int i=0;i<n;i++) {
			string s1,s2;
			cin>>s1;cin>>s2;
			st.insert(s2);
			mp[s2]++;
		}
		for(auto it:st) ret*=(mp[it]+1);
		cout<<ret-1<<'\n';
	}
	return 0;
}