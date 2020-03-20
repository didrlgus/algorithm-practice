// 서울에서 김서방 찾기
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    int r = 0;

    for(int i=0;i<seoul.size();i++) {
        if(seoul[i]=="Kim") r=i;
    }

    string s = to_string(r);

    answer = "김서방은 " + s + "에 있다";

    return answer;
}

int main() {

    vector<string> v = {"Jane", "Kim"};

    string result = solution(v);

    cout << result << endl;

    return 0;
}