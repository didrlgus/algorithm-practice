// KMP는 왜 KMP일까?
#include<bits/stdc++.h>
using namespace std;
string ret;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;cin>>s;
    if(s[0]!='-') ret+=s[0];
    for(int i=1;i<(int)s.size()-1;i++) {
        if(s[i]=='-') ret+=s[i+1];
    }
    cout<<ret<<'\n';
    return 0;
}