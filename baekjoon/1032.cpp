// 명령 프롬프트
#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
string ret;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        v.push_back(s);
    }
    int size=(int)v[0].size();
    string s1=v[0];
    for(int j=0;j<size;j++) {
        char c=s1[j];
        bool flag=false;
        for(int i=1;i<n;i++) {
            if(c!=v[i][j]) flag=true;
        }
        if(flag) ret+='?';
        else ret+=c;
    }
    cout<<ret<<'\n';
    return 0;
}