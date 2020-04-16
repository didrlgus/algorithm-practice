// 숫자의 표현
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int solution(int n) {
    int answer = 0;

    for(int i=1;i<=n;i++) {
        int sum=i;
        if(sum==n) {
            answer++;
            break;
        }
        for(int j=i+1;j<n;j++) {
            sum+=j;

            if(sum==n) {
                answer++;
                break;
            } else if(sum>n) break;
        }
    }

    return answer;
}

int main() {
    int n=15;
    int result=solution(15);
    printf("%d\n",result);
}