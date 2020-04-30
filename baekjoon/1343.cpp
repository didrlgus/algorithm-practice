// 폴리오미노
#include<bits/stdc++.h>

using namespace std;

string s;
int main() {

    cin>>s;

    if(s.size()<2) {
        if(s==".") cout<<s<<endl;
        else cout<<-1<<endl;
        return 0;
    } else if(s.size()<4) {   // size 2 or 3
        if(s==".." || s=="...") {
            cout<<s<<endl;
            return 0;
        }
        if(s.size()==3 && s[0]=='X' && s[1]=='X' && s[2]=='X') {
            cout<<-1<<endl;
            return 0;
        }
        bool flag=false;
        for(int i=0;i<=s.size()-2;i++) {
            if(s[i]=='X' && s[i+1]=='X') {
                s[i]='B';
                s[i+1]='B';
                flag=true;
            }
        }
        if(!flag) cout<<-1<<endl;
        else cout<<s<<endl;;
        return 0;
    }

    // AAAA 채우기
    for(int i=0;i<=s.size()-4;i++) {
        if(s[i]=='X' && s[i+1]=='X' && s[i+2]=='X' && s[i+3]=='X') {
            if((i>0 && s[i-1]!='X') || i==0) {
                s[i]='A'; s[i+1]='A'; s[i+2]='A'; s[i+3]='A';
                i+=3;
            }
        }
    }

    // BB 채우기
    for(int i=0;i<=s.size()-2;i++) {
        if(s[i]=='X' && s[i+1]=='X') {
            if((i>0 && s[i-1]!='X') || i==0) {
                s[i]='B'; s[i+1]='B';
                i+=1;
            }
        }
    }

    for(int i=0;i<s.size();i++) {
        if(s[i]=='X') {
            cout<<-1<<endl;
            return 0;
        }
    }

    cout<<s<<endl;

    return 0;
}