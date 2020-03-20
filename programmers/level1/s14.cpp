#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = false;
    int cnt=0;

    if(s.size() != 4 && s.size() != 6) return false;

    for(int i=0;i<s.size();i++) {
        if(s[i] >= '0' && s[i] <= '9') cnt++;
    }

    if(cnt==s.size()) answer = true;

    return answer;
}

int main() {

    string s = "01234567890";

    bool result = solution(s);

    cout << result << endl;

    return 0;
}