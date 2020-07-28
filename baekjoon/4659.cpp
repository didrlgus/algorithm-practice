// 비밀번호 발음하기
#include<bits/stdc++.h>
using namespace std;
string s;
bool is_vowel(char c) {
    return c=='a'||c=='i'||c=='o'||c=='u'||c=='e';
}
bool check(string str) {
    bool flag=false;
    for(auto c:str) {
        if(is_vowel(c)) {
            flag=true;
            break;
        }
    }
    if(!flag) return false;
    for(int i=0;i<=(int)str.size()-3;i++) {
        if(is_vowel(str[i])&&is_vowel(str[i+1])&&is_vowel(str[i+2])) return false;
        if(!is_vowel(str[i])&&!is_vowel(str[i+1])&&!is_vowel(str[i+2])) return false;
    }
    for(int i=0;i<=(int)str.size()-2;i++) {
        if(str[i]==str[i+1]&&str[i]!='e'&&str[i]!='o') return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    while(true) {
        cin>>s;
        if(s=="end") break;
        cout<<"<"+s+"> is ";
        if(check(s)) cout<<"acceptable."<<'\n';
        else cout<<"not acceptable."<<'\n';
    }
    return 0;
}