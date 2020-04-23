// 점프와 순간 이동
#include <iostream>
using namespace std;

int solution(int n) {
    int ans = 0;
	
    while(n>0) {
        if(n%2==0) n/=2;
        else {
            n--;
            ans++;
            n/=2;
        }
    }

    return ans;
}

int main() {

    int n=5000;
    int result=solution(n);
    printf("%d\n",result);

    return 0;
}