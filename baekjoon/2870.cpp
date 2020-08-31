// 수학숙제
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<string> v;
bool cmp(string s1,string s2) {
    if(s1.size()==s2.size()) return s1<s2;
    return s1.size()<s2.size();
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        int idx=0;
        string str="";
        while(idx<(int)s.size()) {
            if(s[idx]>='0'&&s[idx]<='9') {
                str+=s[idx];
                if(str.size()>1&&str[0]=='0') str.erase(str.begin());
            }
            else {
                if((int)str.size()>0) v.push_back(str);
                str="";
            }
            idx++;
        }
        if((int)str.size()>0) v.push_back(str);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto it:v) cout<<it<<'\n';
    return 0;
}