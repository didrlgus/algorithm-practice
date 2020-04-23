// 예상 대진표
#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int answer=1;
    
    if(a>b) {
        int tmp=a;
        a=b;
        b=tmp;
    }

    if(a%2==1 && b%2==0 && abs(a-b)==1) return answer;

    while(true) {
        answer++;

        if(a%2==1) {
            a=a/2+1;
        } else a/=2;

        if(b%2==1) {
            b=b/2+1;
        } else b/=2;

        if(a%2==1 && b%2==0 && abs(a-b)==1) break;
    }

    return answer;
}

int main() {
    int n=8,a=4,b=7;

    int result=solution(n,a,b);
    printf("%d\n",result);

    return 0;
}

