// 문자열
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,ret=INF;
string s1,s2;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>s1>>s2;
    n=(int)s1.size(),m=(int)s2.size();
    for(int i=0;i<=m-n;i++) {
        int cnt=0;
        for(int j=0;j<n;j++) {
            if(s1[j]!=s2[j+i]) cnt++;
        }
        ret=min(ret,cnt);
    }
    cout<<ret<<'\n';
    return 0;
}