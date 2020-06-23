// 팩토리얼의 0의 개수
#include<bits/stdc++.h>
using namespace std;
int n,cnt2,cnt5;
int main() {
    scanf("%d",&n);
    int a=2;
    while(a<=n) {
        cnt2+=n/a;
        a*=2;
    }
    int b=5;
    while(b<=n) {
        cnt5+=n/b;
        b*=5;
    } 
    printf("%d",min(cnt2,cnt5));
    return 0;
}