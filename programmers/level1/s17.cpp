// 수박수박수박수박수박수?
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";

    for(int i=1;i<=n;i++) {
        if(i%2!=0) answer.append("수");
        else answer.append("박");
    }

    return answer;
}

int main() {
    string result = solution(3);

    cout << result << endl;

    return 0;
}