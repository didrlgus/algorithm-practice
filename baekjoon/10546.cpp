// 배부른 마라토너
#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> mp;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        mp[s]++;
    }
    for(int i=0;i<n-1;i++) {
        string s;cin>>s;
        mp[s]--;
        if(mp[s]==0) mp.erase(s);
    }
    for(auto it:mp) cout<<it.first<<'\n';
    return 0;
}