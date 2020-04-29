// 10988. 팰린드롬인지 확인하기
#include<bits/stdc++.h>

using namespace std;

int main() {

    string s;
    cin>>s;

    bool flag=false;
    for(int i=0;i<s.size();i++) {
        if(s[i]!=s[s.size()-i-1]) {
            flag=true;
            break;
        }
    }

    if(!flag) printf("1");
    else printf("0");

    return 0;
}