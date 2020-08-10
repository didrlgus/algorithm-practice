// 듣보잡
#include<bits/stdc++.h>
using namespace std;
int n,m,ret;
unordered_map<string,bool> mp;
vector<string> v;
int main() {
 	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        mp[s]=true;
    }
    for(int i=0;i<m;i++) {
        string s;cin>>s;
        if(mp[s]) {
            ret++;
            v.push_back(s);
        }
    }
    sort(v.begin(),v.end());
    cout<<ret<<'\n';
    for(auto it:v) cout<<it<<'\n';
    return 0;
}