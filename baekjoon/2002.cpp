// 추월
#include<bits/stdc++.h>
using namespace std;
int n,ret;
map<string,int> mp;
vector<string> v;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        mp[s]=i;
    }
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        v.push_back(s);
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(mp[v[i]]>mp[v[j]]) {
                ret++;
                break;
            }
        }
    }
    printf("%d\n",ret);
    return 0;
}