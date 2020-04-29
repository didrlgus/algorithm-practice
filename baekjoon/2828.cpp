// 사과 담기 게임
#include<bits/stdc++.h>

using namespace std;

int n,m,k;
int main() {

    scanf("%d %d",&n,&m);
    scanf("%d",&k);

    int s=0,e=m;
    int cnt=0;
    for(int i=0;i<k;i++) {
        int a;
        scanf("%d",&a);

        if(a<=s) {          // 왼쪽으로 이동
            int d=s-a+1;
            s-=d;
            e-=d;
            cnt+=d;
        } else if(a>e) {    // 오른쪽으로 이동
            int d=a-e;
            s+=d;
            e+=d;
            cnt+=d;
        }
    }

    printf("%d\n",cnt);

    return 0;
}