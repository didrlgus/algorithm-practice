// 자연수 뒤집어 배열로 만들기
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;

    while(n>0) {
        answer.push_back(n%10);
        n/=10;
    }

    return answer;
}

int main() {

    vector<int> answer = solution(12345);

    for(int i=0;i<answer.size();i++) printf("%d ", answer[i]);

    return 0;
}