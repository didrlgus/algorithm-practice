// 2 X n 타일링
#include <string>
#include <vector>

using namespace std;

int a[60010];

int solution(int n) {
    int answer = 0;

    a[1]=1;
    a[2]=2;

    for(int i=3;i<=n;i++) {
        a[i]=(a[i-1]+a[i-2])%1000000007;
    }

    answer=a[n];

    return answer;
}

int main() {

    int n=4;
    int result=solution(n);
    printf("%d\n",result);

    return 0;
}