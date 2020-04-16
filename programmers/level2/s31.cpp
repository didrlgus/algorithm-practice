// 피보나치 수
#include <string>
#include <vector>

using namespace std;

int a[100010];

int solution(int n) {
    int answer = 0;
    
    a[0]=0;
    a[1]=1;
    
    for(int i=2;i<=100000;i++) a[i]=(a[i-2]+a[i-1])%1234567;
    
    answer=a[n];

    return answer;
}

int main() {

    int result=solution(100000);
    printf("%d\n",result);

    return 0;
}