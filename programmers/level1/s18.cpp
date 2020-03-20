// 문자열을 정수로 바꾸기
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(string s) {
    int answer = 0;

    string s2 = "";

    if(s[0]=='-') {
        for(int i=0;i<s.size()-1;i++) s2[i]=s[i+1];
        answer = stoi(s2) * -1;
    } else {
        s2 = s;
        answer = stoi(s2);
    }

    return answer;
}

int main() {

    int result = solution("-1234");
    printf("%d\n", result);

    return 0;
}