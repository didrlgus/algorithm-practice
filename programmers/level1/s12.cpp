// 문자열 내 p와 y의 개수
#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pCnt = 0;
    int yCnt = 0;

    for(int i=0;i<s.size();i++) {
        if(s[i] == 'p' || s[i] == 'P') {
            pCnt++;
        } else if (s[i] == 'y' || s[i] == 'Y') {
            yCnt++;
        }
    }
    
    if (pCnt != yCnt) answer = false;

    return answer;
}

int main() {

    string s = "pPoooyY";

    int result = solution(s);

    printf("%d", result);

    return 0;
}

