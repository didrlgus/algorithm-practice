// 올바른 괄호
#include<string>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;

    int cnt=0;

    for(int i=0;i<s.size();i++) {
        if(s.at(i)=='(') cnt++;
        else cnt--;

        if(cnt<0) {
            answer=false;
            return answer;
        }
    }

    if(cnt>0) answer=false;

    return answer;
}

int main() {
    string s="(())()";

    bool result=solution(s);
    cout<<result<<endl;

    return 0;
}