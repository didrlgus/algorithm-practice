// 정수 제곱근 판별
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    long long a = sqrt(n);

    if (a*a != n) answer = -1;
    else answer = pow(a+1, 2);

    return answer;
}

int main() {

    long long result = solution(121);

    printf("%lld\n", result);

    return 0;
}