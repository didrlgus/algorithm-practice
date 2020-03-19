// 문자열 내림차순으로 배치하기
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = s;

    sort(answer.rbegin(), answer.rend());

    return answer;
}

int main() {

    string s = "Zbcdefg";

    string result = solution(s);

    cout << result << endl;

    return 0;
}

