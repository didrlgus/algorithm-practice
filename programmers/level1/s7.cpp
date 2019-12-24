// 가운데 글자 가져오기
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int size=s.size();
    int m = size/2;
    
    if(size%2!=0) {
        answer=s.substr(m, 1);
    } else {
        answer=s.substr(m-1, 2);
    }
    
    return answer;
}

int main() {

    string s = solution("abcde");

    puts(s.c_str());

    return 0;
}