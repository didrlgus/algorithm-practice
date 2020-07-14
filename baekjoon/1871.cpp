// 좋은 자동차 번호판
#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        string s1=s.substr(0,3);
        string s2=s.substr(4);
        int a=(s1[0]-'A')*pow(26,2)+(s1[1]-'A')*pow(26,1)+(s1[2]-'A');
        int b=atoi(s2.c_str());
        if(abs(a-b)<=100) cout<<"nice"<<'\n';
        else cout<<"not nice"<<'\n';
    }
    return 0;
}