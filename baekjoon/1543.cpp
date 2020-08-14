// 문서 검색
#include<bits/stdc++.h>
using namespace std;
int idx,ret;
string s1,s2;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<(int)s1.size();i++) {
        idx=i;
        if(idx+(int)s2.size()>(int)s1.size()) break;
        int cnt=0;
        for(int j=0;j<(int)s2.size();j++) {
            if(s1[idx++]==s2[j]) cnt++;
        }
        if(cnt==(int)s2.size()) {
            ret++;
            i+=(cnt-1);
        }
    }
    cout<<ret<<'\n';
    return 0;
}