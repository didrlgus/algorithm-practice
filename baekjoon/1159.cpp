// 농구 경기
#include<bits/stdc++.h>
using namespace std;
int n,cnt[150];
vector<string> v;
vector<char> ret;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        v.push_back(s);
    }
    for(auto s:v) {
        char c=s[0];
        if(cnt[c]>5) continue;
        cnt[c]++;
        if(cnt[c]==5) ret.push_back(c);
    }
    if(!ret.size()) {
        cout<<"PREDAJA"<<'\n';
        return 0;
    }
    sort(ret.begin(),ret.end());
    for(auto it:ret) cout<<it;
    return 0;
}