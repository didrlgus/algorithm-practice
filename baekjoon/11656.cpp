// 접미사 배열
#include<bits/stdc++.h>
using namespace std;
string s;
vector<string> v;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>s;
    for(int i=0;i<(int)s.size();i++) v.push_back(s.substr(i));
    sort(v.begin(),v.end());
    for(auto str:v) cout<<str<<'\n';
    return 0;
}