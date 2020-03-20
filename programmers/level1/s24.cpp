// 정수 내림차순으로 배치하기
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;

    while(n>0) {
        v.push_back(n%10);
        n/=10;
    }

    sort(v.begin(), v.end());

    for(int i=0;i<v.size();i++) {
        answer += v[i]*pow(10,i);
    }

    return answer;
}

int main() {

    long long result = solution(118372);

    printf("%lld", result);

    return 0;
}