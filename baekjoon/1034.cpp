// 램프
#include<bits/stdc++.h>
using namespace std;
int n,m,k,ret;
vector<string> v;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        v.push_back(s);
    }
    cin>>k;
    for(int i=0;i<n;i++) {
        string cur=v[i];
        int z_cnt=0,cnt=0;
        for(int j=0;j<m;j++) if(cur[j]=='0') z_cnt++;
        if(k>=z_cnt&&k%2==z_cnt%2) cnt++;
        else continue;
        for(int j=0;j<n;j++) {
            if(j==i) continue;
            if(v[i]==v[j]) cnt++;
        }
        ret=max(ret,cnt);
    }
    cout<<ret<<'\n';
    return 0;
}