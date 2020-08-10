// 한국이 그리울 땐 서버에 접속하지
#include<bits/stdc++.h>
using namespace std;
int n,p_size,s_size;
string pattern,prefix,suffix;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;cin>>pattern;
    int pos=pattern.find('*');
    prefix=pattern.substr(0,pos);p_size=(int)prefix.size();
    suffix=pattern.substr(pos+1);s_size=(int)suffix.size();
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        if(p_size+s_size>(int)s.size()) {
            cout<<"NE"<<'\n';
            continue;
        }
        bool flag=false;
        for(int j=0;j<p_size;j++) {
            if(prefix[j]!=s[j]){
                flag=true;
                break;
            }
        }
        bool flag2=false;
        for(int j=0;j<s_size;j++) {
            if(suffix[j]!=s[(int)s.size()-s_size+j]) {
                flag2=true;
                break;
            }
        }
        if(flag||flag2) cout<<"NE"<<'\n';
        else cout<<"DA"<<'\n';
    }
    return 0;
}