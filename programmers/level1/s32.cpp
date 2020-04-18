// 콜라츠 추측
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long a=num;

    int cnt=0;

    while(a!=1) {
        if(a%2==0) {
            a/=2;
        } else {
            a=(a*3)+1;
        }
        cnt++;

        if(cnt>=500) break;
    }

    if(cnt<500) answer=cnt;
    else answer=-1;

    return answer;
}

int main() {

    int result=solution(626331);
    printf("%d\n",result);
    return 0;
}