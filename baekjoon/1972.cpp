// 놀라운 문자열
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    while(true) {
        string s;cin>>s;
        if(s=="*") break;
        int n=(int)s.size();
        bool flag=false;
        for(int t=0;t<=n-2;t++) {
            set<string> st;
            int cnt=0;
            for(int i=0;i<n-t-1;i++) {
                st.insert(to_string(s[i])+s[i+t+1]);
                cnt++;
            }
            if((int)st.size()!=cnt) {
                flag=true;
                break;
            }
        }
        if(!flag) cout<<s<<" is surprising."<<'\n';
        else cout<<s<<" is NOT surprising."<<'\n';
    }
    return 0;
}