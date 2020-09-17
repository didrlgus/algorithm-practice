// 복면산?!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> v;
vector<char> vv;
int arr[100];
bool check[15],flag;
void func(int len) {
    if(flag) return;
    if(len>=(int)vv.size()) {
        vector<ll> ret;
        for(int i=0;i<3;i++) {
            ll sum=0;
            for(auto it:v[i]) {
                sum*=10;
                sum+=arr[it-'A'];        
            }
            ret.push_back(sum);
        }
        if(ret[0]+ret[1]==ret[2]) flag=true;
        return;
    }
    for(int i=0;i<=9;i++) {
        if(check[i]) continue;
        arr[vv[len]-'A']=i;
        check[i]=true;
        func(len+1);
        arr[vv[len]-'A']=0;
        check[i]=false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    for(int i=0;i<3;i++) {
        string s;cin>>s;
        v.push_back(s);
    }
    for(auto c:v[0]) vv.push_back(c);
    for(auto c:v[1]) vv.push_back(c);
    for(auto c:v[2]) vv.push_back(c);
    sort(vv.begin(),vv.end());
    vv.erase(unique(vv.begin(),vv.end()),vv.end());
    if((int)vv.size()>10) {
        cout<<"NO"<<'\n';
        return 0;
    }
    func(0);
    if(flag) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
    return 0;
}