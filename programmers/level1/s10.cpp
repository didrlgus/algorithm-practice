// 두 정수 사이의 합
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if(a==b) answer=a;
    else if (a<b) {
        for(int i=a;i<=b;i++) answer+=i; 
    } else {
        for(int i=b;i<=a;i++) answer+=i;
    }
    
    return answer;
}

int main() {

    printf("%lld\n", solution(3, 5));
    
    return 0;
}