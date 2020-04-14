// 괄호 변환
#include <string>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool isValid(string p) {
    int cnt=0;

    for(int i=0;i<p.length();i++) {
        if(p.at(i)=='(') cnt++;
        else cnt--;

        if(cnt<0) return false;
    }
    return true;
}

string solution(string p) {
    string answer = "";

    if(isValid(p)) return p;

    int left=0,right=0;
    string u="",v="";

    for(int i=0;i<p.length();i++) {
        if(p.at(i)=='(') left++;
        else right++;

        if(left==right) {
            u=p.substr(0,i+1);
            v=p.substr(i+1);
            break;
        }
    }

    if(isValid(u)) {    // u가 올바른 문자열일 경우
        answer+=u;
        answer+=solution(v);
    } else {            // u가 올바르지 않은 문자열일 경우
        answer+="(";
        answer+=solution(v);
        answer+=")";

        string tmp=u.substr(1,u.length()-2);

        for(int i=0;i<tmp.length();i++) {
            if(tmp.at(i)=='(') answer+=")";
            else answer+="(";
        }
    }

    return answer;
}

int main() {

    string p="()))((()";
    string result=solution(p);

    cout<<result<<endl;

    return 0;
}