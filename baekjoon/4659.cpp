// 비밀번호 발음하기
#include<bits/stdc++.h>

using namespace std;

// 1. 모음 하나를 반드시 포함
bool check1(string s) {
    for(int i=0;i<s.size();i++) {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
            return true;
        }
    }
    return false;
}

// 2. 모음 혹은 자음이 3개연속 불가
bool check2(string s) {
    if(s.size()<3) return true;
    bool flag1=false,flag2=false;
    for(int i=0;i<=s.size()-3;i++) {
        if((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') 
                && (s[i+1]=='a' || s[i+1]=='e' || s[i+1]=='i' || s[i+1]=='o' || s[i+1]=='u')
                && (s[i+2]=='a' || s[i+2]=='e' || s[i+2]=='i' || s[i+2]=='o' || s[i+2]=='u')) {
            flag1=true;
        }

        if((s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u') 
                && (s[i+1]!='a' && s[i+1]!='e' && s[i+1]!='i' && s[i+1]!='o' && s[i+1]!='u')
                && (s[i+2]!='a' && s[i+2]!='e' && s[i+2]!='i' && s[i+2]!='o' && s[i+2]!='u')) {
            flag2=true;
        }
        if(flag1 || flag2) return false;
    }
    return true;
}

// 3. 같은 문자 연속 x (e,o 제외)
bool check3(string s) {
    if(s.size()<2) return true;
    for(int i=0;i<s.size()-1;i++) {
        char c1=s[i],c2=s[i+1];

        if(c1==c2) {
            if(c1=='e' || c1=='o') continue;
            else return false;
        }
    }
    return true;
}

int main() {

    while(true) {
        string s;
        cin>>s;

        if(s=="end") break;

        string ns="";
        if(check1(s) && check2(s) && check3(s)) {
            ns+="<"+s+">"+" is acceptable.";
        } else {
            ns+="<"+s+">"+" is not acceptable.";
        }

        cout<<ns<<endl;
    }

    return 0;
}