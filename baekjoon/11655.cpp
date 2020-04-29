// ROT13
#include<bits/stdc++.h>

using namespace std;

int main() {

    string s;
    getline(cin,s);

    string ns="";
    for(int i=0;i<s.size();i++) {
        if(s[i]>='A' && s[i]<='Z') {
            char c=s[i]+13;
            if(c>'Z') c='A'+(c-'Z'-1);
            ns+=c;
        } else if(s[i]>='a' && s[i]<='z') {
            if(s[i]>='s') {
                ns+='f'+(s[i]-'s');
                continue;
            }
            char c=s[i]+13;
            if(c>'z') c='a'+(c-'z'-1);
            ns+=c;
        } else ns+=s[i];
    }

    cout<<ns<<endl;

    return 0;
}