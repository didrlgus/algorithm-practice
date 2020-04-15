// 다음 큰 숫자
#include <string>
#include <vector>

using namespace std;

int tobin(int num) {
    int cnt=0;
    while(num>0) {
        if(num%2==1) cnt++;
        num/=2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;

    int cnt=tobin(n);

    while(true) {
        if(cnt==tobin(++n)) {
            return n;
        }
    }
}

int main() {

    int n=78;
    int result=solution(n);
    printf("%d\n",result);

    return 0;
}