// 단어 뒤집기 2
#include<bits/stdc++.h>
using namespace std;
string s,ret;
void go(string& ret) {
    int idx=0;
    for(int i=0;i<(int)ret.size();i++) {
        if(ret[i]==' ') {
            reverse(ret.begin()+idx,ret.begin()+i);
            idx=i+1;
        }
    }
    reverse(ret.begin()+idx,ret.end());
}
int main() {
    getline(cin,s);
    for(auto c:s) {
        if(c=='<') {
            go(ret);
            cout<<ret;
            ret="";
        }
        ret+=c;
        if(c=='>') {
            cout<<ret;
            ret="";
        }
    }
    go(ret);
    cout<<ret<<'\n';
    return 0;

}