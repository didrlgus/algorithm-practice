// IOIOI
#include<bits/stdc++.h>
using namespace std;
int n,m,ret;
string s;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>s;
    for(int i=0;i<m;i++) {
        if(s[i]=='O') continue;
        int o_cnt=0;
        while(s[i+1]=='O'&&s[i+2]=='I') {
            o_cnt++;
            i+=2;
            if(o_cnt==n) {
                o_cnt--;
                ret++;
            }
        }
    }
    cout<<ret<<'\n';
    return 0;
}