// JadenCase 문자열 만들기
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    bool flag=false;
    for(int i=0;i<s.size();i++) {
        if(!flag) {
            s[i]=toupper(s[i]);
            flag=true;
        } else if(s[i]>='A' && s[i]<='Z') {
            s[i]=tolower(s[i]);
        }

        if(s[i]==' ') {
            flag=false;
        }
    }
    return s;
}

int main() {

    string s="aa bB Cc Dd    eE 5abcdE";
    string result=solution(s);

    cout<<result<<endl;

    return 0;
}