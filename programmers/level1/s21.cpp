// 이상한 문자 만들기
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = true;
    
    for(int i=0; i < s.size(); i++){
        if(s.at(i) == ' '){
            answer += " ";
            flag = true;
        }
        else {
            if(flag){
                flag = false;
                answer += toupper(s[i]);
            }
            else {
                flag = true;
                answer += tolower(s[i]);
            }
        }
    }
    return answer;
}

int main() {

    string result = solution("tRy hElLo wOrld");
    cout << result << endl;

    return 0;
}