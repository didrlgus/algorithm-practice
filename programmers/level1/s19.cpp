// 시저 암호
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    vector<char> v;

    for(int i=0;i<s.size();i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            if(s[i]+n > 'Z') {
                v.push_back(s[i]+n - 26);
            } else {
                v.push_back(s[i]+n);
            }
        } else if(s[i] >= 'a' && s[i] <= 'z') {
            if(s[i]+n > 'z') {
                v.push_back(s[i]+n - 26);
            } else {
                v.push_back(s[i]+n);
            }
        } else if(s[i] == ' ') {
            v.push_back(' ');
        }
    }
    
    string answer(v.begin(), v.end());

    return answer;
}

int main() {

    string result = solution("AB", 1);

    cout << result << endl;

    return 0;
}