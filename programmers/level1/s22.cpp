// 자릿수 더하기
#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0;

    while(n>0) {
        answer+=n%10;
        n/=10;
    }

    return answer;
}

int main() {

    int result = solution(123);

    cout << result << endl;

    return 0;
}