// 소풍
#include<bits/stdc++.h>
using namespace std;
int n,k,m,ret;
int main() {
    scanf("%d %d %d",&n,&k,&m);
    int target=k%n?k%n:n;   // 초기 타겟
    ret++;
    while(target!=m) {
        m-=target;          // m의 위치가 계속 바뀜
        if(m<0) m+=n;       // 원형이기때문에 m이 음수일 경우 n을 더함
        n--;
        target=k%n?k%n:n;   // n(전체크기)을 하나 뺀 후 다음 target 수정
        ret++;
    }
    printf("%d\n",ret);
    return 0;
}