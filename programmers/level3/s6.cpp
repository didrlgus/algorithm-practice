// 타일 장식물
#include <string>
#include <vector>

using namespace std;

long long a[90];

long long solution(int N) {
    long long answer = 0;

    a[1]=1;
    a[2]=1;

    if(N==1) return 4;
    if(N==2) return 6;

    for(int i=3;i<=N;i++) a[i]=a[i-1]+a[i-2];
    
    answer=a[N]*2+(a[N-1]+a[N])*2;

    return answer;
}

int main() {

    int N=5;
    long long result=solution(N);
    printf("%lld\n",result);

    return 0;
}