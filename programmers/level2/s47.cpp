// 짝 지어 제거하기
#include <iostream>
#include<string>
#include<stack>

using namespace std;

stack<char> st;

int solution(string s) {
    int answer = 0;

    for(int i=0;i<s.size();i++) {
        char c=s.at(i);

        if(!st.empty()) {
            char top=st.top();
            if(top==c) st.pop();
            else st.push(c);
        } else st.push(c);
    }

    if(st.empty()) answer=1;

    return answer;
}

int main() {

    string s="baabaa";
    int result=solution(s);
    printf("%d\n",result);

    return 0;
}