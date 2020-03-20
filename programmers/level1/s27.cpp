// 짝수와 홀수
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int num) {
    string answer = "";

    if(num%2==0) answer = "Even";
    else answer = "Odd"; 

    return answer;
}

int main() {

    string result = solution(3);
    cout << result << endl;
    
    return 0;
}