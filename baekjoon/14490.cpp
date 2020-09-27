// 백대열
#include<bits/stdc++.h>
using namespace std;
string s,str1="",str2="";
int gcd(int a,int b) {
    while(1) {
        int atmp=a;
        int btmp=b;
        a=b;
        b=atmp%btmp;
        if(b==0) break;
    }
    return a;
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>s;
    for(auto c:s) {
        if(c==':') break;
        str1+=c;
    }
    for(int i=str1.size()+1;i<s.size();i++) str2+=s[i];
    int a=stoi(str1.c_str()),b=stoi(str2.c_str());
    int mod=gcd(a,b);
    cout<<a/mod<<":"<<b/mod<<'\n';
    return 0;
}