// 교수가 된 현우
#include<bits/stdc++.h>

using namespace std;

int n;
int main() {

    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);

        int cnt2=0,cnt5=0;
        for(int j=2;j<=a;j*=2) {       // 2,2^2,2^3... 으로 나눈 몫의 총합 구하기
            cnt2+=(a/j);
        }

        for(int j=5;j<=a;j*=5) {
            cnt5+=(a/j);
        }

        printf("%d\n",min(cnt2,cnt5));
    }

    return 0;
}