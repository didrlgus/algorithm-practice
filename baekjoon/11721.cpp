// 열 개씩 끊어 출력하기
#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
    cin>>s;
    int len=0;
    for(int i=0;i<(int)s.size();i++) {
        cout<<s[i];
        len++;
        if(len>=10) {
            len=0;
            cout<<'\n';
        }
    }
    return 0;
}