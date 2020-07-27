// ROT13
#include<bits/stdc++.h>
using namespace std;
string s,ret;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	getline(cin,s);
	for(auto c:s) {
		if(c>='a'&&c<='z') {
			if(c+13<='z') ret+=(c+13);
			else ret+=(c+13-'z'+'a'-1);
		} else if(c>='A'&&c<='Z') {
			if(c+13<='Z') ret+=(c+13);
			else ret+=(c+13-'Z'+'A'-1);
		} else ret+=c;
	}
	cout<<ret<<'\n';
}