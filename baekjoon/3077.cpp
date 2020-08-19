// 임진왜란
#include<bits/stdc++.h>
using namespace std;
int n,cnt,ret;
map<string,int> mp;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        mp[s]=i;
    }
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        v.push_back(mp[s]);
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            cnt++;
            if(v[i]<v[j]) ret++;
        }
    }
    cout<<ret<<"/"<<cnt<<'\n';
    return 0;
}