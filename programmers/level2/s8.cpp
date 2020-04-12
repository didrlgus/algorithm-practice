// 쇠막대기
#include <string>
#include <vector>
#include <stack>

using namespace std;

// '(' 입력 시 스택에 추가
// ')' 입력 시 이전 값이 '(' 이면 레이저, ')'이면 막대기의 끝
// -> '('이면 pop 수행 후 + 스택의 크기
// -> ')'이면 pop 수행 후 +1

int solution(string arrangement) {
    int answer = 0;

    stack<char> s;
    s.push('(');

    for(int i=1;i<arrangement.size();i++) {
        if(arrangement.at(i)=='(') {
            s.push('(');
        } else {
            if(arrangement.at(i-1)=='(') {  // 레이저
                s.pop();
                answer+=s.size();
            } else {                        // 막대의 끝
                s.pop();
                answer+=1;
            }
        }
    }

    return answer;
}

int main() {
    string s="()(((()())(())()))(())";

    int result=solution(s);
    printf("%d\n",result);

    return 0;
}